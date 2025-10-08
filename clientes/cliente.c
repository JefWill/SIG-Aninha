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
    Cliente *clt;

    system("clear||clr");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧   Cadastrar Novo Cliente   ✧✦✧✦                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    arq_clientes = fopen("clientes/clientes.dat", "ab");
    if (arq_clientes == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }
    clt = preenche_cliente();

    fwrite(clt, sizeof(Cliente), 1, arq_clientes);
    fclose(arq_clientes);
    free(clt);

    printf("\nCliente cadastrado com sucesso!\n");
    printf("\n>>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void buscar_cliente(void)
{
    FILE *arq_clientes;
    Cliente clt;
    int encontrado = 0;
    char cpf_lido[15];

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
        printf("Erro na abertura do arquivo!\n");
        getchar();
        return;
    }

    while (fscanf(arq_clientes, "%[^;];%[^;];%[^;];%[^\n]\n",
                  clt.cpf, clt.nome, clt.data_nascimento, clt.telefone) == 4)
    {
        if (strcmp(clt.cpf, cpf_lido) == 0)
        {
            encontrado = 1;
            printf("\nCliente com CPF %s encontrado!\n", clt.cpf);
            printf("CPF: %s\n", clt.cpf);
            printf("Nome: %s\n", clt.nome);
            printf("Data de Nascimento: %s\n", clt.data_nascimento);
            printf("Telefone: %s\n", clt.telefone);
            printf("\nPressione enter para continuar...");
            fclose(arq_clientes);
            getchar();

            return;
        }
    }

    fclose(arq_clientes);

    if (!encontrado)
    {
        printf("\nCliente nao encontrado!\n");
        printf("\n>>> Tecle <ENTER> para continuar... <<<\n");
        getchar();
    }
}

