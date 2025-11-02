#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"
#include "../utilitarios/utilitarios.h"
#include "../validacao/validacao.h"

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
    printf("|                      6. Excluir Cliente Fisicamente                    |\n");
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
        case 6:
            excluir_cliente_fisico();
            break;
        case 0:
            printf("           Voltando ao menu principal...\n");
            getchar();
            break;
        case -1:
            confirmacao();
            break;
        default:
            printf("                Opção Inexistente!\n");
            confirmacao();
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

    clt = (Cliente *)malloc(sizeof(Cliente));

    arq_clientes = fopen("clientes/clientes.dat", "a+b");
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
    confirmacao();
}

void buscar_cliente(void)
{
    FILE *arq_clientes;
    Cliente *clt;
    int encontrado = 0;
    char cpf_lido[15];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                     ✦✧✦✧✦   Buscar Cliente   ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    clt = (Cliente *)malloc(sizeof(Cliente));

    input(cpf_lido, 16, "Digite o CPF do cliente para buscar: ");

    arq_clientes = fopen("clientes/clientes.dat", "rb");
    if (arq_clientes == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        getchar();
        return;
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes))
    {
        if ((strcmp(cpf_lido, clt->cpf) == 0) && (clt->status == 1))
        {
            encontrado = 1;
            printf("\nCliente com CPF %s encontrado!\n", clt->cpf);
            exibir_cliente(clt);
            confirmacao();
            fclose(arq_clientes);
            free(clt);

            return;
        }
    }
    fclose(arq_clientes);

    if (!encontrado)
    {
        printf("\n      Cliente não encontrado!\n");
        confirmacao();
    }
}

void listar_clientes(void)
{
    FILE *arq_clientes;
    Cliente *clt;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Lista de Clientes   ✦✧✦✧✦                      |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    clt = (Cliente *)malloc(sizeof(Cliente));

    printf("Lista de clientes: \n");
    printf("---------------------------------------\n");
    arq_clientes = fopen("clientes/clientes.dat", "rb");

    while (fread(clt, sizeof(Cliente), 1, arq_clientes))
    {
        exibir_cliente(clt);
        printf("---------------------------------------\n");
    }

    fclose(arq_clientes);
    free(clt);

    confirmacao();
}

void excluir_cliente(void)
{
    FILE *arq_clientes;
    Cliente *clt;
    char opcao[8];
    int encontrado;
    char cpf_lido[16];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      ✦✧✦✧✦  Excluir Cliente  ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    clt = (Cliente *)malloc(sizeof(Cliente));
    input(cpf_lido, 16, "Informe o CPF do cliente que deseja excluir: ");

    encontrado = 0;
    arq_clientes = fopen("clientes/clientes.dat", "r+b");

    if (arq_clientes == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        getchar();
        return;
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes) && (!encontrado))
    {
        if ((strcmp(clt->cpf, cpf_lido) == 0) && (clt->status == 1))
        {
            encontrado = 1;
            printf("\nCliente com CPF %s encontrado!\n", clt->cpf);
            exibir_cliente(clt);

            do
            {
                input(opcao, 8, "\nConfirmar a exclusão deste cliente? (S/N): ");
                if (!validar_confirmacao(opcao))
                    printf("Resposta inválida! Digite 'S' para sim ou 'N' para não.\n");
            } while (!validar_confirmacao(opcao));

            if (validar_confirmacao(opcao))
            {
                clt->status = 0;
                fseek(arq_clientes, (-1) * sizeof(Cliente), SEEK_CUR);
                fwrite(clt, sizeof(Cliente), 1, arq_clientes);
                printf("\nCliente com CPF %s excluído com sucesso!\n", clt->cpf);
            }
            else
            {
                printf("\nExclusão Cancelada!\n");
            }
            break;
        }
    }
    fclose(arq_clientes);
    free(clt);

    if (!encontrado)
    {
        printf("\nCPF não encontrado!\n");
    }

    confirmacao();
}

void excluir_cliente_fisico(void)
{
    FILE *arq_clientes;
    FILE *arq_clientes2;
    Cliente *clt;
    char opcao[8];
    int encontrado = 0;
    char cpf_lido[16];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|              ✦✧✦✧✦  Excluir Cliente Fisicamente  ✦✧✦✧✦            |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    clt = (Cliente *)malloc(sizeof(Cliente));
    input(cpf_lido, 16, "Informe o CPF do cliente que deseja excluir: ");

    arq_clientes = fopen("clientes/clientes.dat", "rb");
    arq_clientes2 = fopen("clientes/clientes2.dat", "wb");

    if ((arq_clientes == NULL) || (arq_clientes2 == NULL))
    {
        printf("Erro na criação do arquivo!\n");
        free(clt);
        getchar();
        return;
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes))
    {
        if ((strcmp(clt->cpf, cpf_lido) == 0))
        {
            encontrado = 1;
            printf("\nCliente com CPF %s encontrado!\n", clt->cpf);
            exibir_cliente(clt);

            do
            {
                input(opcao, 8, "\nConfirmar a exclusão definitiva deste cliente? (S/N): ");
                if (!validar_confirmacao(opcao))
                    printf("Resposta inválida! Digite 'S' para sim ou 'N' para não.\n");
            } while (!validar_confirmacao(opcao));

            if (validar_confirmacao(opcao))
            {
                printf("\nCliente com CPF %s excluído com sucesso!\n", clt->cpf);
            }
            else
            {
                printf("\n        Exclusão cancelada!\n");
                fwrite(clt, sizeof(Cliente), 1, arq_clientes2);
            }
        }
        else
        {
            fwrite(clt, sizeof(Cliente), 1, arq_clientes2);
        }
    }

    fclose(arq_clientes);
    fclose(arq_clientes2);
    free(clt);

    if (encontrado)
    {
        remove("clientes/clientes.dat");
        rename("clientes/clientes2.dat", "clientes/clientes.dat");
    }
    else
    {
        remove("clientes/clientes2.dat");
        printf("CPF não encontrado!\n");
    }

    confirmacao();
}

