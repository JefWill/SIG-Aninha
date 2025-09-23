// Universidade Federal do Rio Grande do Norte - UFRN
// Centro de Ensino Superior do Seridó - CERES
// Departamento de Computação e Tecnologia - DCT
// Disciplina DCT1106 - Programação
// Projeto Sistema de Gestão Mística (SIG-Aninha)
// Desenvolvido por: @JaineSouz e @JeffWill - since Ago, 2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./informacoes/informacoes.h"
#include "./relatorios/relatorio.h"
#include "./servicos/servicos.h"
#include "./agendamentos/agendamento.h"
#include "./clientes/cliente.h"
#include "./funcionarios/funcionario.h"
#include "./utilitarios/utilitarios.h"

// Assinatura da Função
int tela_menu_principal(void);

int main(void)
{
    int op = 10;

    do
    {
        op = tela_menu_principal();

        switch (op)
        {

        case 1:
            modulo_cliente();
            break;
        case 2:
            modulo_funcionario();
            break;
        case 3:
            modulo_agendamentos();
            break;
        case 4:
            modulo_servicos();
            break;
        case 5:
            tela_menu_relatorio();
            break;
        case 6:
            modulo_informacoes();
            break;
        case 0:
            printf("Encerrando o sistema... Até logo!\n");
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

    } while (op != 0);

    return 0;
}

// Funções da Tela do Menu Principal e Cabeçalho

int tela_menu_principal(void)
{
    int op;
    system("clear||cls");
    header();
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|             ✦✧✦✧✦    SIG-Aninha - A cigana virtual    ✦✧✦✧✦            |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Módulo Cliente                                 |\n");
    printf("|                      2. Módulo Funcionário                             |\n");
    printf("|                      3. Módulo Agendamento                             |\n");
    printf("|                      4. Módulo Serviços                                |\n");
    printf("|                      5. Módulo Relatório                               |\n");
    printf("|                      6. Informações do Projeto                         |\n");
    printf("|                      0. Sair do Programa                               |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op = escolha();

    return op;
}