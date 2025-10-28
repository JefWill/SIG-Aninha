#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utilitarios.h"

int escolha(void)
{
    int opcao;
    int resultado;

    printf("\n           Escolha a opção desejada: ");
    resultado = scanf("%d", &opcao);

    if (resultado != 1)
    {
        printf("\nOpção inválida! Digite apenas números.\n");
        while (getchar() != '\n')
            ;
        return -1;
    }

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

void limpar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void header(void)
{
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|             Universidade Federal do Rio Grande do Norte                |\n");
    printf("|                   Centro de Ensino Superior do Seridó                  |\n");
    printf("|                 Departamento de Computação e Tecnologia                |\n");
    printf("|                   Disciplina DCT1106 -- Programação                    |\n");
    printf("|                       Prof.: Flavius Gorgônio                          |\n");
    printf("|                                                                        |\n");
    printf("|                 Projeto: SIG-Aninha - Cigana Virtual                   |\n");
    printf("|                                                                        |\n");
    printf("|                 Devs: Jaine Souza & Jefferson Willame                  |\n");
    printf("|                         Since: Ago, 2025                               |\n");
    printf("|                                                                        |\n");
}

void confirmacao(void)
{
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}