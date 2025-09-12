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
        default:
            printf("                Opção inválida!\n");
            getchar();
            break;
        }
    } while (op_cliente != 0);
}

void cadastrar_cliente(void)
{
    char cpf[15];
    char nome[50];
    char data_nascimento[12];
    system("clear||clr");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧   Cadastrar Novo Cliente   ✧✦✧✦                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf, 15, "insira seu cpf");
    input(nome, 50, "Digite o seu nome: ");
    input(data_nascimento, 12, "Digite sua data de nascimento (DD/MM/AAAA): ");
    printf("cliente cadastrado com sucesso!\n");
    printf("Nome: %s.\nCPF: %s.\nData nascimento: %s.", nome, cpf, data_nascimento);
    printf("\nPressione Enter para continuar");
    getchar();
}

void buscar_cliente(void)
{
    char cpf[15];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                     ✦✧✦✧✦   Buscar Cliente   ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Digite o CPF do cliente para buscar: ");
    scanf("%s", cpf);

    printf("\nCliente com CPF %s encontrado!\n", cpf);
    printf("(aqui seriam exibidos os dados detalhados)\n\n");

    printf("\n\n           Pressione a tecla ENTER para retornar ao menu...");
    getchar();
    getchar();
}

void listar_clientes(void)
{
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Lista de Clientes   ✦✧✦✧✦                      |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("[ Lista de clientes exibida.\n");
    printf("Pressione ENTER para continuar...");
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