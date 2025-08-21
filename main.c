// Universidade Federal do Rio Grande do Norte - UFRN
// Centro de Ensino Superior do Seridó - CERES
// Departamento de Computação e Tecnologia - DCT
// Disciplina DCT1106 - Programação
// Projeto Sistema de Gestão Mística (SIG-Aninha)
// Desenvolvido por: @JaineSouz e @JeffWill - since Ago, 2025

#include <stdio.h>
#include <stdlib.h>

// Assinatura das funções
char tela_menu_principal(void);
char escolha(void);

void tela_menu_cliente(void);

void tela_menu_agendamento(void);
void agendar_consulta(void);
void atualizar_agendamento(void);
void listar_agendamentos(void);

void tela_menu_signos(void);
void tela_menu_tarot(void);
void tela_menu_numerologia(void);
void tela_menu_relatorio(void);
void tela_menu_informacoes(void);
void tela_sobre(void);
void tela_equipe(void);

int main(void)
{
    char op = ' ';

    while (op != '0')
    {
        op = tela_menu_principal();

        if (op == '1')
        {
            tela_menu_cliente();
        }
        else if (op == '2')
        {
            tela_menu_agendamento();
        }
        else if (op == '3')
        {
            tela_menu_signos();
        }
        else if (op == '4')
        {
            tela_menu_tarot();
        }
        else if (op == '5')
        {
            tela_menu_numerologia();
        }
        else if (op == '6')
        {
            tela_menu_relatorio();
        }
        else if (op == '7')
        {
            tela_menu_informacoes();
        }
        else if (op == '0')
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

char tela_menu_principal(void)
{
    char op; // isso é a variável de opção principal
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("|   ✦✧✦✧✦ SIG-Aninha - A sigana virtual ✦✧✦✧✦    |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Módulo Cliente                    |\n");
    printf("|           2. Módulo Agendamento                |\n");
    printf("|           3. Módulo Signos                     |\n");
    printf("|           4. Módulo Tarot                      |\n");
    printf("|           5. Módulo Numerologia                |\n");
    printf("|           6. Módulo Relatorio                  |\n");
    printf("|           7. Informações                       |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    op = escolha();

    return op;
}

void tela_menu_cliente(void)
{
    char op_cliente; // aqui cria uma variável de opção só pro modulo de cliente
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("|   ✦✧✦✧✦ SIG-Aninha - Módulo Cliente   ✦✧✦✧✦    |\n");
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
}

void tela_menu_agendamento(void)
{
    char op_agendamento;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧ SIG-Aninha - Módulo agendamento ✧✦✧✦  |\n");
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
}

void agendar_consulta(void)
{
    char cpf[15], nome[100], data[11], horario[6], tipo_consulta[20];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|          ✦✧✦✧ Agendar Consulta ✧✦✧✦          |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);

    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    printf("Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia): ");
    scanf("%s", tipo_consulta);

    printf("Digite a data da consulta: ");
    scanf("%s", data);

    printf("Digite o horário da consulta: ");
    scanf("%s", horario);

    printf("\nConsulta agendada com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<         \n");
    getchar();
    getchar();
}

void atualizar_agendamento(void)
{
    char cpf[15], nome[100], data[11], horario[6], tipo_consulta[20];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|         ✦✧✦✧ Atualizar Agendamento ✧✦✧✦        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);

    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    printf("Digite qual tipo de consulta deseja (Tarot, Signos, Numerologia): ");
    scanf("%s", tipo_consulta);

    printf("Digite a data da consulta: ");
    scanf("%s", data);

    printf("Digite o horário da consulta: ");
    scanf("%s", horario);

    printf("\nAgendamento atualizado com sucesso!\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<         \n");
    getchar();
    getchar();
}

void listar_agendamentos(void)
{
    char data[11];
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           ✦✧✦✧ Listar Agendamentos ✧✦✧✦          |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    printf("Digite a data desejada (dd/mm/aaaa): ");
    scanf("%s", data);
    printf("Agendamentos para a data %s:\n", data);

    printf("      >>> Tecle <ENTER> para continuar... <<<         \n");
    getchar();
    getchar();
}

void tela_menu_signos(void)
{
    char op_signos;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("|    ✦✧✦✧✦   SIG-Aninha - Módulo signos  ✦✧✦✧✦   |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Listar Signos                     |\n");
    printf("|           2. Consultar Signo                   |\n");
    printf("|           3. Consultar Compatibilidade         |\n");
    printf("|           4. Gerar Horoscopo Diário            |\n");
    printf("|           5. Calcular Signo                    |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_signos = escolha();
}

void tela_menu_tarot(void)
{
    char op_tarot;
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

    char op_num;
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

    char op_rel;
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
    char op_info = ' ';
    while (op_info != '0')
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

        if (op_info == '1')
        {
            tela_sobre();
        }
        else if (op_info == '2')
        {
            tela_equipe();
        }
        else if (op_info == '0')
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

char escolha(void)
{
    char opcao;
    printf("           Escolha a opção desejada: ");
    scanf("%c", &opcao);
    printf("\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<         \n");
    getchar();
    return opcao;
}