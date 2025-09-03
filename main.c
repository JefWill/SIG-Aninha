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

    while (op != 0)
    {
        op = tela_menu_principal();

        if (op == 1)
        {
            modulo_cliente();
        }
        else if (op == 2)
        {
            modulo_funcionario();
        }
        else if (op == 3)
        {
            modulo_agendamentos();
        }
        else if (op == 4)
        {
            modulo_servicos();
        }
        else if (op == 5)
        {
            tela_menu_relatorio();
        }
        else if (op == 6)
        {
            tela_menu_informacoes();
        }
        else if (op == 0)
        {
            printf("Encerrando o sistema... Até logo!\n");
        }
        else
        {
            printf("\nOpção inválida! Tente novamente.\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
        }
    }

    return 0;
}


