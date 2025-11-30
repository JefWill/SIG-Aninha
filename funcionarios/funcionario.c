#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcionario.h"
#include "../validacao/validacao.h"
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
    printf("|                      6. Excluir Funcionário Fisicamente                |\n");
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
        case 6:
            excluir_funcionario_fisico();
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
    } while (op_funcionario != 0);
}

void cadastrar_funcionario(void)
{
    FILE *arq_funcionarios;
    Funcionario *fnc;

    system("clear||clr");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧   Cadastrar Funcionário   ✧✦✧✦                   |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    arq_funcionarios = fopen("funcionarios/funcionarios.dat", "a+b");
    if (arq_funcionarios == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    fnc = preenche_funcionario();

    fwrite(fnc, sizeof(Funcionario), 1, arq_funcionarios);
    fclose(arq_funcionarios);

    free(fnc);

    printf("funcionário cadastrado com sucesso!\n");
    confirmacao();
}

void buscar_funcionario(void)
{
    FILE *arq_funcionarios;
    Funcionario *fnc;
    char cpf_lido[16];
    int encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                    ✦✧✦✧✦   Buscar Funcionário   ✦✧✦✧✦                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    input(cpf_lido, 16, "Digite o CPF do funcionário para buscar: ");

    arq_funcionarios = fopen("funcionarios/funcionarios.dat", "rb");

    if (arq_funcionarios == NULL)
    {
        printf("Erro na criacao do arquivo\n!");
        return;
    }

    while (fread(fnc, sizeof(Funcionario), 1, arq_funcionarios))
    {
        if ((strcmp(cpf_lido, fnc->cpf) == 0) && (fnc->status == 1))
        {
            encontrado = 1;
            printf("\nFuncionário com CPF %s encontrado!\n", fnc->cpf);
            exibir_funcionario(fnc);

            fclose(arq_funcionarios);
            free(fnc);
            confirmacao();

            return;
        }
    }
    fclose(arq_funcionarios);

    if (!encontrado)
    {
        printf("\nFuncionário não encontrado!\n");
        confirmacao();
    }
}

void listar_funcionarios(void)
{
    FILE *arq_funcionarios;
    Funcionario *fnc;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧✦   Lista de Funcionários   ✦✧✦✧✦                 |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    printf("-------------------------------------------------------------------------------\n");
    printf("| %-12s | %-20s | %-20s | %-8s |\n", 
           "CPF", "Nome", "Cargo", "Status");
    printf("-------------------------------------------------------------------------------\n");

    arq_funcionarios = fopen("funcionarios/funcionarios.dat", "rb");
    if (arq_funcionarios == NULL) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        free(fnc);
        confirmacao();
        return;
    }

    while (fread(fnc, sizeof(Funcionario), 1, arq_funcionarios)) {
        exibir_funcionario(fnc);
    }

    printf("-------------------------------------------------------------------------------\n");
    fclose(arq_funcionarios);
    free(fnc);

    confirmacao();
}

void excluir_funcionario(void)
{
    FILE *arq_funcionarios;
    Funcionario *fnc;
    char cpf_lido[16];
    char opcao [8];
    int encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                   ✦✧✦✧✦  Excluir Funcionário  ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    input(cpf_lido, 16, "Informe o CPF do Funcionário que deseja excluir: ");

    arq_funcionarios = fopen("funcionarios/funcionarios.dat", "r+b");

    if (arq_funcionarios == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        getchar();
        return;
    }

    while (fread(fnc, sizeof(Funcionario), 1, arq_funcionarios) && (!encontrado))
    {
        if ((strcmp(fnc->cpf, cpf_lido) == 0) && (fnc->status == 1))
        {
            encontrado = 1;
            printf("\nFuncionário com CPF %s encontrado!\n", fnc->cpf);
            exibir_funcionario(fnc);

            do {
                input(opcao, 8, "\nConfirmar a exclusão deste funcionário? (S/N): ");
                limpar_espacos_laterais(opcao);
                if (!validar_confirmacao(opcao))
                    printf("Resposta inválida! Digite 'S' para sim ou 'N' para não.\n");
            } while (!validar_confirmacao(opcao));

            if (strcasecmp(opcao, "s") == 0 || strcasecmp(opcao, "sim") == 0)
            {
                fnc->status = 0;
                fseek(arq_funcionarios, (-1) * sizeof(Funcionario), SEEK_CUR);
                fwrite(fnc, sizeof(Funcionario), 1, arq_funcionarios);
                printf("\nFuncionário com CPF %s excluído com sucesso!\n", fnc->cpf);
            }
            else
            {
                printf("\nExclusão Cancelada!\n");
            }
            break;
        }
    }

    fclose(arq_funcionarios);
    free(fnc);

    if (!encontrado)
    {
        printf("\nCPF não encontrado!\n");
    }

    confirmacao();
}

