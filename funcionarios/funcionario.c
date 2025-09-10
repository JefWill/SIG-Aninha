#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionario.h"
#include "../utilitarios.h"

//// FUNCIONARIO /////
int tela_menu_funcionario(void)
{
    int op_funcionario;

    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                 |\n");
    printf("|   ✦✧✦✧✦ SIG-Aninha - Módulo Funcionário ✦✧✦✧✦   |\n");
    printf("|                                                 |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Cadastrar Funcionário              |\n");
    printf("|           2. Buscar Funcionário                 |\n");
    printf("|           3. Listar Funcionários                |\n");
    printf("|           4. Atualizar Funcionário              |\n");
    printf("|           5. Excluir Funcionário                |\n");
    printf("|           0. Sair                               |\n");
    printf("|                                                 |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_funcionario = escolha();

    return op_funcionario;
}

void modulo_funcionario(void)
{
    int op_funcionario = 11;
    while (op_funcionario != 0)
    {
        op_funcionario = tela_menu_funcionario();

        if (op_funcionario == 1)
        {
            cadastrar_funcionario();
        }
        else if (op_funcionario == 2)
        {
            buscar_funcionario();
        }
        else if (op_funcionario == 3)
        {
            listar_funcionarios();
        }
        else if (op_funcionario == 4)
        {
            alterar_funcionario();
        }
        else if (op_funcionario == 5)
        {
            excluir_funcionario();
        }
        else if (op_funcionario == 0)
        {
            printf("           Voltando ao menu principal...\n");
            getchar();
        }
        else
        {
            printf("                Opção inválida!\n");
            getchar();
        }
    }
}

void cadastrar_funcionario(void)
{
    char cpf[15];
    char nome[50];
    char cargo[50];
    system("clear||clr");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|        ✦✧✦✧  Cadastrar funcionaário ✧✦✧✦       |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    input(cpf, 15, "informe o CPF do funcionário");
    input(nome, 50, "Digite o nome do funcionário: ");
    input(cargo, 50, "Digite o cargo do funcionário");
    printf("funcionário cadastrado com sucesso!\n");
    printf("Nome: %s.\nCPF: %s.\nCargo: %s.", nome, cpf, cargo);
    printf("\nPressione Enter para continuar");
    getchar();
}

void buscar_funcionario(void)
{
    char ID[10];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|        ✦✧✦✧✦  Buscar Funcionário  ✦✧✦✧✦        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Digite o ID do funcionario para buscar: ");
    scanf("%s", ID);

    printf("\nfuncionario com ID %s encontrado!\n", ID);
    printf("(aqui seriam exibidos os dados detalhados)\n\n");

    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}

void listar_funcionarios(void)
{
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|       ✦✧✦✧✦    Listar Funcionários    ✦✧✦✧✦    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("| ID |      NOME      |    CARGO     |\n\n");
    printf("Pressione ENTER para continuar...");
    getchar();
}

void excluir_funcionario(void)
{
    char ID[10];
    char opcao;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|        ✦✧✦✧✦  Excluir Funcionário  ✦✧✦✧✦       |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(ID, 10, "Informe o ID do Funcionário que deseja excluir: ");

    printf("\nConfirma exclusão do Funcionário com ID %s? (S/N): ", ID);
    scanf(" %c", &opcao);

    if (opcao == 'S' || opcao == 's')
    {
        printf("\nFuncionário com ID %s excluído.\n", ID);
    }
    else
    {
        printf("\nExclusão cancelada.\n");
    }

    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}

void alterar_funcionario(void)
{
    char ID[10];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|         ✦✧✦✧✦  Alterar funcionario  ✦✧✦✧✦      |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(ID, 10, "informe o ID\n");
    printf("\nfuncionario com ID %s alterado.\n", ID);
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}
