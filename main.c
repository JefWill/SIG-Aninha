// Universidade Federal do Rio Grande do Norte - UFRN
// Centro de Ensino Superior do Seridó - CERES
// Departamento de Computação e Tecnologia - DCT
// Disciplina DCT1106 - Programação
// Projeto Sistema de Gestão Mística (SIG-Aninha)
// Desenvolvido por: @JaineSouz e @JeffWill - since Ago, 2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assinatura das funções
int tela_menu_principal(void);
int escolha(void);
void input(char *nome, int tamanho, char *mensagem);
void perguntas(void);

void modulo_cliente(void);
void cadastrar_cliente(void);
int tela_menu_cliente(void);
void buscar_cliente(void);
void listar_clientes(void);
void excluir_cliente(void);
void alterar_cliente(void);

int tela_menu_agendamento(void);
void modulo_agendamentos(void);
void agendar_consulta(void);
void atualizar_agendamento(void);
void listar_agendamentos(void);
void buscar_agendamento_por_cpf(void);
void excluir_agendamento(void);

void tela_menu_signos(void);
void tela_menu_tarot(void);
void tela_menu_numerologia(void);
void tela_menu_relatorio(void);
void tela_menu_informacoes(void);
void tela_sobre(void);
void tela_equipe(void);

int main(void)
{
    int op = 10;

    while (op != 0)
    {
        op = tela_menu_principal();

        if (op == 1)
        {
            modulo_cliente();
        }
        else if (op == 2)
        {
            modulo_agendamentos();
        }
        else if (op == 3)
        {
            tela_menu_signos();
        }
        else if (op == 4)
        {
            tela_menu_tarot();
        }
        else if (op == 5)
        {
            tela_menu_numerologia();
        }
        else if (op == 6)
        {
            tela_menu_relatorio();
        }
        else if (op == 7)
        {
            tela_menu_informacoes();
        }
        else if (op == 8)
        {
            perguntas();
        }
        else if (op == 0)
        {
            printf("Encerrando o sistema... Até logo!\n");
        }
        else
        {
            printf("\nOpção inválida! Tente novamente.\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
        }
    }

    return 0;
}

/// FUNÇÕES: ///

int tela_menu_principal(void)
{
    int op; // isso é a variável de opção principal
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧✦ SIG-Aninha - A sigana virtual ✦✧✦✧✦ |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Módulo Cliente                    |\n");
    printf("|           2. Módulo Agendamento                |\n");
    printf("|           3. Módulo Signos                     |\n");
    printf("|           4. Módulo Tarot                      |\n");
    printf("|           5. Módulo Numerologia                |\n");
    printf("|           6. Módulo Relatorio                  |\n");
    printf("|           7. Informações                       |\n");
    printf("|           8. Pergunte á sigana                 |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    op = escolha();

    return op;
}
void perguntas(void)
{
    int continuar = 1;
    while (continuar != 0)
    {
        char *respostas[7] = {"sim", "nao", "talvez"};
        char pergunta[255];
        input(pergunta, 255, "Faça uma pergunta para a sigana (sim ou não)");
        printf("\nsua pergunta foi %s", pergunta);
        printf("\na resposta é: %s", respostas[rand() % 3]);
        printf("\ncontinuar? 1 para sim, 0 para não");
        continuar = escolha();
    }
}
int tela_menu_cliente(void)
{
    int op_cliente; // aqui cria uma variável de opção só pro modulo de cliente
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("|   ✦✧✦✧✦ SIG-Aninha - Módulo Cliente   ✦✧✦✧✦|\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Cadastrar Cliente                 |\n");
    printf("|           2. Buscar cliente                    |\n");
    printf("|           3. Listar Clientes                   |\n");
    printf("|           4. Atualizar Cliente                 |\n");
    printf("|           5. Excluir Cliente                   |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_cliente = escolha();

    return op_cliente;
}

int tela_menu_agendamento(void)
{
    int op_agendamento = 11;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧ SIG-Aninha - Módulo agendamento ✧✦✧✦      |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Agendar consulta                  |\n");
    printf("|           2. Atualizar agendamento             |\n");
    printf("|           3. Listar agendamentos (no dia)      |\n");
    printf("|           4. Buscar agendamento por cliente    |\n");
    printf("|           5. Cancelar agendamento              |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    op_agendamento = escolha();

    return op_agendamento;
}
//////// MODULO CLIENTE ////////

void modulo_cliente(void)
{
    int op_cliente = 11;
    while (op_cliente != 0)
    {
        op_cliente = tela_menu_cliente();

        if (op_cliente == 1)
        {
            cadastrar_cliente();
        }
        else if (op_cliente == 2)
        {
            buscar_cliente();
        }
        else if (op_cliente == 3)
        {
            listar_clientes();
        }
        else if (op_cliente == 4)
        {
            alterar_cliente();
        }
        else if (op_cliente == 5)
        {
            excluir_cliente();
        }
        else if (op_cliente == 0)
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

void cadastrar_cliente(void)
{
    char cpf[15];
    char nome[50];
    char data_nascimento[12];
    system("clear||clr");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|         ✦✧✦✧  Cadastrar Cliente ✧✦✧✦         |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

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
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|       ✦✧✦✧✦  Buscar Cliente  ✦✧✦✧✦             |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Digite o CPF do cliente para buscar: ");
    scanf("%s", cpf);

    printf("\nCliente com CPF %s encontrado!\n", cpf);
    printf("(aqui seriam exibidos os dados detalhados)\n\n");

    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}

void listar_clientes(void)
{
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|     ✦✧✦✧✦     Listar Clientes     ✦✧✦✧✦    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("[ Lista de clientes exibida.\n");
    printf("Pressione ENTER para continuar...");
    getchar();
}

void excluir_cliente(void)
{
    char cpf[15];
    char opcao;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|        ✦✧✦✧✦  Excluir Cliente  ✦✧✦✧✦       |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

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

    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}

void alterar_cliente(void)
{
    char cpf[15];
    char nome[50];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|        ✦✧✦✧✦  Alterar Cliente  ✦✧✦✧✦       |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(cpf, 15, "informe o CPF");
    input(nome, 50, "Informe o nome");
    printf("\ncliente com CPF %s alterado.\n", cpf);
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}

//////////// MODULO AGENDAMENTO //////////////
void modulo_agendamentos(void)
{
    int op_agendamento = 11;
    while (op_agendamento != 0)
    {
        op_agendamento = tela_menu_agendamento();

        if (op_agendamento == 1)
        {
            agendar_consulta();
        }
        else if (op_agendamento == 2)
        {
            atualizar_agendamento();
        }
        else if (op_agendamento == 3)
        {
            listar_agendamentos();
        }
        else if (op_agendamento == 4)
        {
            buscar_agendamento_por_cpf();
        }
        else if (op_agendamento == 5)
        {
            excluir_agendamento();
        }
        else if (op_agendamento == 0)
        {
            printf("           Voltando ao menu principal...\n");
            getchar();
        }
        else
        {
            printf("                Opção inválida!\n");
            printf("      >>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
        }
    }
}

void agendar_consulta(void)
{
    char cpf[15], nome[100], data[11], horario[6], tipo_consulta[20];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|          ✦✧✦✧ Agendar Consulta ✧✦✧✦          |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    input(cpf, 15, "Digite o CPF do cliente:");
    input(nome, 100, "Digite o nome do cliente:");
    input(tipo_consulta, 20, "Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia):");
    input(data, 11, "Digite a data da consulta (DD/MM/AAAA):");
    input(horario, 6, "Digite o horário da consulta (HH:MM):");

    printf("\n         Consulta agendada com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void atualizar_agendamento(void)
{
    char cpf[15], nome[100], data[11], horario[6], tipo_consulta[20];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|       ✦✧✦✧ Atualizar Agendamento ✧✦✧✦       |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    input(cpf, 15, "Digite o CPF do cliente: ");
    input(nome, 100, "Digite o nome do cliente: ");
    input(tipo_consulta, 20, "Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia): ");
    input(data, 11, "Digite a data da consulta (DD/MM/AAAA): ");
    input(horario, 6, "Digite o horário da consulta: ");

    printf("\n      Agendamento atualizado com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void listar_agendamentos(void)
{
    char data[11];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|         ✦✧✦✧ Listar Agendamentos ✧✦✧✦       |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    printf("Digite a data desejada (dd/mm/aaaa): ");
    scanf("%s", data);
    printf("\nAgendamentos para a data %s:\n", data);
    printf("Exibe os agendamentos da data...\n");

    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}

void buscar_agendamento_por_cpf(void)
{
    char cpf[15];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|        ✦✧✦✧ Buscar Agendamento ✧✦✧✦         |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    printf("\nAgendamentos do cliente %s:\n", cpf);
    printf("Exibe os agendamentos do cliente...\n");

    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}

void excluir_agendamento(void)
{
    char cpf[15];
    char resposta[3];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|        ✦✧✦✧ Excluir Agendamento ✧✦✧✦        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    input(cpf, 15, "Digite o CPF do cliente:");
    input(resposta, 3, "\nDeseja excluir o agendamento do cliente? (S/N)");

    if (resposta[0] == 'S' || resposta[0] == 's')
    {
        printf("\n       Agendamento excluído com sucesso!\n");
    }
    else
    {
        printf("\n              Exclusão cancelada!\n");
    }

    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}

void tela_menu_signos(void)
{
    int op_signos;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧✦   SIG-Aninha - Módulo signos  ✦✧✦✧✦      |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Listar Signos                     |\n");
    printf("|           2. Consultar Signo                   |\n");
    printf("|           3. Consultar Compatibilidade         |\n");
    printf("|           4. Horoscopo do meu Signo            |\n");
    printf("|           5. Calcular Signo                    |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_signos = escolha();
}

void listar_signos(void)
{
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|     ✦✧✦✧✦     Listar Signos     ✦✧✦✧✦    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Existem 12 signos:\n\n");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");
    printf("\n      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
    getchar();
}

void tela_menu_tarot(void)
{
    int op_tarot;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧✦   SIG-Aninha - Módulo tarot   ✦✧✦✧✦      |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Menu Cartas                       |\n");
    printf("|           2. Menu Consultas tarot              |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_tarot = escolha();
}

void tela_menu_numerologia(void)
{
    system("clear||cls");

    int op_num;
    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("| ✦✧✦✧✦  SIG-Aninha - Módulo Numerologia  ✦✧✦✧✦      |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("|          1. Descobrir qual é o seu Número          |\n");
    printf("|          2. Significado dos Números                |\n");
    printf("|          0. Voltar para o menu Principal           |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_num = escolha();
}

void tela_menu_relatorio(void)
{
    system("clear||cls");

    int op_rel;
    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("| ✦✧✦✧✦  SIG-Aninha - Módulo Relatórios  ✦✧✦✧✦       |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("|    1. Relatório de Clientes Cadastrados            |\n");
    printf("|    2. Relatório de Atendimentos Realizados         |\n");
    printf("|    3. Relatório por Tipo de Serviço (Tarot,        |\n");
    printf("|    Signos, Numerologia)                            |\n");
    printf("|    4. Relatório de Agendamentos Pendentes          |\n");
    printf("|    5. Relatório de Clientes Atendidos por Período  |\n");
    printf("|    0. Voltar ao Menu Principal                     |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_rel = escolha();
}

void tela_menu_informacoes(void)
{
    int op_info = 11;
    while (op_info != 0)
    {
        system("clear||cls");

        printf("\n");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
        printf("|                                                    |\n");
        printf("| ✦✧✦✧✦  SIG-Aninha - Módulo Informações  ✦✧✦✧✦      |\n");
        printf("|                                                    |\n");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
        printf("|                                                    |\n");
        printf("|          1. Informações sobre o Projeto            |\n");
        printf("|          2. Informações sobre a Equipe             |\n");
        printf("|          0. Voltar ao menu principal               |\n");
        printf("|                                                    |\n");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
        op_info = escolha();

        if (op_info == 1)
        {
            tela_sobre();
        }
        else if (op_info == 2)
        {
            tela_equipe();
        }
        else if (op_info == 0)
        {
            printf("Voltando ao menu principal...\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
        }
        else
        {
            printf("\nOpção inválida! Tente novamente.\n");
            printf(">>> Tecle <ENTER> para continuar... <<<\n");
            getchar();
        }
    }
}

void tela_sobre(void)
{
    system("clear||cls");

    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|           ✦✧✦✧✦  SIG-Aninha - Cigana Vitual  ✦✧✦✧✦                  |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|            Universidade Federal do Rio Grande do Norte              |\n");
    printf("|               Centro de Ensino Superior do Seridó                   |\n");
    printf("|             Departamento de Computação e Tecnologia                 |\n");
    printf("|                Disciplina DCT1106 -- Programação                    |\n");
    printf("|                   Professor: Flavius Gorgônio                       |\n");
    printf("|               Projeto: SIG-Aninha: Cigana Virtual                   |\n");
    printf("|           Developed by: Jaine Souza e Jefferson Willame             |\n");
    printf("|                        Since: Ago, 2025                             |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|       O SIG-Aninha é uma cigana virtual criada para auxiliar        |\n");
    printf("|       no atendimento holístico, unindo tecnologia e misticismo.     |\n");
    printf("|                                                                     |\n");
    printf("|       Este sistema oferece funcionalidades como cadastro de         |\n");
    printf("|       clientes, agendamento de consultas e acessos a serviços       |\n");
    printf("|       online como mapa astral, tarot e numerologia.                 |\n");
    printf("|       O sistema também oferece geração de relatórios                |\n");
    printf("|       personalizados sobre clientes e atendimentos, facilitando     |\n");
    printf("|       a análise e acompanhamento dos serviços prestados.            |\n");
    printf("|                                                                     |\n");
    printf("|       Unindo organização e espiritualidade num só lugar.            |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("\n");
    printf("                   >>> Tecle <ENTER> para continuar... <<<            \n");
    getchar();
}

void tela_equipe(void)
{
    system("clear||cls");

    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|           ✦✧✦✧✦  SIG-Aninha - Cigana Vitual  ✦✧✦✧✦                  |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|            Universidade Federal do Rio Grande do Norte              |\n");
    printf("|               Centro de Ensino Superior do Seridó                   |\n");
    printf("|             Departamento de Computação e Tecnologia                 |\n");
    printf("|                Disciplina DCT1106 -- Programação                    |\n");
    printf("|                   Professor: Flavius Gorgônio                       |\n");
    printf("|               Projeto: SIG-Aninha: Cigana Virtual                   |\n");
    printf("|           Developed by: Jaine Souza e Jefferson Willame             |\n");
    printf("|                        Since: Ago, 2025                             |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|                    ✦✧✦✧✦  EQUIPE  ✦✧✦✧✦                             |\n");
    printf("|                                                                     |\n");
    printf("|             Este projeto foi desenvolvido por:                      |\n");
    printf("|                                                                     |\n");
    printf("|             Alun@: Jaine Souza                                      |\n");
    printf("|             Email: jaine.luz.138@ufrn.edu.br                        |\n");
    printf("|             Redes Sociais: @_jaine.souza_                           |\n");
    printf("|             Git: https://github.com/JefWill/SIG-Aninha.git          |\n");
    printf("|                                                                     |\n");
    printf("|             Alun@: Jefferson Willame                                |\n");
    printf("|             Email: jefferson.willame.712@ufrn.edu.br                |\n");
    printf("|             Redes Sociais: @jefferson_willame                       |\n");
    printf("|             Git: https://github.com/JefWill/SIG-Aninha.git          |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("\n");
    printf("                   >>> Tecle <ENTER> para continuar... <<<            \n");
    getchar();
}

int escolha(void)
{
    int opcao;
    printf("\n           Escolha a opção desejada: ");
    scanf("%d", &opcao);
    printf("\n");
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