void excluir_funcionario_fisico(void)
{
    FILE *arq_funcionarios;
    FILE *arq_funcionarios2;
    Funcionario *fnc;
    char cpf_lido[16];
    char opcao [8];
    int encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|            ✦✧✦✧✦  Excluir Funcionário Fisicamente  ✦✧✦✧✦          |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    fnc = (Funcionario *)malloc(sizeof(Funcionario));
    input(cpf_lido, 16, "Informe o CPF do funcionário que deseja excluir: ");

    arq_funcionarios = fopen("funcionarios/funcionarios.dat", "rb");
    arq_funcionarios2 = fopen("funcionarios/funcionarios2.dat", "wb");

    if ((arq_funcionarios == NULL) || (arq_funcionarios2 == NULL))
    {
        printf("Erro na abertura ou criação do arquivo!\n");
        free(fnc);
        getchar();
        return;
    }

    while (fread(fnc, sizeof(Funcionario), 1, arq_funcionarios))
    {
        if (strcmp(fnc->cpf, cpf_lido) == 0)
        {
            encontrado = 1;
            printf("\nFuncionário encontrado!\n");
            exibir_funcionario(fnc);

            do {
                input(opcao, 8, "\nConfirmar a exclusão definitiva deste funcionário? (S/N): ");
                limpar_espacos_laterais(opcao);
                if (!validar_confirmacao(opcao))
                    printf("Resposta inválida! Digite 'S' para sim ou 'N' para não.\n");
            } while (!validar_confirmacao(opcao));

            if (strcasecmp(opcao, "s") == 0 || strcasecmp(opcao, "sim") == 0)
            {
                printf("\nFuncionário com CPF %s excluído com sucesso!\n", fnc->cpf);
            }
            else
            {
                printf("\nExclusão cancelada.\n");
                fwrite(fnc, sizeof(Funcionario), 1, arq_funcionarios2);
            }
        }
        else
        {
            fwrite(fnc, sizeof(Funcionario), 1, arq_funcionarios2);
        }
    }

    fclose(arq_funcionarios);
    fclose(arq_funcionarios2);
    free(fnc);

    if (encontrado)
    {
        remove("funcionarios/funcionarios.dat");
        rename("funcionarios/funcionarios2.dat", "funcionarios/funcionarios.dat");
    }
    else
    {
        remove("funcionarios/funcionarios2.dat");
        printf("\nCPF não encontrado!\n");
    }

    confirmacao();
}

