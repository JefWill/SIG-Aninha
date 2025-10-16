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
    //printf("|                      6. Cancelar Agendamento Fisicamente               |\n");
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
        //case 6:
            //excluir_agendamento_fisico();
            //break;
        case 0:
            printf("           Voltando ao menu principal...\n");
            getchar();
            break;
        case -1:
            confirmacao();
            break;
        default:
            printf("                Opção Inexistente!\n");
            confirmacao();
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
        confirmacao();
        free(agd);
        free(fnc);
        return;
    }

    input(agd->data, 15, "Digite a data da consulta (DD/MM/AAAA):");
    input(agd->horario, 10, "Digite o horário da consulta (HH:MM):");

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "a+b");
    if (arq_agendamentos == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        free(agd);
        free(fnc);
        return;
    }

    agd->id = gerar_novo_id();
    agd->status = 1;
    strcpy(agd->cpf_funcionario, fnc->cpf);
    strcpy(agd->nome_funcionario, fnc->nome);

    fwrite(agd, sizeof(Agendamento), 1, arq_agendamentos);

    fclose(arq_agendamentos);
    free(agd);
    free(fnc);

    printf("\n         Consulta agendada com sucesso!\n");
    confirmacao();
}

void atualizar_agendamento(void)
{
    FILE *arq_agendamentos;
    Agendamento *agd;
    char cpf_lido[15];
    int id_escolhido, encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                          |\n");
    printf("|                 ✦✧✦✧✦   Atualizar Agendamento   ✦✧✦✧✦               |\n");
    printf("|                                                                          |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf_lido, 15, "Digite o CPF do cliente para listar os agendamentos: ");

    agd = (Agendamento *)malloc(sizeof(Agendamento));

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "r+b");
    if (!arq_agendamentos)
    {
        printf("Erro ao abrir arquivo de agendamentos!\n");
        getchar();
        return;
    }

    printf("\nAgendamentos encontrados:\n------------------------------------------------\n");
    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos) && (!encontrado))
    {
        if ((strcmp(agd->cpf, cpf_lido) == 0) && (agd->status == 1))
        {
            encontrado = 1;
            exibir_agendamento(agd);
            printf("------------------------------------------------\n");
        }
    }

    if (!encontrado)
    {
        printf("\nNenhum agendamento encontrado para este CPF!\n");
        fclose(arq_agendamentos);
        free(agd);
        confirmacao();
        return;
    }

    printf("\nDigite o ID do agendamento que deseja atualizar: ");
    scanf("%d", &id_escolhido);
    getchar();

    // Volta para o início do arquivo para procurar o ID escolhido
    fseek(arq_agendamentos, 0, SEEK_SET);

    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos))
    {
        if (agd->id == id_escolhido && agd->status == 1)
        {
            fseek(arq_agendamentos, (-1) * ((long)sizeof(Agendamento)), SEEK_CUR);

            modulo_alteracao_agend(agd->nome, agd->tipo_consulta, agd->data, agd->horario);

            fwrite(agd, sizeof(Agendamento), 1, arq_agendamentos);
            printf("\nAgendamento atualizado com sucesso!\n");
            break;
        }
    }

    fclose(arq_agendamentos);
    free(agd);

    confirmacao();
}

void listar_agendamentos(void)
{
    FILE *arq_agendamentos;
    Agendamento *agd;
    int encontrado = 0;
    char data_agendamento[15];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Listar Agendamentos   ✦✧✦✧✦               |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    agd = (Agendamento *)malloc(sizeof(Agendamento));

    input(data_agendamento, 15, "Digite a data desejada (dd/mm/aaaa): ");

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "rb");
    if (arq_agendamentos == NULL)
    {
        printf("Erro na abertura do arquivo\n!");
        free(agd);
        return;
    }

    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos))
    {
        if (strcmp(agd->data, data_agendamento) == 0)
        {
            if (!encontrado)
            {
                printf("\nAgendamentos para a data %s:\n", agd->data);
                printf("------------------------------------------------\n");
            }
            encontrado = 1;
            exibir_agendamento(agd);
            printf("------------------------------------------------\n");
        }
    }

    fclose(arq_agendamentos);
    free(agd);

    if (!encontrado)
    {
        printf("\nNenhum agendamento encontrado!\n");
    }

    confirmacao();
}

void buscar_agendamento_por_cpf(void)
{
    FILE *arq_agendamentos;
    Agendamento *agd;
    char cpf_lido[15];
    int encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Buscar Agendamento   ✦✧✦✧✦                |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    agd = (Agendamento *)malloc(sizeof(Agendamento));

    input(cpf_lido, 15, "Digite o CPF do cliente para buscar: ");

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "rb");
    if (arq_agendamentos == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        free(agd);
        return;
    }

    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos))
    {
        if ((strcmp(agd->cpf, cpf_lido) == 0) && (agd->status == 1))
        {
            if (!encontrado)
            {
                printf("\nAgendamentos do CPF %s encontrados:\n", cpf_lido);
                printf("------------------------------------------------\n");
            }
            encontrado = 1;
            exibir_agendamento(agd);
            printf("------------------------------------------------\n");
        }
    }

    fclose(arq_agendamentos);
    free(agd);

    if (!encontrado)
    {
        printf("\nNenhum agendamento encontrado para este CPF!\n");
    }

    confirmacao();
}

