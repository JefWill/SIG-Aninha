#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "relatorio.h"
#include "../utilitarios/utilitarios.h"
#include "../clientes/cliente.h"
#include "../funcionarios/funcionario.h"
#include "../agendamentos/agendamento.h"
#include "../servicos/servicos.h"

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
    printf("|                 3. Relatório com Lista Dinâmicas                       |\n");
    printf("|                 4. Relatório com dados ordenados                       |\n");
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
            escolha_relatorios_dinamicos();
            break;
        case 4:
            escolha_relatorios_ordenados();
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
    printf("|                 1. Listar Funcionários Por Cargos                      |\n");
    printf("|                 2. Listar Serviços Por Data                            |\n");
    printf("|                 3. Listar Agendamentos Por Tipo                        |\n");
    printf("|                 4. Listar Clientes Por DDD                             |\n");
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
                listar_servicos_por_data();
                break;
            case 3:
                listar_agendamento_tipo();
                break;
            case 4:
                listar_clientes_ddd();
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

int menu_relatorio_dinamicos(void){
    int op_dados_filtro;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 1. Listar Clientes Ativos                              |\n");
    printf("|                 2. Listar serviços por cliente                         |\n");
    printf("|                 0. Voltar ao Menu Principal                            |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_dados_filtro=escolha();
    return op_dados_filtro;
}

void escolha_relatorios_dinamicos(void){
    int op_dados_gerais;
    ClienteDinamico* lista_clientes;
    ServicosDinamico* lista_servicos;
    do{

        op_dados_gerais=menu_relatorio_dinamicos();

        switch (op_dados_gerais){
            case 1:
                lista_clientes = carregar_cli_ativos();
                exibir_cli_ativos(lista_clientes);
                break;
            case 2:
                lista_servicos = carregar_servicos_por_cpf();
                exibir_servicos_por_cpf(lista_servicos);
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

int menu_relatorio_ordenados(void){
    int op_dados_filtro;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 1. Lista de Cliente Ordem Alfabética                   |\n");
    printf("|                 0. Voltar ao Menu Principal                            |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_dados_filtro=escolha();
    return op_dados_filtro;
}

void escolha_relatorios_ordenados(void){
    int op_dados_gerais;
    ClienteDinamico* lista;
    do{

        op_dados_gerais=menu_relatorio_ordenados();

        switch (op_dados_gerais){
            case 1:
                lista = ordenar_clientes();
                exibir_cli_ativos(lista);
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