void alterar_funcionario(void)
{
    FILE *arq_funcionarios;
    Funcionario *fnc;
    char cpf_lido[16];
    char opcao [8];
    int encontrado = 0;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧✦  Alterar Funcionário  ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    input(cpf_lido, 16, "Informe o CPF do Funcionário que deseja alterar: ");

    arq_funcionarios = fopen("funcionarios/funcionarios.dat", "r+b");

    if (arq_funcionarios == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        getchar();
        return;
    }

    while (fread(fnc, sizeof(Funcionario), 1, arq_funcionarios) && (!encontrado))
    {
        if ((strcmp(fnc->cpf, cpf_lido) == 0) && (fnc->status == 1))
        {
            encontrado = 1;
            printf("\nFuncionário com CPF %s encontrado!\n", fnc->cpf);
            exibir_funcionario(fnc);

            do {
                input(opcao, 8, "\nQuer mesmo alterar os dados deste funcionário? (S/N): ");
                limpar_espacos_laterais(opcao);
                if (!validar_confirmacao(opcao))
                    printf("Resposta inválida! Digite 'S' para sim ou 'N' para não.\n");
            } while (!validar_confirmacao(opcao));

            if (strcasecmp(opcao, "s") == 0 || strcasecmp(opcao, "sim") == 0)
            {
                modulo_alteracao_func(fnc->nome, fnc->cargo);
                fseek(arq_funcionarios, (-1) * sizeof(Funcionario), SEEK_CUR);
                fwrite(fnc, sizeof(Funcionario), 1, arq_funcionarios);
                printf("\nInformações do Funcionário com CPF %s alteradas com sucesso!\n", fnc->cpf);
            }
            else
            {
                printf("\nAlteração Cancelada!\n");
            }
            break;
        }
    }

    fclose(arq_funcionarios);
    free(fnc);

    if (!encontrado)
    {
        printf("CPF não encontrado!\n");
    }

    confirmacao();
}

int menu_alteracao_func(void)
{
    int opcao;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Alterar Nome                                   |\n");
    printf("|                      2. Alterar Cargo                                  |\n");
    printf("|                      0. Salvar e Sair                                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    opcao = escolha();
    return opcao;
}

void modulo_alteracao_func(char *nome, char *cargo)
{
    int opcao;
    do
    {
        opcao = menu_alteracao_func();

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
                input(cargo, 50, "Digite o cargo do funcionário: (Numerologia, Tarot, Signos)");
                if (!validar_cargo(cargo))
                    printf("Cargo inválido! Use apenas 'Numerologia', 'Tarot' ou 'Signos'.\n");
            } while (!validar_cargo(cargo));

            printf("\nCargo atualizado com sucesso!\n");
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

int validar_funcionario_por_cargo(const char *cpf, const char *tipo_consulta)
{
    FILE *arq = fopen("funcionarios/funcionarios.dat", "rb");
    if (!arq)
        return 0;

    Funcionario *fnc = malloc(sizeof(Funcionario));
    if (!fnc)
    {
        fclose(arq);
        return 0;
    }

    int valido = 0;

    while (fread(fnc, sizeof(Funcionario), 1, arq) == 1)
    {
        if (strcasecmp(fnc->cargo, tipo_consulta) == 0 && strcmp(fnc->cpf, cpf) == 0)
        {
            valido = 1;
            break;
        }
    }

    free(fnc);
    fclose(arq);

    return valido;
}

void listar_funcionarios_por_cargo(const char *tipo_consulta, char *cpf_escolhido, char *nome_escolhido)
{
    FILE *arq = fopen("funcionarios/funcionarios.dat", "rb");
    if (!arq)
    {
        printf("Erro ao abrir arquivo de funcionários!\n");
        return;
    }

    Funcionario *fnc = malloc(sizeof(Funcionario));
    if (!fnc)
    {
        printf("Erro de alocação de memória!\n");
        fclose(arq);
        return;
    }

    char cpfs[100][16];
    char nomes[100][100];
    int contador = 0;
    int escolha = 0;
    int encontrado = 0;

    printf("\nFuncionários disponíveis para %s:\n", tipo_consulta);
    printf("--------------------------------------------\n");

    while (fread(fnc, sizeof(Funcionario), 1, arq) == 1)
    {
        if ((strcasecmp(fnc->cargo, tipo_consulta) == 0) && (fnc->status == 1))
        {
            encontrado = 1;
            printf("%d) %s \n", ++contador, fnc->nome);
            strcpy(cpfs[contador - 1], fnc->cpf);
            strcpy(nomes[contador - 1], fnc->nome);
        }
    }

    fclose(arq);

    if (!encontrado)
    {
        printf("\nNenhum funcionário disponível para esse tipo de consulta.\n");
        confirmacao();
        strcpy(cpf_escolhido, "");
        strcpy(nome_escolhido, "");
        free(fnc);
        return;
    }

    printf("\nDigite o número do funcionário escolhido: ");
    scanf("%d", &escolha);
    getchar(); // limpa buffer

    if (escolha < 1 || escolha > contador)
    {
        printf("\nOpção inválida!\n");
        confirmacao();
        strcpy(cpf_escolhido, "");
        strcpy(nome_escolhido, "");
        free(fnc);
        return;
    }

    // Copia os dados do funcionário escolhido
    strcpy(cpf_escolhido, cpfs[escolha - 1]);
    strcpy(nome_escolhido, nomes[escolha - 1]);

    free(fnc);
}

Funcionario *preenche_funcionario(void)
{
    Funcionario *fnc;
    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    ler_cpf_funcionario(fnc->cpf);

    ler_nome(fnc->nome);

    ler_cargo(fnc->cargo);

    fnc->status = 1;
    return fnc;
}

void exibir_funcionario(const Funcionario *fnc)
{

    printf("| %-12s | %-20s | %-12s | %-8d |\n", 
               fnc->cpf, fnc->nome, fnc->cargo, fnc->status);
}


void ler_cpf_funcionario(char *cpf)
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
            cpf_unico = !funcionario_existe(cpf); // Se funcionario_existe = 1 (true), cpf_unico = 0 (false)

            if (!cpf_unico)
            {
                printf("Já existe um funcionário cadastrado com esse CPF!\n");
            }
        }

    } while (!cpf_valido || !cpf_unico); // O loop continua SE (o CPF não for válido) OU (o CPF não for único)
}

