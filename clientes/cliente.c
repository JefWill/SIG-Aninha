#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"
#include "../utilitarios/utilitarios.h"

//////////////////////////////////////////////
///////////// MODULO CLIENTE /////////////////
//////////////////////////////////////////////
int tela_menu_cliente(void)
{
    int op_cliente;
    system("clear||cls");
    header();
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|              ✦✧✦✧✦       SIG-Aninha - Módulo Cliente       ✦✧✦✧✦       |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Cadastrar Novo Cliente                         |\n");
    printf("|                      2. Buscar Cliente por CPF                         |\n");
    printf("|                      3. Listar Todos os Clientes                       |\n");
    printf("|                      4. Atualizar Dados de Cliente                     |\n");
    printf("|                      5. Excluir Cliente do Sistema                     |\n");
    printf("|                      0. Retornar ao Menu Principal                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_cliente = escolha();

    return op_cliente;
}

void modulo_cliente(void)
{
    int op_cliente;
    do
    {
        op_cliente = tela_menu_cliente();

        switch (op_cliente)
        {
        case 1:
            cadastrar_cliente();
            break;
        case 2:
            buscar_cliente();
            break;
        case 3:
            listar_clientes();
            break;
        case 4:
            alterar_cliente();
            break;
        case 5:
            excluir_cliente();
            break;
        case 0:
            printf("           Voltando ao menu principal...\n");
            getchar();
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
    } while (op_cliente != 0);
}

void cadastrar_cliente(void)
{
    FILE *arq_clientes;
    char cpf[15];
    char nome[50];
    char data_nascimento[12];
    char telefone[20];

    system("clear||clr");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧   Cadastrar Novo Cliente   ✧✦✧✦                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf, 15, "Insira seu cpf: ");
    input(nome, 50, "Digite o seu nome: ");
    input(data_nascimento, 12, "Digite sua data de nascimento (DD/MM/AAAA): ");
    input(telefone, 20, "Digite seu telefone: ");

    arq_clientes = fopen("clientes/clientes.csv", "at");
    if (arq_clientes == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    fprintf(arq_clientes, "%s;", cpf);
    fprintf(arq_clientes, "%s;", nome);
    fprintf(arq_clientes, "%s;", data_nascimento);
    fprintf(arq_clientes, "%s\n", telefone);
    fclose(arq_clientes);

    printf("\nCliente cadastrado com sucesso!\n");
    printf("\n>>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void buscar_cliente(void)
{
    FILE *arq_clientes;
    char cpf[15];
    char cpf_lido[15];
    char nome[50];
    char data_nascimento[12];
    char telefone[20];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                     ✦✧✦✧✦   Buscar Cliente   ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf_lido, 15, "Digite o CPF do cliente para buscar: ");

    arq_clientes = fopen("clientes/clientes.csv", "rt");
    if (arq_clientes == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        getchar();
        return;
    }

    while (!feof(arq_clientes))
    {
        fscanf(arq_clientes, "%[^;]", cpf);
        fgetc(arq_clientes);
        fscanf(arq_clientes, "%[^;]", nome);
        fgetc(arq_clientes);
        fscanf(arq_clientes, "%[^;]", data_nascimento);
        fgetc(arq_clientes);
        fscanf(arq_clientes, "%[^\n]", telefone);
        fgetc(arq_clientes);

        if (strcmp(cpf, cpf_lido) == 0)
        {
            printf("\nCliente com CPF %s encontrado!\n", cpf);
            printf("CPF: %s\n", cpf);
            printf("Nome: %s\n", nome);
            printf("Data de Nascimento: %s\n", data_nascimento);
            printf("Telefone: %s\n", telefone);
            printf("Pressione enter para continuar...");
            getchar();
            fclose(arq_clientes);

            return;
        }
    }
    fclose(arq_clientes);
    printf("Cliente não encontrado!");

    printf("\n>>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}

void listar_clientes(void)
{
    FILE *arq_clientes;
    char cpf[15];
    char nome[50];
    char data_nascimento[12];
    char telefone[20];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Lista de Clientes   ✦✧✦✧✦                      |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Lista de clientes: \n");
    printf("---------------------------------------\n");
    arq_clientes = fopen("clientes/clientes.csv", "rt");

    while (fscanf(arq_clientes, "%[^;];%[^;];%[^;];%[^\n]\n", cpf, nome, data_nascimento, telefone) == 4)
    {
        printf("CPF: %s\n", cpf);
        printf("Nome: %s\n", nome);
        printf("Data de Nascimento: %s\n", data_nascimento);
        printf("Telefone: %s\n", telefone);
        prinft("---------------------------------------\n");
    }

    fclose(arq_clientes);
    printf("\n>>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void excluir_cliente(void)
{
    char cpf[15];
    char opcao;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      ✦✧✦✧✦  Excluir Cliente  ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf, 15, "Informe o CPF do cliente que deseja excluir: ");

    printf("\nConfirma exclusão do cliente com CPF %s? (S/N): ", cpf);
    scanf(" %c", &opcao);

    if (opcao == 'S' || opcao == 's')
    {
        printf("\ncliente com CPF %s excluído.\n", cpf);
    }
    else
    {
        printf("\nExclusão cancelada.\n");
    }

    printf("\n\n           Pressione a tecla ENTER para retornar ao menu...");
    getchar();
    getchar();
}

void alterar_cliente(void)
{
    char cpf[15];
    char nome[50];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                     ✦✧✦✧✦  Alterar Cliente  ✦✧✦✧✦                      |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf, 15, "informe o CPF");
    input(nome, 50, "Informe o nome");
    printf("\ncliente com CPF %s alterado.\n", cpf);
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}