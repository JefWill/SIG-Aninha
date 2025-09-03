#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "agendamento.h"


//////////////////////////////////////////////
///////////// MODULO AGENDAMENTO /////////////
//////////////////////////////////////////////

int tela_menu_agendamento(void)
{
    int op_agendamento = 11;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧ SIG-Aninha - Módulo agendamento ✧✦✧✦      |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Agendar consulta                  |\n");
    printf("|           2. Atualizar agendamento             |\n");
    printf("|           3. Listar agendamentos (no dia)      |\n");
    printf("|           4. Buscar agendamento por cliente    |\n");
    printf("|           5. Cancelar agendamento              |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    op_agendamento = escolha();

    return op_agendamento;
}

void modulo_agendamentos(void)
{
    int op_agendamento = 11;
    while (op_agendamento != 0)
    {
        op_agendamento = tela_menu_agendamento();

        if (op_agendamento == 1)
        {
            agendar_consulta();
        }
        else if (op_agendamento == 2)
        {
            atualizar_agendamento();
        }
        else if (op_agendamento == 3)
        {
            listar_agendamentos();
        }
        else if (op_agendamento == 4)
        {
            buscar_agendamento_por_cpf();
        }
        else if (op_agendamento == 5)
        {
            excluir_agendamento();
        }
        else if (op_agendamento == 0)
        {
            printf("           Voltando ao menu principal...\n");
            getchar();
        }
        else
        {
            printf("                Opção inválida!\n");
            printf("      >>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
        }
    }
}

void agendar_consulta(void)
{
    char cpf[15], nome[100], data[11], horario[6], tipo_consulta[20];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|          ✦✧✦✧ Agendar Consulta ✧✦✧✦          |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    input(cpf, 15, "Digite o CPF do cliente:");
    input(nome, 100, "Digite o nome do cliente:");
    input(tipo_consulta, 20, "Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia):");
    input(data, 11, "Digite a data da consulta (DD/MM/AAAA):");
    input(horario, 6, "Digite o horário da consulta (HH:MM):");

    printf("\n         Consulta agendada com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void atualizar_agendamento(void)
{
    char id_funcionario[10];
    char cpf[15], nome[100], data[11], horario[6], tipo_consulta[20];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|       ✦✧✦✧ Atualizar Agendamento ✧✦✧✦       |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    input(cpf, 15, "Digite o CPF do cliente: ");
    input(nome, 100, "Digite o nome do cliente: ");
    input(tipo_consulta, 20, "Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia): ");
    input(id_funcionario, 10, "informe o id do funcionáio");
    input(data, 11, "Digite a data da consulta (DD/MM/AAAA): ");
    input(horario, 6, "Digite o horário da consulta: ");

    printf("\n      Agendamento atualizado com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void listar_agendamentos(void)
{
    char data[11];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|         ✦✧✦✧ Listar Agendamentos ✧✦✧✦       |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    printf("Digite a data desejada (dd/mm/aaaa): ");
    scanf("%s", data);
    printf("\nAgendamentos para a data %s:\n", data);
    printf("Exibe os agendamentos da data...\n");

    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}

void buscar_agendamento_por_cpf(void)
{
    char cpf[15];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|        ✦✧✦✧ Buscar Agendamento ✧✦✧✦         |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    printf("\nAgendamentos do cliente %s:\n", cpf);
    printf("Exibe os agendamentos do cliente...\n");

    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}

void excluir_agendamento(void)
{
    char cpf[15];
    char resposta[3];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|        ✦✧✦✧ Excluir Agendamento ✧✦✧✦        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

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