void listar_funcionarios_cargo(void)
{
    FILE *arq_funcionarios;
    Funcionario *fnc;
    int encontrado=0;
    char tipo_consulta[20];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|            ✦✧✦✧✦   Lista de Funcionários por Cargo   ✦✧✦✧✦                 |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    fnc = (Funcionario *)malloc(sizeof(Funcionario));

    ler_cargo(tipo_consulta);
    printf("\nLista de funcionários para %s:\n", tipo_consulta);

    

    arq_funcionarios = fopen("funcionarios/funcionarios.dat", "rb");

    while (fread(fnc, sizeof(Funcionario), 1, arq_funcionarios))
    { 
        if((strcasecmp(fnc->cargo, tipo_consulta) == 0) && (fnc->status == 1)){
            if (!encontrado){
                printf("-----------------------------------------------------------------\n");
                printf("| %-12s | %-20s | %-12s | %-8s |\n", 
                        "CPF", "Nome", "Cargo", "Status");
                printf("-----------------------------------------------------------------\n");
            }
            encontrado=1;
            exibir_funcionario(fnc);
        }
    }

    fclose(arq_funcionarios);
    free(fnc);

    confirmacao();
}


FuncionarioDinamico* carregar_func_ativos(void) {

    FILE* arq_funcionarios;
    arq_funcionarios = fopen("funcionarios/funcionarios.dat", "rb");

    if (arq_funcionarios == NULL) {
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    FuncionarioDinamico* lista = NULL;
    Funcionario temp;

    while (fread(&temp, sizeof(Funcionario), 1, arq_funcionarios) == 1) {
        
        FuncionarioDinamico* novo = malloc(sizeof(FuncionarioDinamico));
        if (!novo) {
            printf("Erro de memória!\n");
            fclose(arq_funcionarios);
            return lista;
        }

        if(temp.status){
            novo->funcionario = temp;
            novo->prox = lista;
            lista = novo;
        }
    }

    fclose(arq_funcionarios);
    return lista;

}