void alterar_cliente(void)
{
    FILE *arq_clientes;
    Cliente *clt;
    char opcao[8];
    int encontrado = 0;
    char cpf_lido[16];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                     ✦✧✦✧✦  Alterar Cliente  ✦✧✦✧✦                      |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    clt = (Cliente *)malloc(sizeof(Cliente));
    input(cpf_lido, 16, "Informe o CPF:");

    arq_clientes = fopen("clientes/clientes.dat", "r+b");

    if (arq_clientes == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        getchar();
        return;
    }

    while (fread(clt, sizeof(Cliente), 1, arq_clientes) && (!encontrado))
    {
        if ((strcmp(clt->cpf, cpf_lido) == 0) && (clt->status == 1))
        {
            encontrado = 1;
            printf("\nCliente com CPF %s encontrado!\n", clt->cpf);
            exibir_cliente(clt);

            do
            {
                input(opcao, 8, "\nQuer mesmo alterar os dados deste cliente? (S/N): ");
                if (!validar_confirmacao(opcao))
                    printf("Resposta inválida! Digite 'S' para sim ou 'N' para não.\n");
            } while (!validar_confirmacao(opcao));

            if (validar_confirmacao(opcao))
            {
                modulo_alteracao(clt->nome, clt->data_nascimento, clt->telefone);
                fseek(arq_clientes, (-1) * sizeof(Cliente), SEEK_CUR);
                fwrite(clt, sizeof(Cliente), 1, arq_clientes);
                printf("\nInformações do Cliente com CPF %s alteradas com sucesso!\n", clt->cpf);
            }
            else
            {
                printf("\nAlteração Cancelada!\n");
            }
            break;
        }
    }

    fclose(arq_clientes);
    free(clt);

    if (!encontrado)
    {
        printf("CPF não encontrado!\n");
    }

    confirmacao();
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
            do
            {
                input(nome, 50, "Digite o nome: ");
                if (!validar_nome(nome))
                    printf("Nome inválido! Use apenas letras.\n");
            } while (!validar_nome(nome));

            printf("\nNome atualizado com sucesso!\n");
            confirmacao();
            break;
        case 2:
            do
            {
                input(data_nascimento, 12, "Digite sua data de nascimento (DD/MM/AAAA): ");
                if (!validar_data(data_nascimento))
                    printf("Data inválida! Use o formato DD/MM/AAAA.\n");
            } while (!validar_data(data_nascimento));

            printf("\nData de nascimento atualizada com sucesso!\n");
            confirmacao();
            break;
        case 3:
            do
            {
                input(telefone, 20, "Digite o telefone: ");
                if (!validar_telefone(telefone))
                    printf("Telefone inválido! Digite um telefone válido.\n");
            } while (!validar_telefone(telefone));

            printf("\nTelefone atualizado com sucesso!\n");
            confirmacao();
            break;
        case 0:
            printf("           Voltando ao menu principal...\n");
            getchar();
            break;
        case -1:
            confirmacao();
            break;
        default:
            printf("                Opção Inexistente!\n");
            confirmacao();
            break;
        }
    } while (opcao != 0);
}

Cliente *preenche_cliente(void)
{
    Cliente *clt;
    clt = (Cliente *)malloc(sizeof(Cliente));

    ler_cpf_cliente(clt->cpf);

    ler_nome(clt->nome);

    ler_data(clt->data_nascimento);

    ler_telefone(clt->telefone);

    clt->status = 1;
    return clt;
}

void exibir_cliente(const Cliente *clt)
{
    printf("CPF: %s\n", clt->cpf);
    printf("Nome: %s\n", clt->nome);
    printf("Data de Nascimento: %s\n", clt->data_nascimento);
    printf("Telefone: %s\n", clt->telefone);
    printf("Status: %d\n", clt->status);
}

void ler_cpf_cliente(char *cpf)
{
    int cpf_valido = 0;
    int cpf_unico = 0;

    do
    {
        input(cpf, 16, "Digite o CPF: ");
        cpf_valido = validar_cpf(cpf);

        if (!cpf_valido)
        {
            printf("CPF inválido! Digite um CPF válido.\n");
            cpf_unico = 0;
        }
        else
        {
            cpf_unico = !cliente_existe(cpf); // Se cliente_existe = 1 (true), cpf_unico = 0 (false)

            if (!cpf_unico)
            {
                printf("Já existe um cliente cadastrado com esse CPF!\n");
            }
        }

    } while (!cpf_valido || !cpf_unico); // O loop continua SE (o CPF não for válido) OU (o CPF não for único)
}
