#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "informacoes.h"


void tela_menu_informacoes(void)
{
    int op_info = 11;
    while (op_info != 0)
    {
        system("clear||cls");

        printf("\n");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
        printf("|                                                    |\n");
        printf("| ✦✧✦✧✦  SIG-Aninha - Módulo Informações  ✦✧✦✧✦      |\n");
        printf("|                                                    |\n");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
        printf("|                                                    |\n");
        printf("|          1. Informações sobre o Projeto            |\n");
        printf("|          2. Informações sobre a Equipe             |\n");
        printf("|          0. Voltar ao menu principal               |\n");
        printf("|                                                    |\n");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
        op_info = escolha();

        if (op_info == 1)
        {
            tela_sobre();
        }
        else if (op_info == 2)
        {
            tela_equipe();
        }
        else if (op_info == 0)
        {
            printf("Voltando ao menu principal...\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
        }
        else
        {
            printf("\nOpção inválida! Tente novamente.\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
        }
    }
}

void tela_sobre(void)
{
    system("clear||cls");

    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|           ✦✧✦✧✦  SIG-Aninha - Cigana Vitual  ✦✧✦✧✦                  |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|            Universidade Federal do Rio Grande do Norte              |\n");
    printf("|               Centro de Ensino Superior do Seridó                   |\n");
    printf("|             Departamento de Computação e Tecnologia                 |\n");
    printf("|                Disciplina DCT1106 -- Programação                    |\n");
    printf("|                   Professor: Flavius Gorgônio                       |\n");
    printf("|               Projeto: SIG-Aninha: Cigana Virtual                   |\n");
    printf("|           Developed by: Jaine Souza e Jefferson Willame             |\n");
    printf("|                        Since: Ago, 2025                             |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|       O SIG-Aninha é uma cigana virtual criada para auxiliar        |\n");
    printf("|       no atendimento holístico, unindo tecnologia e misticismo.     |\n");
    printf("|                                                                     |\n");
    printf("|       Este sistema oferece funcionalidades como cadastro de         |\n");
    printf("|       clientes, agendamento de consultas e acessos a serviços       |\n");
    printf("|       online como mapa astral, tarot e numerologia.                 |\n");
    printf("|       O sistema também oferece geração de relatórios                |\n");
    printf("|       personalizados sobre clientes e atendimentos, facilitando     |\n");
    printf("|       a análise e acompanhamento dos serviços prestados.            |\n");
    printf("|                                                                     |\n");
    printf("|       Unindo organização e espiritualidade num só lugar.            |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("\n");
    printf("                   >>> Tecle <ENTER> para continuar... <<<            \n");
    getchar();
}

void tela_equipe(void)
{
    system("clear||cls");

    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|           ✦✧✦✧✦  SIG-Aninha - Cigana Vitual  ✦✧✦✧✦                  |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|            Universidade Federal do Rio Grande do Norte              |\n");
    printf("|               Centro de Ensino Superior do Seridó                   |\n");
    printf("|             Departamento de Computação e Tecnologia                 |\n");
    printf("|                Disciplina DCT1106 -- Programação                    |\n");
    printf("|                   Professor: Flavius Gorgônio                       |\n");
    printf("|               Projeto: SIG-Aninha: Cigana Virtual                   |\n");
    printf("|           Developed by: Jaine Souza e Jefferson Willame             |\n");
    printf("|                        Since: Ago, 2025                             |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|                    ✦✧✦✧✦  EQUIPE  ✦✧✦✧✦                             |\n");
    printf("|                                                                     |\n");
    printf("|             Este projeto foi desenvolvido por:                      |\n");
    printf("|                                                                     |\n");
    printf("|             Alun@: Jaine Souza                                      |\n");
    printf("|             Email: jaine.luz.138@ufrn.edu.br                        |\n");
    printf("|             Redes Sociais: @_jaine.souza_                           |\n");
    printf("|             Git: https://github.com/JefWill/SIG-Aninha.git          |\n");
    printf("|                                                                     |\n");
    printf("|             Alun@: Jefferson Willame                                |\n");
    printf("|             Email: jefferson.willame.712@ufrn.edu.br                |\n");
    printf("|             Redes Sociais: @jefferson_willame                       |\n");
    printf("|             Git: https://github.com/JefWill/SIG-Aninha.git          |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("\n");
    printf("                   >>> Tecle <ENTER> para continuar... <<<            \n");
    getchar();
}