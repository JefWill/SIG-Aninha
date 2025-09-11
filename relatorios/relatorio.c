#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "relatorio.h"
#include "../utilitarios/utilitarios.h"

//////////////////////////////////////////////
///////////// MODULO RELATORIO ///////////////
//////////////////////////////////////////////

void tela_menu_relatorio(void)
{
    system("clear||cls");
    header();
    int op_rel;
    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("|   ✦✧✦✧✦  SIG-Aninha - Módulo Relatórios  ✦✧✦✧✦     |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("|    1. Relatório de Clientes Cadastrados            |\n");
    printf("|    2. Relatório de Atendimentos Realizados         |\n");
    printf("|    3. Relatório por Tipo de Serviço (Tarot,        |\n");
    printf("|    Signos, Numerologia)                            |\n");
    printf("|    4. Relatório de Agendamentos Pendentes          |\n");
    printf("|    5. Relatório de Clientes Atendidos por Período  |\n");
    printf("|    0. Voltar ao Menu Principal                     |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_rel = escolha();
}
