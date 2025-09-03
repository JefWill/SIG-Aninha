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
    printf("| ✦✧✦✧✦ SIG-Aninha - A sigana virtual ✦✧✦✧✦ |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
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