void excluir_agendamento(void)
{
    FILE *arq_agendamentos;
    Agendamento *agd;
    char cpf_lido[15];
    int encontrado = 0, id_escolhido = 0;
    char opcao;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                          |\n");
    printf("|                 ✦✧✦✧✦   Excluir Agendamento   ✦✧✦✧✦                 |\n");
    printf("|                                                                          |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    agd = (Agendamento *)malloc(sizeof(Agendamento));

    input(cpf_lido, 15, "Digite o CPF do cliente para listar os agendamentos: ");

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "r+b");
    if (!arq_agendamentos)
    {
        printf("Erro ao abrir arquivo de agendamentos!\n");
        free(agd);
        getchar();
        return;
    }

    printf("\nAgendamentos encontrados para o CPF %s:\n------------------------------------------------\n", cpf_lido);
    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos))
    {
        if ((strcmp(agd->cpf, cpf_lido) == 0) && (agd->status == 1))
        {
            encontrado = 1;
            exibir_agendamento(agd);
            printf("------------------------------------------------\n");
        }
    }

    if (!encontrado)
    {
        printf("Nenhum agendamento ativo encontrado para este CPF!\n");
        fclose(arq_agendamentos);
        free(agd);
        confirmacao();
        return;
    }

    printf("Digite o ID do agendamento que deseja excluir: ");
    scanf("%d", &id_escolhido);
    getchar();

    // Volta para o início do arquivo para procurar o ID
    fseek(arq_agendamentos, 0, SEEK_SET);
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
                fseek(arq_agendamentos, -((long)sizeof(Agendamento)), SEEK_CUR);
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
    {
        printf("\nAgendamento com o ID informado não encontrado!\n");
    }

    fclose(arq_agendamentos);
    free(agd);

    confirmacao();
}

int gerar_novo_id()
{
    FILE *arq = fopen("agendamentos/agendamentos.dat", "rb");
    int ultimo_id = 0;
    Agendamento *agd;

    agd = (Agendamento *)malloc(sizeof(Agendamento));

    if (arq != NULL)
    {
        while (fread(agd, sizeof(Agendamento), 1, arq))
        {
            if (agd->id > ultimo_id)
                ultimo_id = agd->id;
        }
        fclose(arq);
    }

    free(agd);
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
            confirmacao();
            break;
        case 2:
            input(tipo_consulta, 20, "Digite o novo tipo de consulta (Tarot, Signos, Numerologia): ");
            printf("\nTipo de consulta atualizado com sucesso!\n");
            confirmacao();
            break;
        case 3:
            input(data, 15, "Digite a nova data da consulta (DD/MM/AAAA): ");
            printf("\nData atualizada com sucesso!\n");
            confirmacao();
            break;
        case 4:
            input(horario, 10, "Digite o novo horário da consulta (HH:MM): ");
            printf("\nHorário atualizado com sucesso!\n");
            confirmacao();
            break;
        case 0:
            printf("           Voltando ao menu principal...\n");
            getchar();
            break;
        case -1:
            confirmacao();
            break;
        default:
            printf("                Opção Inexistente!\n");
            confirmacao();
            break;
        }
    } while (opcao != 0);
}


void exibir_agendamento(const Agendamento *agd)
{
    printf("ID: %d\n", agd->id);
    printf("CPF: %s\n", agd->cpf);
    printf("Nome: %s\n", agd->nome);
    printf("Tipo de consulta: %s\n", agd->tipo_consulta);
    printf("Funcionário: %s \n", agd->nome_funcionario);
    printf("Data: %s\n", agd->data);
    printf("Horário: %s\n", agd->horario);
    printf("Status: %d\n", agd->status);
}


void excluir_agendamento_fisico(void)
{
    FILE *arq_agendamentos;
    FILE *arq_agendamentos2;
    Agendamento *agd;
    char opcao;
    int encontrado = 0;
    char cpf_lido[15];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|              ✦✧✦✧✦  Excluir Agendamento Fisicamente  ✦✧✦✧✦         |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    agd = (Agendamento *)malloc(sizeof(Agendamento));
    input(cpf_lido, 15, "Informe o CPF do cliente que fez o agendamento que você deseja excluir: ");

    arq_agendamentos = fopen("agendamentos/agendamentos.dat", "rb");
    arq_agendamentos2 = fopen("agendamentos/agendamentos2.dat", "wb");

    if ((arq_agendamentos == NULL) || (arq_agendamentos2 == NULL))
    {
        printf("Erro na criação do arquivo!\n");
        free(agd);
        getchar();
        return;
    }

    while (fread(agd, sizeof(Agendamento), 1, arq_agendamentos))
    {
        if ((strcmp(agd->cpf, cpf_lido) == 0))
        {
            encontrado = 1;
            printf("\nAgendamento do cliente com CPF %s encontrado!\n", agd->cpf);
            exibir_agendamento(agd);

            printf("\nConfirma exclusão definitiva deste agendamento? (S/N): ");
            scanf(" %c", &opcao);
            getchar();

            if (opcao == 'S' || opcao == 's')
            {
                printf("\nAgendamento do cliente com CPF %s excluído com sucesso!\n", agd->cpf);
            }
            else
            {
                printf("        Exclusão cancelada!\n");
                fwrite(agd, sizeof(Agendamento), 1, arq_agendamentos2);
            }
        }
        else
        {
            fwrite(agd, sizeof(Agendamento), 1, arq_agendamentos2);
        }
    }

    fclose(arq_agendamentos);
    fclose(arq_agendamentos2);
    free(agd);

    if (encontrado)
    {
        remove("agendamentos/agendamentos.dat");
        rename("agendamentos/agendamentos2.dat", "agendamentos/agendamentos.dat");
    }
    else
    {
        remove("agendamentos/agendamentos2.dat");
        printf("CPF não encontrado!\n");
    }

    confirmacao();
}