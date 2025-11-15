#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "relatorio.h"
#include "../utilitarios/utilitarios.h"
#include "../clientes/cliente.h"
#include "../funcionarios/funcionario.h"
#include "../agendamentos/agendamento.h"

//////////////////////////////////////////////
///////////// MODULO RELATORIO ///////////////
//////////////////////////////////////////////

int tela_menu_relatorio(void)
{
    int op_rel;
    system("clear||cls");
    header();
    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|          ✦✧✦✧✦    SIG-Aninha - Módulo Relatórios    ✦✧✦✧✦         |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 1. Relatório de Dados Gerais                           |\n");
    printf("|                 2. Relatório com Dados Filtrados                       |\n");
    printf("|                 3. Relatório por Tipo de Serviço                       |\n");
    printf("|                    (Tarot, Signos, Numerologia)                        |\n");
    printf("|                 4. Relatório de Agendamentos Pendentes                 |\n");
    printf("|                 5. Relatório de Clientes Atendidos por Período         |\n");
    printf("|                 0. Voltar ao Menu Principal                            |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_rel = escolha();
    return op_rel;
}

void modulo_relatorio(void)
{
    int op_rel;
    do
    {
        op_rel = tela_menu_relatorio();

        switch (op_rel)
        {
        case 1:
            escolha_relatorios_gerais();
            break;
         case 2:
            escolha_relatorios_filtrados();
            break;
        case 3:
            printf("Relatório por Tipo de Serviço - Em Desenvolvimento...\n");
            break;
        case 4:
             printf("Relatório de Agendamentos Pendentes - Em Desenvolvimento...\n");
             break;
         case 5:
             printf("Relatório de Clientes Atendidos por Período - Em Desenvolvimento...\n");
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
    } while (op_rel != 0);
}

int menu_relatorio_dados(void){
    int op_dados_gerais;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 1. Relatório de Dados de Clientes                      |\n");
    printf("|                 2. Relatório de Dados de Funcionarios                  |\n");
    printf("|                 3. Relatório de Dados de Agendamentos                  |\n");
    printf("|                 0. Voltar ao Menu Principal                            |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_dados_gerais=escolha();
    return op_dados_gerais;
}

int menu_relatorio_dados_filtro(void){
    int op_dados_filtro;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 1. Listar Funcionários por Cargos                      |\n");
    printf("|                 0. Voltar ao Menu Principal                            |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_dados_filtro=escolha();
    return op_dados_filtro;
}

void escolha_relatorios_gerais(void){
    int op_dados_gerais;
    do{
        op_dados_gerais=menu_relatorio_dados();

        switch (op_dados_gerais){
            case 1:
                listar_clientes();
                break;
            case 2:
                listar_funcionarios();
                break;
            case 3:
                listar_todos_agendamentos();
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
    } while (op_dados_gerais!=0);
}

void escolha_relatorios_filtrados(void){
    
    int op_dados_filtro;

    do{
        op_dados_filtro=menu_relatorio_dados_filtro();

        switch (op_dados_filtro){
            case 1:
                listar_funcionarios_cargo();
                break;
            case 2:
                listar_funcionarios();
                break;
            case 3:
                listar_todos_agendamentos();
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
    } while (op_dados_filtro!=0);
}