void listar_clientes(void)
{
    FILE *arq_clientes;
    Cliente clt;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Lista de Clientes   ✦✧✦✧✦                      |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Lista de clientes: \n");
    printf("---------------------------------------\n");
    arq_clientes = fopen("clientes/clientes.csv", "rt");

    while (fscanf(arq_clientes, "%[^;];%[^;];%[^;];%[^\n]\n", clt.cpf, clt.nome, clt.data_nascimento, clt.telefone) == 4)
    {
        printf("CPF: %s\n", clt.cpf);
        printf("Nome: %s\n", clt.nome);
        printf("Data de Nascimento: %s\n", clt.data_nascimento);
        printf("Telefone: %s\n", clt.telefone);
        printf("---------------------------------------\n");
    }

    fclose(arq_clientes);
    printf("\n>>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void excluir_cliente(void)
{
    FILE *arq_clientes;
    FILE *arq_clientes2;
    Cliente clt;
    char opcao;
    int encontrado = 0;
    char cpf_lido[15];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      ✦✧✦✧✦  Excluir Cliente  ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf_lido, 15, "Informe o CPF do cliente que deseja excluir: ");
    arq_clientes = fopen("clientes/clientes.csv", "rt");
    arq_clientes2 = fopen("clientes/clientes2.csv", "wt");

    if (arq_clientes == NULL || arq_clientes2 == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        getchar();
        return;
    }

    while (fscanf(arq_clientes, "%14[^;];%49[^;];%11[^;];%19[^\n]\n",
                  clt.cpf, clt.nome, clt.data_nascimento, clt.telefone) == 4)
    {
        if (strcmp(clt.cpf, cpf_lido) == 0)
        {
            encontrado = 1;
            printf("\nCliente com CPF %s encontrado!\n", clt.cpf);
            printf("CPF: %s\n", clt.cpf);
            printf("Nome: %s\n", clt.nome);
            printf("Data de Nascimento: %s\n", clt.data_nascimento);
            printf("Telefone: %s\n", clt.telefone);

            printf("\nConfirma exclusão do cliente com CPF %s? (S/N): ", clt.cpf);
            scanf(" %c", &opcao);
            getchar();

            if (opcao == 'S' || opcao == 's')
            {
                printf("\ncliente com CPF %s excluído com sucesso!\n", clt.cpf);
            }
            else
            {
                printf("Exclusão Cancelada!");
                fprintf(arq_clientes2, "%s;", clt.cpf);
                fprintf(arq_clientes2, "%s;", clt.nome);
                fprintf(arq_clientes2, "%s;", clt.data_nascimento);
                fprintf(arq_clientes2, "%s\n", clt.telefone);
            }
        }
        else
        {
            fprintf(arq_clientes2, "%s;", clt.cpf);
            fprintf(arq_clientes2, "%s;", clt.nome);
            fprintf(arq_clientes2, "%s;", clt.data_nascimento);
            fprintf(arq_clientes2, "%s\n", clt.telefone);
        }
    }

    fclose(arq_clientes);
    fclose(arq_clientes2);

    if (encontrado)
    {
        remove("clientes/clientes.csv");
        rename("clientes/clientes2.csv", "clientes/clientes.csv");
    }
    else
    {
        printf("CPF não encontrado!");
    }

    printf("\n\n           Pressione a tecla ENTER para retornar ao menu...");
    getchar();
}

void alterar_cliente(void)
{
    FILE *arq_clientes;
    FILE *arq_clientes2;
    Cliente clt;
    char opcao;
    int encontrado = 0;
    char cpf_lido[15];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                     ✦✧✦✧✦  Alterar Cliente  ✦✧✦✧✦                      |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf_lido, 15, "Informe o CPF:");

    arq_clientes = fopen("clientes/clientes.csv", "rt");
    arq_clientes2 = fopen("clientes/clientes2.csv", "wt");

    if (arq_clientes == NULL || arq_clientes2 == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        getchar();
        return;
    }

    while (fscanf(arq_clientes, "%14[^;];%49[^;];%11[^;];%19[^\n]\n",
                  clt.cpf, clt.nome, clt.data_nascimento, clt.telefone) == 4)
    {
        if (strcmp(clt.cpf, cpf_lido) == 0)
        {
            encontrado = 1;
            printf("\nCliente com CPF %s encontrado!\n", clt.cpf);
            printf("CPF: %s\n", clt.cpf);
            printf("Nome: %s\n", clt.nome);
            printf("Data de Nascimento: %s\n", clt.data_nascimento);
            printf("Telefone: %s\n", clt.telefone);

            printf("\nConfirma alteração do cliente com CPF %s? (S/N): ", clt.cpf);
            scanf(" %c", &opcao);
            getchar();

            if (opcao == 'S' || opcao == 's')
            {
                modulo_alteracao(clt.nome, clt.data_nascimento, clt.telefone);

                fprintf(arq_clientes2, "%s;%s;%s;%s\n", clt.cpf, clt.nome, clt.data_nascimento, clt.telefone);
                printf("\nInformações do Cliente com CPF %s alteradas com sucesso!\n", clt.cpf);
            }
            else
            {
                printf("\nAlteração Cancelada!\n");
                fprintf(arq_clientes2, "%s;%s;%s;%s\n", clt.cpf, clt.nome, clt.data_nascimento, clt.telefone);
            }
        }
        else
        {
            fprintf(arq_clientes2, "%s;%s;%s;%s\n", clt.cpf, clt.nome, clt.data_nascimento, clt.telefone);
        }
    }

    fclose(arq_clientes);
    fclose(arq_clientes2);

    if (encontrado)
    {
        remove("clientes/clientes.csv");
        rename("clientes/clientes2.csv", "clientes/clientes.csv");
    }
    else
    {
        remove("clientes/clientes2.csv");
        printf("CPF não encontrado!\n");
    }

    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}

int menu_alteracao(void)
{
    int opcao;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Alterar Nome                                   |\n");
    printf("|                      2. Alterar Data de Nascimento                     |\n");
    printf("|                      3. Alterar Telefone                               |\n");
    printf("|                      0. Salvar e Sair                                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    opcao = escolha();
    return opcao;
}

void modulo_alteracao(char *nome, char *data_nascimento, char *telefone)
{
    int opcao;
    do
    {
        opcao = menu_alteracao();

        switch (opcao)
        {
        case 1:
            input(nome, 50, "Digite o nome: ");
            printf("\nNome atualizado com sucesso!\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        case 2:
            input(data_nascimento, 12, "Digite sua data de nascimento (DD/MM/AAAA): ");
            printf("\nData de nascimento atualizada com sucesso!\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
            break;
        case 3:
            input(telefone, 20, "Digite o telefone: ");
            printf("\nTelefone atualizado com sucesso!\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
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
    } while (opcao != 0);
}

Cliente *preenche_cliente(void)
{
    Cliente *clt;
    clt = (Cliente *)malloc(sizeof(Cliente));
    input(clt->cpf, 15, "Digite o CPF: ");

    input(clt->nome, 50, "Digite o nome: ");

    input(clt->data_nascimento, 12, "Digite sua data de nascimento (DD/MM/AAAA): ");

    input(clt->telefone, 20, "Digite o telefone: ");
    clt->status = 1;
    return clt;
}