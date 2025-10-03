#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionario.h"
#include "../utilitarios/utilitarios.h"

//// FUNCIONARIO /////
int tela_menu_funcionario(void)
{
    int op_funcionario;

    system("clear||cls");
    header();
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|               ✦✧✦✧✦  SIG-Aninha - Módulo Funcionário  ✦✧✦✧✦            |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Cadastrar Funcionário                          |\n");
    printf("|                      2. Buscar Funcionário                             |\n");
    printf("|                      3. Listar Funcionários                            |\n");
    printf("|                      4. Atualizar Funcionário                          |\n");
    printf("|                      5. Excluir Funcionário                            |\n");
    printf("|                      0. Retornar ao Menu Principal                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_funcionario = escolha();

    return op_funcionario;
}

void modulo_funcionario(void)
{
    int op_funcionario;
    do
    {
        op_funcionario = tela_menu_funcionario();

        switch (op_funcionario)
        {
        case 1:
            cadastrar_funcionario();
            break;
        case 2:
            buscar_funcionario();
            break;
        case 3:
            listar_funcionarios();
            break;
        case 4:
            alterar_funcionario();
            break;
        case 5:
            excluir_funcionario();
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
            printf("         >>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        }
    } while (op_funcionario != 0);
}

void cadastrar_funcionario(void)
{
    FILE *arq_funcionarios;
    Funcionario fnc;

    system("clear||clr");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧   Cadastrar Funcionário   ✧✦✧✦                   |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(fnc.cpf, 15, "Informe o CPF do funcionário: ");
    input(fnc.nome, 50, "Digite o nome do funcionário: ");
    input(fnc.cargo, 50, "Digite o cargo do funcionário: ");

    arq_funcionarios = fopen("funcionarios/funcionarios.csv", "at");
    if (arq_funcionarios == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    fprintf(arq_funcionarios, "%s;", fnc.cpf);
    fprintf(arq_funcionarios, "%s;", fnc.nome);
    fprintf(arq_funcionarios, "%s\n", fnc.cargo);
    fclose(arq_funcionarios);

    printf("funcionário cadastrado com sucesso!\n");
    printf("Nome: %s.\nCPF: %s.\nCargo: %s.", fnc.nome, fnc.cpf, fnc.cargo);
    printf("\nPressione Enter para continuar");
    getchar();
}

void buscar_funcionario(void)
{
    FILE *arq_funcionarios;
    Funcionario fnc;
    int encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                    ✦✧✦✧✦   Buscar Funcionário   ✦✧✦✧✦                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(fnc.cpf_lido,15, "Digite o CPF do funcionário para buscar: ");

    arq_funcionarios = fopen("funcionarios/funcionarios.csv", "rt");
    if (arq_funcionarios == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    while (fscanf(arq_funcionarios, "%[^;];%[^;];%[^\n]\n",
                  fnc.cpf, fnc.nome, fnc.cargo) == 3)
    {
        if (strcmp(fnc.cpf, fnc.cpf_lido) == 0)
        {
            encontrado = 1;
            printf("\nFuncionário com CPF %s encontrado!\n", fnc.cpf);
            printf("CPF: %s\n", fnc.cpf);
            printf("Nome: %s\n", fnc.nome);
            printf("Cargo: %s\n", fnc.cargo);
            printf("Pressione enter para continuar...");
            getchar();
            fclose(arq_funcionarios);

            return;
        }
    }
    fclose(arq_funcionarios);

    if (!encontrado){
        printf("Funcionário não encontrado!");
        printf("\n\n           Pressione a tecla ENTER para retornar ao menu...");
        getchar();
    }
}

void listar_funcionarios(void)
{
    FILE *arq_funcionarios;
    Funcionario fnc;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧✦   Lista de Funcionários   ✦✧✦✧✦                 |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Lista de funcionários: \n");
    printf("------------------------------------\n");
    arq_funcionarios = fopen("funcionarios/funcionarios.csv", "rt");

    while (fscanf(arq_funcionarios, "%[^;];%[^;];%[^\n]\n", fnc.cpf, fnc.nome, fnc.cargo) == 3)
    {
        printf("CPF: %s\n", fnc.cpf);
        printf("Nome: %s\n", fnc.nome);
        printf("Cargo: %s\n", fnc.cargo);
        printf("------------------------------------\n");
    }

    fclose(arq_funcionarios);
    printf("\n>>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void excluir_funcionario(void)
{
    FILE *arq_funcionarios;
    FILE *arq_funcionarios2;
    char cpf[15];
    char nome[50];
    char cargo[50];
    char cpf_lido[15];
    char opcao;
    int encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                   ✦✧✦✧✦  Excluir Funcionário  ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf_lido, 15, "Informe o CPF do Funcionário que deseja excluir: ");
    arq_funcionarios = fopen("funcionarios/funcionarios.csv", "rt");
    arq_funcionarios2 = fopen("funcionarios/funcionarios2.csv", "wt");

    if (arq_funcionarios == NULL || arq_funcionarios2 == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        getchar();
        return;
    }

    while (fscanf(arq_funcionarios, "%14[^;];%49[^;];%49[^\n]\n",
                  cpf, nome, cargo) == 3)
    {
        if (strcmp(cpf, cpf_lido) == 0)
        {
            encontrado = 1;
            printf("\nFuncionário com CPF %s encontrado!\n", cpf);
            printf("CPF: %s\n", cpf);
            printf("Nome: %s\n", nome);
            printf("Cargo: %s\n", cargo);

            printf("\nConfirma exclusão do Funcionário com CPF %s? (S/N): ", cpf);
            scanf(" %c", &opcao);
            getchar();

            if (opcao == 'S' || opcao == 's')
            {
                printf("\nFuncionário com CPF %s excluído com sucesso!\n", cpf);
            }
            else
            {
                printf("Exclusão Cancelada!\n");
                fprintf(arq_funcionarios2, "%s;", cpf);
                fprintf(arq_funcionarios2, "%s;", nome);
                fprintf(arq_funcionarios2, "%s\n", cargo);
            }
        }
        else
        {
            fprintf(arq_funcionarios2, "%s;", cpf);
            fprintf(arq_funcionarios2, "%s;", nome);
            fprintf(arq_funcionarios2, "%s\n", cargo);
        }
    }

    fclose(arq_funcionarios);
    fclose(arq_funcionarios2);

    if (encontrado)
    {
        remove("funcionarios/funcionarios.csv");
        rename("funcionarios/funcionarios2.csv", "funcionarios/funcionarios.csv");
    }
    else
    {
        remove("funcionarios/funcionarios2.csv");
        printf("CPF não encontrado!\n");
    }

    printf("\n\n           Pressione a tecla ENTER para retornar ao menu...");
    getchar();
}

void alterar_funcionario(void)
{
    char cpf[15];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧✦  Alterar Funcionário  ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf, 15, "Informe o CPF do Funcionário que deseja alterar: ");
    printf("\nFuncionário com CPF %s alterado.\n", cpf);
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}