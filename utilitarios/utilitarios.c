#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utilitarios.h"

int tela_menu_principal(void)
{
    int op;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("|   ✦✧✦✧✦ SIG-Aninha - A cigana virtual ✦✧✦✧✦    |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Módulo Cliente                    |\n");
    printf("|           2. Módulo Funcionário                |\n");
    printf("|           3. Módulo Agendamento                |\n");
    printf("|           4. Módulo Serviços                   |\n");
    printf("|           5. Módulo Relatorio                  |\n");
    printf("|           6. Informações                       |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    op = escolha();

    return op;
}

void header(void)
{
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                 |\n");
    printf("|   Universidade Federal do Rio Grande do Norte   |\n");
    printf("|   Centro de Ensino Superior do Seridó           |\n");
    printf("|   Departamento de Computação e Tecnologia       |\n");
    printf("|   Disciplina DCT1106 -- Programação             |\n");
    printf("|   Prof.: Flavius Gorgônio                       |\n");
    printf("|   Projeto: SIG-Aninha - Cigana Virtual          |\n");
    printf("|   Devs: Jaine Souza & Jefferson Willame         |\n");
    printf("|   Since: Ago, 2025                              |\n");
    printf("|                                                 |\n");
}

int escolha(void)
{
    int opcao;
    printf("\n           Escolha a opção desejada: ");
    scanf("%d", &opcao);
    printf("\n");
    getchar();
    return opcao;
}

void input(char *nome, int tamanho, char *mensagem)
{
    int tam;
    printf("%s\n", mensagem);
    fgets(nome, tamanho, stdin);
    tam = strlen(nome);
    nome[tam - 1] = '\0';
}