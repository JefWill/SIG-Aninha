#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utilitarios.h"
#include "../validacao/validacao.h"
#include "../clientes/cliente.h"
#include "../funcionarios/funcionario.h"

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

void input(char *nome, int tamanho, const char *mensagem)
{
    int tam, i, j = 0;
    char temp[tamanho];
    
    const char *proibidos = "/!@#$%^&*()_+={}|[]:;\"'<>,.?~`-";

    printf("%s\n", mensagem);
    

    if (fgets(nome, tamanho, stdin) == NULL) {
        fprintf(stderr, "Erro na leitura da entrada.\n");
        nome[0] = '\0';
        return;
    }
    
    tam = strlen(nome);
    
    if (tam > 0 && nome[tam - 1] == '\n')
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
        if (strchr(proibidos, nome[i]) == NULL)
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

char* pega_nome_cliente(const char* cpf) {
    FILE *arq_clientes;
    Cliente *clt;
    int encontrado = 0;
    char *nome = (char *)malloc(50 * sizeof(char));

    arq_clientes = fopen("clientes/clientes.dat", "rb");
    if (arq_clientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        free(nome);
        return NULL;
    }

    clt = (Cliente *)malloc(sizeof(Cliente));

    while (fread(clt, sizeof(Cliente), 1, arq_clientes)) {
        if (strcmp(clt->cpf, cpf) == 0 && clt->status == 1) {
            strcpy(nome, clt->nome);
            encontrado = 1;
            break;
        }
    }

    fclose(arq_clientes);
    free(clt);

    if (!encontrado) {
        free(nome);
        return NULL;
    }

    return nome;
}


char* pega_nome_funcionario(const char* cpf) {
    FILE *arq_funcionarios;
    Funcionario *fnc;
    int encontrado = 0;
    char *nome = (char *)malloc(50 * sizeof(char));

    arq_funcionarios = fopen("funcionarios/funcionarios.dat", "rb");
    if (arq_funcionarios == NULL) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        free(nome);
        return NULL;
    }

    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    while (fread(fnc, sizeof(Funcionario), 1, arq_funcionarios)) {
        if (strcmp(fnc->cpf, cpf) == 0 && fnc->status == 1) {
            strcpy(nome, fnc->nome);
            encontrado = 1;
            break;
        }
    }

    fclose(arq_funcionarios);
    free(fnc);

    if (!encontrado) {
        free(nome);
        return NULL;
    }

    return nome;
}

void tranformar_nome_maiusculo(char *str){
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper((unsigned char)str[i]);
        i++;
    }
}