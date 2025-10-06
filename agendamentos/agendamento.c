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
    Agendamento agd;
    Funcionario fnc;
    int id;

    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                    ✦✧✦✧✦   Agendar Consulta   ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(agd.cpf, 15, "Digite o CPF do cliente:");
    input(agd.nome, 100, "Digite o nome do cliente:");
    input(agd.tipo_consulta, 20, "Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia):");

    listar_funcionarios_por_cargo(agd.tipo_consulta, fnc.cpf, fnc.nome);

    if (strlen(fnc.cpf) == 0 || strlen(fnc.nome) == 0)
    {
        printf("\nAgendamento cancelado.\n");
        printf(">>> Tecle <ENTER> para continuar... <<<\n");
        getchar();
        return;
    }

    input(agd.data, 15, "Digite a data da consulta (DD/MM/AAAA):");
    input(agd.horario, 10, "Digite o horário da consulta (HH:MM):");

    arq_agendamentos = fopen("agendamentos/agendamentos.csv", "at");
    if (arq_agendamentos == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    id = gerar_novo_id();
    fprintf(arq_agendamentos, "%d;", id);
    fprintf(arq_agendamentos, "%s;", agd.cpf);
    fprintf(arq_agendamentos, "%s;", agd.nome);
    fprintf(arq_agendamentos, "%s;", agd.tipo_consulta);
    fprintf(arq_agendamentos, "%s;", fnc.cpf);
    fprintf(arq_agendamentos, "%s;", fnc.nome);
    fprintf(arq_agendamentos, "%s;", agd.data);
    fprintf(arq_agendamentos, "%s\n", agd.horario);
    fclose(arq_agendamentos);

    printf("\n         Consulta agendada com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void atualizar_agendamento(void)
{
    FILE *arq_agendamentos, *arq_agendamentos2;
    Agendamento agd;
    Funcionario fnc;

    int id, id_escolhido, encontrado = 0, id_encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                 ✦✧✦✧✦   Atualizar Agendamento   ✦✧✦✧✦                  |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(agd.cpf_lido, 15, "Digite o CPF do cliente para listar os agendamentos: ");

    arq_agendamentos = fopen("agendamentos/agendamentos.csv", "rt");
    if (arq_agendamentos == NULL)
    {
        printf("Erro ao abrir arquivo de agendamentos!\n");
        return;
    }

    printf("\nAgendamentos encontrados:\n------------------------------------------------\n");
    while (fscanf(arq_agendamentos, "%d;%14[^;];%99[^;];%19[^;];%14[^;];%99[^;];%14[^;];%9[^\n]\n",
                  &id, agd.cpf, agd.nome, agd.tipo_consulta, fnc.cpf, fnc.nome, agd.data, agd.horario) == 8)
    {
        if (strcmp(agd.cpf, agd.cpf_lido) == 0)
        {
            encontrado = 1;
            printf("ID: %d\n", id);
            printf("CPF: %s\n", agd.cpf);
            printf("Nome: %s\n", agd.nome);
            printf("Tipo de consulta: %s\n", agd.tipo_consulta);
            printf("Funcionário: %s (%s)\n", fnc.nome, fnc.cpf);
            printf("Data: %s\n", agd.data);
            printf("Horário: %s\n", agd.horario);
            printf("------------------------------------------------\n");
        }
    }
    fclose(arq_agendamentos);

    if (!encontrado)
    {
        printf("\nNenhum agendamento encontrado para este CPF!\n");
        printf(">>> Tecle <ENTER> para continuar... <<<\n");
        getchar();
        return;
    }

    printf("\nDigite o ID do agendamento que deseja atualizar: ");
    scanf("%d", &id_escolhido);
    getchar();

    arq_agendamentos = fopen("agendamentos/agendamentos.csv", "rt");
    arq_agendamentos2 = fopen("agendamentos/temp.csv", "wt");
    if (arq_agendamentos == NULL || arq_agendamentos2 == NULL)
    {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    while (fscanf(arq_agendamentos, "%d;%14[^;];%99[^;];%19[^;];%14[^;];%99[^;];%14[^;];%9[^\n]\n",
                  &id, agd.cpf, agd.nome, agd.tipo_consulta, fnc.cpf, fnc.nome, agd.data, agd.horario) == 8)
    {
        if (id == id_escolhido)
        {
            id_encontrado = 1;
            modulo_alteracao_agend(agd.nome, agd.tipo_consulta, agd.data, agd.horario);
        }

        fprintf(arq_agendamentos2, "%d;%s;%s;%s;%s;%s;%s;%s\n",
                id, agd.cpf, agd.nome, agd.tipo_consulta, fnc.cpf, fnc.nome, agd.data, agd.horario);
    }

    fclose(arq_agendamentos);
    fclose(arq_agendamentos2);

    if (!id_encontrado)
    {
        remove("agendamentos/temp.csv");
        printf("\nNenhum agendamento encontrado com o ID informado!\n");
        printf(">>> Nenhuma alteração foi feita. <<<\n");
    }
    else
    {
        remove("agendamentos/agendamentos.csv");
        rename("agendamentos/temp.csv", "agendamentos/agendamentos.csv");

        printf("\nAgendamento atualizado com sucesso!\n");
    }

    printf(">>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void listar_agendamentos(void)
{
    FILE *arq_agendamentos;
    Agendamento agd;
    Funcionario fnc;
    int id;
    int encontrado = 0;
    char data_agendamento[15];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Listar Agendamentos   ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(data_agendamento, 15, "Digite a data desejada (dd/mm/aaaa): ");

    arq_agendamentos = fopen("agendamentos/agendamentos.csv", "rt");
    if (arq_agendamentos == NULL)
    {
        printf("Erro na abertura do arquivo\n!");
        return;
    }

    while (fscanf(arq_agendamentos, "%d;%14[^;];%99[^;];%19[^;];%14[^;];%99[^;];%14[^;];%9[^\n]\n",
                  &id, agd.cpf, agd.nome, agd.tipo_consulta, fnc.cpf, fnc.nome, agd.data, agd.horario) == 8)
    {

        if (strcmp(agd.data, data_agendamento) == 0)
        {
            if (!encontrado)
            {
                printf("\nAgendamentos para a data %s:\n", agd.data);
                printf("------------------------------------------------\n");
            }
            encontrado = 1;
            printf("ID: %d\n", id);
            printf("CPF: %s\n", agd.cpf);
            printf("Nome: %s\n", agd.nome);
            printf("Tipo de consulta: %s\n", agd.tipo_consulta);
            printf("Funcionário: %s (%s)\n", fnc.nome, fnc.cpf);
            printf("Data: %s\n", agd.data);
            printf("Horário: %s\n\n", agd.horario);
            printf("------------------------------------------------\n");
        }
    }
    fclose(arq_agendamentos);
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
    Agendamento agd;
    Funcionario fnc;
    int encontrado = 0;
    int id;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Buscar Agendamento   ✦✧✦✧✦                |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(agd.cpf_lido, 15, "Digite o CPF do cliente para buscar: ");

    arq_agendamentos = fopen("agendamentos/agendamentos.csv", "rt");

    if (arq_agendamentos == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    while (fscanf(arq_agendamentos,
                  "%d;%14[^;];%99[^;];%19[^;];%14[^;];%99[^;];%14[^;];%9[^\n]\n",
                  &id, agd.cpf, agd.nome, agd.tipo_consulta, fnc.cpf, fnc.nome, agd.data, agd.horario) == 8)

    {

        if (strcmp(agd.cpf, agd.cpf_lido) == 0)
        {
            if (!encontrado)
            {
                printf("\nAgendamentos do CPF %s encontrado!\n", agd.cpf_lido);
                printf("------------------------------------------------\n");
            }

            encontrado = 1;
            printf("ID: %d\n", id);
            printf("CPF: %s\n", agd.cpf);
            printf("Nome: %s\n", agd.nome);
            printf("Tipo de Consulta: %s\n", agd.tipo_consulta);
            printf("Funcionário: %s (%s)\n", fnc.nome, fnc.cpf);
            printf("Data: %s\n", agd.data);
            printf("Horário: %s\n", agd.horario);
            printf("------------------------------------------------\n");
        }
    }

    fclose(arq_agendamentos);

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
    FILE *arq_agendamentos2;
    char cpf_lido[15];
    char cpf[15], nome[100], tipo_consulta[20], data[15], horario[10];
    char cpf_funcionario[15], nome_funcionario[100];
    int id, id_escolhido, encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Excluir Agendamento   ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf_lido, 15, "Digite o CPF do cliente:");

    arq_agendamentos = fopen("agendamentos/agendamentos.csv", "rt");
    if (arq_agendamentos == NULL)
    {
        printf("Erro ao abrir arquivo de agendamentos!\n");
        return;
    }

    printf("\nAgendamentos encontrados:\n");
    printf("------------------------------------------------\n");

    while (fscanf(arq_agendamentos,
                  "%d;%14[^;];%99[^;];%19[^;];%14[^;];%99[^;];%14[^;];%9[^\n]\n",
                  &id, cpf, nome, tipo_consulta, cpf_funcionario, nome_funcionario, data, horario) == 8)
    {
        if (strcmp(cpf, cpf_lido) == 0)
        {
            encontrado = 1;
            printf("ID: %d\n", id);
            printf("CPF: %s\n", cpf);
            printf("Nome: %s\n", nome);
            printf("Tipo de Consulta: %s\n", tipo_consulta);
            printf("Funcionário: %s (%s)\n", nome_funcionario, cpf_funcionario);
            printf("Data: %s\n", data);
            printf("Horário: %s\n", horario);
            printf("------------------------------------------------\n");
        }
    }
    fclose(arq_agendamentos);

    if (!encontrado)
    {
        printf("\nNenhum agendamento encontrado para este CPF!\n");
        printf(">>> Tecle <ENTER> para continuar... <<<\n");
        getchar();
        return;
    }

    printf("Digite o ID do agendamento que deseja excluir: ");
    scanf("%d", &id_escolhido);
    getchar();

    arq_agendamentos = fopen("agendamentos/agendamentos.csv", "rt");
    arq_agendamentos2 = fopen("agendamentos/agendamentos2.csv", "wt");

    if (arq_agendamentos == NULL || arq_agendamentos2 == NULL)
    {
        printf("Erro ao manipular arquivos!\n");
        return;
    }

    while (fscanf(arq_agendamentos,
                  "%d;%14[^;];%99[^;];%19[^;];%14[^;];%99[^;];%14[^;];%9[^\n]\n",
                  &id, cpf, nome, tipo_consulta, cpf_funcionario, nome_funcionario, data, horario) == 8)
    {
        if (id != id_escolhido)
        {
            fprintf(arq_agendamentos2, "%d;%s;%s;%s;%s;%s;%s;%s\n",
                    id, cpf, nome, tipo_consulta, cpf_funcionario, nome_funcionario, data, horario);
        }
    }

    fclose(arq_agendamentos);
    fclose(arq_agendamentos2);

    remove("agendamentos/agendamentos.csv");
    rename("agendamentos/agendamentos2.csv", "agendamentos/agendamentos.csv");

    printf("\nAgendamento excluído com sucesso!\n");
    printf(">>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

int gerar_novo_id()
{
    FILE *arq = fopen("agendamentos/agendamentos.csv", "rt");
    int id = 0, ultimo_id = 0;
    char cpf_cliente[15], nome_cliente[100];
    char tipo_consulta[20], cpf_funcionario[15], nome_funcionario[100];
    char data[15], horario[10];

    if (arq != NULL)
    {
        while (fscanf(arq, "%d;%14[^;];%99[^;];%19[^;];%14[^;];%99[^;];%14[^;];%9[^\n]\n",
                      &id,
                      cpf_cliente,
                      nome_cliente,
                      tipo_consulta,
                      cpf_funcionario,
                      nome_funcionario,
                      data,
                      horario) == 8)
        {
            if (id > ultimo_id)
            {
                ultimo_id = id;
            }
        }
        fclose(arq);
    }

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
