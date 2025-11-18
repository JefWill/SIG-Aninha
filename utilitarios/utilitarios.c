#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utilitarios.h"
#include "../validacao/validacao.h"

void limpar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int escolha(void)
{
    int opcao;
    int resultado;

    printf("\n           Escolha a opção desejada: ");
    resultado = scanf("%d", &opcao);

    if (resultado != 1)
    {
        printf("\nOpção inválida! Digite apenas números.\n");
        limpar_buffer();
        return -1;
    }

    limpar_buffer();
    return opcao;
}

void input(char *nome, int tamanho, char *mensagem)
{
    int tam, i, j = 0;
    char temp[tamanho];

    printf("%s\n", mensagem);
    fgets(nome, tamanho, stdin);
    tam = strlen(nome);


    if (nome[tam - 1] == '\n')
    {
        nome[tam - 1] = '\0';
        tam--;
    }
    else
    {
        limpar_buffer();
    }


    for (i = 0; i < tam; i++)
    {
        if (isalnum(nome[i]) || isspace(nome[i]))
        {
            temp[j++] = nome[i];
        }
    }
    temp[j] = '\0';

    strcpy(nome, temp);
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

void ler_nome(char *nome){
    do
    {
        input(nome, 50, "Digite o nome: ");
        if (!validar_nome(nome))
            printf("Nome inválido! Use apenas letras.\n");
    } while (!validar_nome(nome));
}

void ler_data_nascimento(char *data_nascimento){
    do
    {
        input(data_nascimento, 12, "Digite sua data de nascimento (DD/MM/AAAA): ");
        if (!validar_data(data_nascimento))
            printf("Data inválida! Use o formato DD/MM/AAAA.\n");
    } while (!validar_data(data_nascimento));
}

void ler_data(char *data){
    do
    {
        input(data, 12, "Digite sua data (DD/MM/AAAA): ");
        if (!validar_data(data))
            printf("Data inválida! Use o formato DD/MM/AAAA.\n");
    } while (!validar_data(data));
}

void ler_telefone(char *telefone){
    do
    {
        input(telefone, 20, "Digite o telefone com DDD: EX: (84) 99981-1234 ");
        if (!validar_telefone(telefone))
            printf("Telefone inválido! Digite um telefone válido. Não esqueça do DDD.\n");
    } while (!validar_telefone(telefone));
}

void ler_cargo(char *cargo)
{
    do
    {
        input(cargo, 50, "Digite o cargo do funcionário: (Numerologia, Tarot, Signos)");
        if (!validar_cargo(cargo))
            printf("Cargo inválido! Use apenas 'Numerologia', 'Tarot' ou 'Signos'.\n");
    } while (!validar_cargo(cargo));
}

void ler_tipo(char *tipo)
{
    do
    {
        input(tipo, 50, "Digite o tipo de consulta: (Numerologia, Tarot, Signos)");
        if (!validar_cargo(tipo))
            printf("Tipo inválido! Use apenas 'Numerologia', 'Tarot' ou 'Signos'.\n");
    } while (!validar_cargo(tipo));
}

void ler_ddd(char *ddd)
{
    do
    {
        input(ddd, 5, "Digite o DDD Ex: 84 : ");
        if (!validar_ddd(ddd))
            printf("DDD inválido! Digite um DDD válido.\n");
    } while (!validar_ddd(ddd));
}

void limpar_espacos_laterais(char *str)
{
    int len = strlen(str);
    int inicio = 0;
    int fim = len - 1;

    // Acha o primeiro caractere que NÃO é espaço (início)
    while (inicio < len && isspace(str[inicio]))
    {
        inicio++;
    }

    // Acha o último caractere que NÃO é espaço (fim)
    while (fim >= inicio && isspace(str[fim]))
    {
        fim--;
    }

    // Move a string "limpa" para o início
    int i;
    for (i = 0; i <= (fim - inicio); i++)
    {
        str[i] = str[inicio + i];
    }

    // 4. Coloca o terminador nulo no novo final
    str[i] = '\0';
}