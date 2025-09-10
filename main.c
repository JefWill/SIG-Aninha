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

#include "informacoes.h"
#include "relatorio.h"
#include "servicos.h"
#include "agendamento.h"
#include "cliente.h"
#include "funcionario.h"
#include "utilitarios.h"

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
            tela_menu_informacoes();
            break;
        case 0:
            printf("Encerrando o sistema... Até logo!\n");
            break;

        default:
            printf("\nOpção inválida! Tente novamente.\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        }

    } while (op != 0);

    return 0;
}
