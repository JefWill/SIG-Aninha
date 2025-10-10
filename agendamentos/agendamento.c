#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "agendamento.h"
#include "../utilitarios/utilitarios.h"
#include "../funcionarios/funcionario.h"

//////////////////////////////////////////////
///////////// MODULO AGENDAMENTO /////////////
//////////////////////////////////////////////

int tela_menu_agendamento(void)
{
    int op_agendamento;
    system("clear||cls");
    header();
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|               ✦✧✦✧✦  SIG-Aninha - Módulo Agendamento  ✦✧✦✧✦            |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Agendar Consulta                               |\n");
    printf("|                      2. Atualizar Agendamento                          |\n");
    printf("|                      3. Listar Agendamentos (do dia)                   |\n");
    printf("|                      4. Buscar Agendamento por Cliente                 |\n");
    printf("|                      5. Cancelar Agendamento                           |\n");
    printf("|                      0. Retornar ao Menu Principal                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_agendamento = escolha();

    return op_agendamento;
}

void modulo_agendamentos(void)
{
    int op_agendamento;
    do
    {
        op_agendamento = tela_menu_agendamento();

        switch (op_agendamento)
        {
        case 1:
            agendar_consulta();
            break;
        case 2:
            atualizar_agendamento();
            break;
        case 3:
            listar_agendamentos();
            break;
        case 4:
            buscar_agendamento_por_cpf();
            break;
        case 5:
            excluir_agendamento();
            break;
        case 0:
            printf("           Voltando ao menu principal...\n");
            getchar();
            break;
        case -1:
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        default:
            printf("                Opção Inexistente!\n");
            printf("      >>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        }
    } while (op_agendamento != 0);
}

void agendar_consulta(void)
{
    FILE *arq_agendamentos;
    Agendamento *agd;
    Funcionario *fnc;

    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                    ✦✧✦✧✦   Agendar Consulta   ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    agd = (Agendamento *)malloc(sizeof(Agendamento));
    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    input(agd->cpf, 15, "Digite o CPF do cliente:");
    input(agd->nome, 100, "Digite o nome do cliente:");
    input(agd->tipo_consulta, 20, "Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia):");

    listar_funcionarios_por_cargo(agd->tipo_consulta, fnc->cpf, fnc->nome);

    if (strlen(fnc->cpf) == 0 || strlen(fnc->nome) == 0)
    {
        printf("\nAgendamento cancelado.\n");
        printf(">>> Tecle <ENTER> para continuar... <<<\n");
        getchar();
        return;
    }

    input(agd->data, 15, "Digite a data da consulta (DD/MM/AAAA):");
    input(agd->horario, 10, "Digite o horário da consulta (HH:MM):");

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "a+b");
    if (arq_agendamentos == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    agd->id = gerar_novo_id();
    agd->status = 1;
    fwrite(agd, sizeof(Agendamento), 1, arq_agendamentos);
    fwrite(fnc, sizeof(Funcionario), 1, arq_agendamentos);
    fclose(arq_agendamentos);
    free(agd);
    free(fnc);

    printf("\n         Consulta agendada com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void atualizar_agendamento(void)
{
    FILE *arq_agendamentos;
    Agendamento *agd;
    Funcionario *fnc;
    char cpf_lido[15];
    int id, id_escolhido, encontrado = 0, id_encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                          |\n");
    printf("|                 ✦✧✦✧✦   Atualizar Agendamento   ✦✧✦✧✦               |\n");
    printf("|                                                                          |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf_lido, 15, "Digite o CPF do cliente para listar os agendamentos: ");

    agd = (Agendamento *)malloc(sizeof(Agendamento));
    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "rb+");
    if (arq_agendamentos == NULL)
    {
        printf("Erro ao abrir arquivo de agendamentos!\n");
        free(agd);
        free(fnc);
        return;
    }

    printf("\nAgendamentos encontrados:\n------------------------------------------------\n");
    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos) == 1)
    {

        if (strcmp(agd->cpf, cpf_lido) == 0)
        {
            encontrado = 1;
            printf("ID: %d\n", agd->id);
            printf("CPF: %s\n", agd->cpf);
            printf("Nome: %s\n", agd->nome);
            printf("Tipo de consulta: %s\n", agd->tipo_consulta);
            printf("Funcionário: %s (%s)\n", agd->nome_funcionario, agd->cpf_funcionario);
            printf("Data: %s\n", agd->data);
            printf("Horário: %s\n", agd->horario);
            printf("------------------------------------------------\n");
        }
    }

    if (!encontrado)
    {
        printf("\nNenhum agendamento encontrado para este CPF!\n");
        printf(">>> Tecle <ENTER> para continuar... <<<\n");
        getchar();
        free(agd);
        free(fnc);
        fclose(arq_agendamentos);
        return;
    }

    printf("\nDigite o ID do agendamento que deseja atualizar: ");
    scanf("%d", &id_escolhido);
    getchar();

    // Rewind para reescrever o registro
    rewind(arq_agendamentos);

    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos) == 1)
    {
        if (agd->id == id_escolhido)
        {
            id_encontrado = 1;

            modulo_alteracao_agend(agd->nome, agd->tipo_consulta, agd->data, agd->horario);

            fseek(arq_agendamentos, -((long)sizeof(Agendamento)), SEEK_CUR);
            fwrite(agd, sizeof(Agendamento), 1, arq_agendamentos);
            break;
        }
    }

    fclose(arq_agendamentos);

    if (!id_encontrado)
    {
        printf("\nNenhum agendamento encontrado com o ID informado!\n");
        printf(">>> Nenhuma alteração foi feita. <<<\n");
    }
    else
    {
        printf("\nAgendamento atualizado com sucesso!\n");
    }

    printf(">>> Tecle <ENTER> para continuar... <<<\n");
    getchar();

    free(agd);
    free(fnc);
}

void listar_agendamentos(void)
{
    FILE *arq_agendamentos;
    Agendamento *agd;
    Funcionario *fnc;
    int encontrado = 0;
    char data_agendamento[15];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Listar Agendamentos   ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    agd = (Agendamento *)malloc(sizeof(Agendamento));
    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    input(data_agendamento, 15, "Digite a data desejada (dd/mm/aaaa): ");

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "rb");
    if (arq_agendamentos == NULL)
    {
        printf("Erro na abertura do arquivo\n!");
        return;
    }

    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos) &&
           fread(fnc, sizeof(Funcionario), 1, arq_agendamentos))
    {

        if (strcmp(agd->data, data_agendamento) == 0)
        {
            if (!encontrado)
            {
                printf("\nAgendamentos para a data %s:\n", agd->data);
                printf("------------------------------------------------\n");
            }
            encontrado = 1;
            printf("ID: %d\n", agd->id);
            printf("CPF: %s\n", agd->cpf);
            printf("Nome: %s\n", agd->nome);
            printf("Tipo de consulta: %s\n", agd->tipo_consulta);
            printf("Funcionário: %s (%s)\n", fnc->nome, fnc->cpf);
            printf("Data: %s\n", agd->data);
            printf("Horário: %s\n", agd->horario);
            printf("Status: %d\n", agd->status);
            printf("------------------------------------------------\n");
        }
    }
    fclose(arq_agendamentos);
    free(agd);
    free(fnc);
    if (!encontrado)
    {
        printf("\nNenhum agendamento encontrado!\n");
    }

    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void buscar_agendamento_por_cpf(void)
{
    FILE *arq_agendamentos;
    Agendamento *agd;
    Funcionario *fnc;
    char cpf_lido[15];
    int encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Buscar Agendamento   ✦✧✦✧✦                |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    agd = (Agendamento *)malloc(sizeof(Agendamento));
    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    input(cpf_lido, 15, "Digite o CPF do cliente para buscar: ");

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "rb");

    if (arq_agendamentos == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos) &&
           fread(fnc, sizeof(Funcionario), 1, arq_agendamentos))

    {

        if (strcmp(agd->cpf, cpf_lido) == 0)
        {
            if (!encontrado)
            {
                printf("\nAgendamentos do CPF %s encontrado!\n", cpf_lido);
                printf("------------------------------------------------\n");
            }

            encontrado = 1;
            printf("ID: %d\n", agd->id);
            printf("CPF: %s\n", agd->cpf);
            printf("Nome: %s\n", agd->nome);
            printf("Tipo de Consulta: %s\n", agd->tipo_consulta);
            printf("Funcionário: %s\n", fnc->nome);
            printf("Data: %s\n", agd->data);
            printf("Horário: %s\n", agd->horario);
            printf("Status: %d\n", agd->status);
            printf("------------------------------------------------\n");
        }
    }

    fclose(arq_agendamentos);
    free(agd);
    free(fnc);

    if (!encontrado)
    {
        printf("\nNenhum agendamento encontrado!\n");
    }

    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void excluir_agendamento(void)
{
    FILE *arq_agendamentos;
    Agendamento *agd;
    int encontrado = 0, id_escolhido = 0;
    char opcao;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                          |\n");
    printf("|                 ✦✧✦✧✦   Excluir Agendamento   ✦✧✦✧✦                 |\n");
    printf("|                                                                          |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    agd = (Agendamento *)malloc(sizeof(Agendamento));

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "rb");
    if (!arq_agendamentos)
    {
        printf("Erro ao abrir arquivo de agendamentos!\n");
        free(agd);
        return;
    }

    printf("Lista de Agendamentos:\n");
    printf("------------------------------------------------\n");
    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos))
    {
        if (agd->status == 1)
        {
            encontrado = 1;
            printf("ID: %d\n", agd->id);
            printf("CPF do Cliente: %s\n", agd->cpf);
            printf("Nome do Cliente: %s\n", agd->nome);
            printf("Tipo de Consulta: %s\n", agd->tipo_consulta);
            printf("Nome do Funcionário: %s\n", agd->nome_funcionario);
            printf("CPF do Funcionário: %s\n", agd->cpf_funcionario);
            printf("Data: %s\n", agd->data);
            printf("Horário: %s\n", agd->horario);
            printf("------------------------------------------------\n");
        }
    }
    fclose(arq_agendamentos);

    if (!encontrado)
    {
        printf("Nenhum agendamento ativo encontrado!\n");
        free(agd);
        printf(">>> Tecle <ENTER> para continuar... <<<\n");
        getchar();
        return;
    }

    printf("Digite o ID do agendamento que deseja excluir: ");
    scanf("%d", &id_escolhido);
    getchar();

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "r+b");
    if (!arq_agendamentos)
    {
        printf("Erro ao abrir arquivo para atualizar!\n");
        free(agd);
        return;
    }

    encontrado = 0;
    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos))
    {
        if (agd->id == id_escolhido && agd->status == 1)
        {
            encontrado = 1;
            printf("\nAgendamento com ID %d encontrado!\n", agd->id);
            printf("Deseja realmente excluir? (S/N): ");
            scanf(" %c", &opcao);
            getchar();

            if (opcao == 'S' || opcao == 's')
            {
                agd->status = 0;
                fseek(arq_agendamentos, -sizeof(Agendamento), SEEK_CUR);
                fwrite(agd, sizeof(Agendamento), 1, arq_agendamentos);
                printf("\nAgendamento excluído com sucesso!\n");
            }
            else
            {
                printf("\nExclusão cancelada!\n");
            }
            break;
        }
    }

    if (!encontrado)
        printf("\nAgendamento com o ID informado não encontrado!\n");

    fclose(arq_agendamentos);
    free(agd);
    printf(">>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

int gerar_novo_id()
{
    FILE *arq = fopen("agendamentos/agendamentos.dat", "rb");
    int ultimo_id = 0;
    Agendamento *agd;
    Funcionario *fnc;
    agd = (Agendamento *)malloc(sizeof(Agendamento));
    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    if (arq != NULL)
    {
        while (fread(agd, sizeof(Agendamento), 1, arq) &&
               fread(fnc, sizeof(Funcionario), 1, arq))
        {
            if (agd->id > ultimo_id)
                ultimo_id = agd->id;
        }
        fclose(arq);
    }
    free(agd);
    free(fnc);
    return ultimo_id + 1;
}

int menu_alterar_agendamento(void)
{
    int opcao;
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Alterar Nome                                   |\n");
    printf("|                      2. Alterar Tipo de Consulta                       |\n");
    printf("|                      3. Alterar Data                                   |\n");
    printf("|                      4. Alterar Horário                                |\n");
    printf("|                      0. Salvar e Sair                                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    opcao = escolha();

    return opcao;
}
void modulo_alteracao_agend(char *nome, char *tipo_consulta, char *data, char *horario)
{
    int opcao;
    do
    {
        opcao = menu_alterar_agendamento();

        switch (opcao)
        {
        case 1:
            input(nome, 100, "Digite o novo nome do cliente: ");
            printf("\nNome atualizado com sucesso!\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        case 2:
            input(tipo_consulta, 20, "Digite o novo tipo de consulta (Tarot, Signos, Numerologia): ");
            printf("\nTipo de consulta atualizado com sucesso!\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        case 3:
            input(data, 15, "Digite a nova data da consulta (DD/MM/AAAA): ");
            printf("\nData atualizada com sucesso!\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        case 4:
            input(horario, 10, "Digite o novo horário da consulta (HH:MM): ");
            printf("\nHorário atualizado com sucesso!\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        case 0:
            printf("           Voltando ao menu principal...\n");
            getchar();
            break;
        case -1:
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        default:
            printf("                Opção Inexistente!\n");
            printf("      >>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        }
    } while (opcao != 0);
}
