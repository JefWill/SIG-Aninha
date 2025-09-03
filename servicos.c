#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "servicos.h"

int tela_menu_servicos(void)
{
    int op_servicos;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧✦ SIG-Aninha - A sigana virtual ✦✧✦✧✦ |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Módulo Signos                     |\n");
    printf("|           2. Módulo Tarot                      |\n");
    printf("|           3. Módulo Numerologia                |\n");
    printf("|           4. Pergunte à Sigana                 |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    op_servicos = escolha();

    return op_servicos;
}

void modulo_servicos(void)
{
    int op_servicos = 11;
    while (op_servicos != 0)
    {
        op_servicos = tela_menu_servicos();

        if (op_servicos == 1)
        {
            modulo_signos();
        }
        else if (op_servicos == 2)
        {
            modulo_tarot();
        }
        else if (op_servicos == 3)
        {
            modulo_numerologia();
        }
        else if (op_servicos == 4)
        {
            perguntas();
        }
        else if (op_servicos == 0)
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

void perguntas(void)
{
    int continuar = 1;
    while (continuar != 0)
    {
        srand(time(NULL)); // inicializa a SEED que faz gerar o numero aleatorio para sortear a resposta
        char *respostas[3] = {"sim", "nao", "talvez"};
        char pergunta[255];
        system("clear||cls");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
        printf("|        ✦✧✦✧✦  Pergunte à Sigana ✦✧✦✧✦       |\n");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

        input(pergunta, 255, "Faça uma pergunta para a sigana (sim ou não)");
        printf("\nSua pergunta foi %s", pergunta);
        printf("\nResposta: %s", respostas[rand() % 3]);
        printf("\n\nDigite 0 para sair");
        printf("\nDigite qualquer numero para continuar perguntando");
        continuar = escolha();
    }
}


//////////////////////////////////////////////
///////////// MODULO SIGNOS //////////////////
//////////////////////////////////////////////

int tela_menu_signos(void)
{
    int op_signos = 1;
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

    return op_signos;
}

void modulo_signos(void)
{
    int op_signos = 11;

    while (op_signos != 0)
    {
        op_signos = tela_menu_signos();

        if (op_signos == 1)
        {
            listar_signos();
        }
        else if (op_signos == 2)
        {
            consultar_signo();
        }
        else if (op_signos == 3)
        {
            compatibilidade();
        }
        else if (op_signos == 4)
        {
            horoscopo_signo();
        }
        else if (op_signos == 5)
        {
            calcular_signo();
        }
        else if (op_signos == 0)
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

char *signos[12] = {
    "Áries", "Touro", "Gêmeos", "Câncer", "Leão", "Virgem",
    "Libra", "Escorpião", "Sagitário", "Capricórnio", "Aquário", "Peixes"};

void exibir_lista_signos(void)
{
    for (int i = 0; i < 12; i++)
    {
        printf("%2d - %s\n", i + 1, signos[i]);
    }
}

void listar_signos(void)
{
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|     ✦✧✦✧✦     Listar Signos     ✦✧✦✧✦    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Existem 12 signos:\n\n");

    exibir_lista_signos();

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");
    printf("\n      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void consultar_signo(void)
{
    int opcao = 11;
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|     ✦✧✦✧✦     Consultar Signo     ✦✧✦✧✦    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    exibir_lista_signos();

    printf("\nEscolha o signo que deseja consultar: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 12)
    {
        printf("\n Opção inválida! Tente novamente.\n");
    }
    else
    {
        printf("\nO signo escolhido foi: %s\n", signos[opcao - 1]);
        printf("Exibe as características detalhadas do signo...\n");
    }
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}

void compatibilidade(void)
{
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|     ✦✧✦✧✦     Compatibilidade     ✦✧✦✧✦    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Calcular compatibilidade dos signos...\n");
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

void horoscopo_signo(void)
{
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|     ✦✧✦✧✦     Horoscopo Signo     ✦✧✦✧✦    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Calcular horoscopo do signo...\n");
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

void calcular_signo(void)
{
    char data_nascimento[11];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|     ✦✧✦✧✦     Calcular Signo     ✦✧✦✧✦    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(data_nascimento, 11, "Digite a data de nascimento (DD/MM/AAAA): ");
    printf("Calcular signo...\n");
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

//////////////////////////////////////////////
///////////// MODULO TAROT ///////////////////
//////////////////////////////////////////////

void modulo_tarot(void)
{
    int op_tarot = 11;
    while (op_tarot != 0)
    {
        op_tarot = tela_menu_tarot();

        if (op_tarot == 1)
        {
            exibir_lista_cartas();
        }
        else if (op_tarot == 2)
        {
            consultar_cartas();
        }
        else if (op_tarot == 0)
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

char *cartas[22] = {"O Louco", "O Mago", "A Sacerdotisa", "A Imperatriz", "O Imperador", "O Hierofante",
                    "Os Enamorados", "O Carro", "A Força", "O Eremita", "A Roda da Fortuna", "A Justiça", "O Enforcado",
                    "A Morte", "A Temperança", "O Diabo", "A Torre", "A Estrela", "A Lua", "O Sol", "O Julgamento", "O Mundo"};

void exibir_lista_cartas(void)
{
    system("clear|| cls");
    printf("\nLista de cartas (Arcanos): \n");
    for (int i = 0; i < 22; i++)
    {
        printf("%2d - %s\n", i + 1, cartas[i]);
    }
    printf("\n☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void consultar_cartas(void)
{
    srand(time(NULL)); // inicializa a SEED que faz gerar o numero aleatorio para sortear a carta
    char cpf[15], data[11];
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|          ✦✧✦✧ Consultar Cartas ✧✦✧✦          |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");

    input(cpf, 15, "Digite o CPF do cliente:");
    input(data, 11, "Digite a data atual (DD/MM/AAAA):");

    printf("\n Resultado da consulta:\n");
    printf(" Passado : %s\n", cartas[rand() % 22]);
    printf(" Presente: %s\n", cartas[rand() % 22]);
    printf(" Futuro  : %s\n", cartas[rand() % 22]);

    printf("\n☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

int tela_menu_tarot(void)
{
    int op_tarot;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧✦   SIG-Aninha - Módulo tarot   ✦✧✦✧✦      |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Exibir Cartas                     |\n");
    printf("|           2. Realizar Consulta Tarot           |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_tarot = escolha();
    return op_tarot;
}

//////////////////////////////////////////////
///////////// MODULO NUMEROLOGIA /////////////
//////////////////////////////////////////////

int tela_menu_numerologia(void)
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

    return op_num;
}

void modulo_numerologia(void)
{
    int op_num = 11;

    while (op_num != 0)
    {
        op_num = tela_menu_numerologia();

        if (op_num == 1)
        {
            descobrir_numero();
        }
        else if (op_num == 2)
        {
            significado_numeros();
        }
        else if (op_num == 0)
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

void descobrir_numero(void)
{
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|     ✦✧✦✧✦   Descobra seu Numero    ✦✧✦✧✦   |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    char data_nascimento[11];
    input(data_nascimento, 11, "Digite a data de nascimento (DD/MM/AAAA): ");

    printf("Descobrindo...\n");

    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

void significado_numeros(void)
{
    int n;
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|     ✦✧✦✧✦   Significado dos Números    ✦✧✦✧✦   |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Digite o número que deseja saber o significado: \n");
    scanf("%d", &n);

    exibir_significados(n);

    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

void exibir_significados(int n)
{
    if (n == 1)
    {
        printf("Liderança, independência e iniciativa.\n");
        getchar();
    }
    else if (n == 2)
    {
        printf("Cooperação, sensibilidade e diplomacia.\n");
        getchar();
    }
    else if (n == 3)
    {
        printf("Comunicação, expressão e criatividade.\n");
        getchar();
    }
    else if (n == 4)
    {
        printf("Organização, estabilidade e disciplina.\n");
        getchar();
    }
    else if (n == 5)
    {
        printf("Liberdade, aventura e versatilidade.\n");
        getchar();
    }
    else if (n == 6)
    {
        printf("Amor, família e responsabilidade.\n");
        getchar();
    }
    else if (n == 7)
    {
        printf("Espiritualidade, introspecção e sabedoria.\n");
        getchar();
    }
    else if (n == 8)
    {
        printf("Sucesso, poder e realização material.\n");
        getchar();
    }
    else if (n == 9)
    {
        printf("Compaixão, humanitarismo e generosidade.\n");
        getchar();
    }
    else
    {
        printf("Número inválido!\n");
        getchar();
    }
}
