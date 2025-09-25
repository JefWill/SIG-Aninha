#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "agendamento.h"
#include "../utilitarios/utilitarios.h"

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
    char cpf[15], nome[100], data[15], horario[10], tipo_consulta[20];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                    ✦✧✦✧✦   Agendar Consulta   ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf, 15, "Digite o CPF do cliente:");
    input(nome, 100, "Digite o nome do cliente:");
    input(tipo_consulta, 20, "Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia):");
    input(data, 15, "Digite a data da consulta (DD/MM/AAAA):");
    input(horario, 10, "Digite o horário da consulta (HH:MM):");

    arq_agendamentos = fopen("agendamentos/agendamentos.csv", "at");
    if (arq_agendamentos == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    fprintf(arq_agendamentos, "%s;", cpf);
    fprintf(arq_agendamentos, "%s;", nome);
    fprintf(arq_agendamentos, "%s;", tipo_consulta);
    fprintf(arq_agendamentos, "%s;", data);
    fprintf(arq_agendamentos, "%s\n", horario);
    fclose(arq_agendamentos);

    printf("\n         Consulta agendada com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void atualizar_agendamento(void)
{
    // char id_funcionario[10];
    char cpf[15], nome[100], data[15], horario[10], tipo_consulta[20];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Atualizar Agendamento   ✦✧✦✧✦                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf, 15, "Digite o CPF do cliente: ");
    input(nome, 100, "Digite o nome do cliente: ");
    input(tipo_consulta, 20, "Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia): ");
    input(data, 15, "Digite a data da consulta (DD/MM/AAAA): ");
    input(horario, 10, "Digite o horário da consulta: ");

    printf("\n      Agendamento atualizado com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void listar_agendamentos(void)
{
    FILE *arq_agendamentos;
    char data[15];
    char cpf[15];
    char nome[100];
    char tipo_consulta[20];
    char data_agendamento[15];
    char horario[10];

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

    while (!feof(arq_agendamentos))
    {
        fscanf(arq_agendamentos, "%[^;]", cpf);
        fgetc(arq_agendamentos);
        fscanf(arq_agendamentos, "%[^;]", nome);
        fgetc(arq_agendamentos);
        fscanf(arq_agendamentos, "%[^;]", tipo_consulta);
        fgetc(arq_agendamentos);
        fscanf(arq_agendamentos, "%[^;]", data);
        fgetc(arq_agendamentos);
        fscanf(arq_agendamentos, "%[^\n]", horario);
        fgetc(arq_agendamentos);

        if (strcmp(data, data_agendamento) == 0)
        {
            printf("\nAgendamentos para a data %s:\n", data);
            printf("------------------------------------------------\n");
            printf("CPF: %s\n", cpf);
            printf("Nome: %s\n", nome);
            printf("Tipo de consulta: %s\n", tipo_consulta);
            printf("Data: %s\n", data);
            printf("Horário: %s\n\n", horario);
            printf("------------------------------------------------\n");
            printf("      >>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            fclose(arq_agendamentos);
            return;
        }
    }

    fclose(arq_agendamentos);
    printf("\n         Nenhum agendamento encontrado!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}

void buscar_agendamento_por_cpf(void)
{
    FILE *arq_agendamentos;
    char cpf[15], cpf_lido[15], nome[100], data[15], horario[10], tipo_consulta[20];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Buscar Agendamento   ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf_lido, 15, "Digite o CPF do cliente para buscar: ");

    arq_agendamentos = fopen("agendamentos/agendamentos.csv", "rt");
    if (arq_agendamentos == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    while (!feof(arq_agendamentos))
    {
        fscanf(arq_agendamentos, "%[^;]", cpf);
        fgetc(arq_agendamentos);
        fscanf(arq_agendamentos, "%[^;]", nome);
        fgetc(arq_agendamentos);
        fscanf(arq_agendamentos, "%[^;]", tipo_consulta);
        fgetc(arq_agendamentos);
        fscanf(arq_agendamentos, "%[^;]", data);
        fgetc(arq_agendamentos);
        fscanf(arq_agendamentos, "%[^\n]", horario);
        fgetc(arq_agendamentos);

        if (strcmp(cpf, cpf_lido) == 0)
        {
            printf("\nAgendamento do CPF %s encontrado!\n", cpf);
            printf("CPF: %s\n", cpf);
            printf("Nome: %s\n", nome);
            printf("Tipo de Consulta: %s\n", tipo_consulta);
            printf("Data: %s\n", data);
            printf("Horário: %s\n", horario);
            printf("Pressione enter para continuar...");
            getchar();
            fclose(arq_agendamentos);

            return;
        }
    }
    fclose(arq_agendamentos);
    printf("Agendamento não encontrado!");

    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}

void excluir_agendamento(void)
{
    char cpf[15];
    char resposta[3];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Excluir Agendamento   ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf, 15, "Digite o CPF do cliente:");
    input(resposta, 3, "\nDeseja excluir o agendamento do cliente? (S/N)");

    if (resposta[0] == 'S' || resposta[0] == 's')
    {
        printf("\n       Agendamento excluído com sucesso!\n");
    }
    else
    {
        printf("\n              Exclusão cancelada!\n");
    }

    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}
