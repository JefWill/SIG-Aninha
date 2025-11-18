#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "servicos.h"
#include "../utilitarios/utilitarios.h"
#include "../clientes/cliente.h"
#include "../validacao/validacao.h"

int tela_menu_servicos(void)
{
    int op_servicos;
    system("clear||cls");
    header();
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|               ✦✧✦✧✦    SIG-Aninha - Módulo Serviços    ✦✧✦✧✦           |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Módulo Signos                                  |\n");
    printf("|                      2. Módulo Tarot                                   |\n");
    printf("|                      3. Módulo Numerologia                             |\n");
    printf("|                      4. Pergunte à Cigana                              |\n");
    printf("|                      5. Listar Serviços                                |\n");
    printf("|                      0. Retornar ao Menu Principal                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    op_servicos = escolha();

    return op_servicos;
}

void modulo_servicos(void)
{
    int op_servicos;
    int id;
    char cpf[16];
    do
    {
        op_servicos = tela_menu_servicos();

        switch (op_servicos)
        {
        case 1:
            id = 1;
            dados_usuario_servico(cpf);
            cadastra_arquivo_servico(cpf, id);
            modulo_signos();
            break;
        case 2:
            id = 2;
            dados_usuario_servico(cpf);
            cadastra_arquivo_servico(cpf, id);
            modulo_tarot();
            break;
        case 3:
            id = 3;
            dados_usuario_servico(cpf);
            cadastra_arquivo_servico(cpf, id);
            modulo_numerologia();
            break;
        case 4:
            id = 4;
            dados_usuario_servico(cpf);
            cadastra_arquivo_servico(cpf, id);
            perguntas();
            break;
        case 5:
            listar_servicos();
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
    } while (op_servicos != 0);
}

void perguntas(void)
{
    int continuar = 1;
    while (continuar != 0)
    {
        srand(time(NULL)); // inicializa a SEED que faz gerar o numero aleatorio para sortear a resposta
        char *respostas[3] = {"Sim", "Não", "Talvez"};
        char pergunta[255];
        system("clear||cls");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
        printf("|                                                                        |\n");
        printf("|                    ✦✧✦✧✦   Pergunte à Cigana   ✦✧✦✧✦                   |\n");
        printf("|                                                                        |\n");
        printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

        input(pergunta, 255, "Faça uma pergunta para a cigana (sim ou não)");
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
    int op_signos;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                ✦✧✦✧✦   SIG-Aninha - Módulo Signos   ✦✧✦✧✦              |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Listar Todos os Signos                         |\n");
    printf("|                      2. Consultar Detalhes de um Signo                 |\n");
    printf("|                      3. Verificar Compatibilidade Amorosa              |\n");
    printf("|                      4. Ver Horóscopo do Signo                         |\n");
    printf("|                      5. Calcular seu Signo                             |\n");
    printf("|                      6. Calcular Signo de Outra Pessoa                 |\n");
    printf("|                      0. Retornar ao Menu de Serviços                   |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
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
        else if (op_signos == 6)
        {
            calcular_signo_pessoa();
        }
        else if (op_signos == 0)
        {
            printf("           Voltando ao menu principal...\n");
            getchar();
        }
        else if (op_signos == -1)
        {
            confirmacao();
        }
        else
        {
            printf("                Opção Inexistente!\n");
            confirmacao();
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
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                    ✦✧✦✧✦   Lista de Signos   ✦✧✦✧✦                     |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");
    printf("   Existem 12 signos no Zodíaco:\n\n");

    exibir_lista_signos();

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");
    printf("\n      >>> Tecle <ENTER> para continuar... <<<\n");
    getchar();
}

void consultar_signo(void)
{
    int opcao = 11;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                   ✦✧✦✧✦   Consultar Signo   ✦✧✦✧✦                      |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

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
        exibir_caracteristicas_signo(opcao);
    }
    confirmacao();
}

void exibir_caracteristicas_signo(int numero)
{
    switch (numero)
    {
    case 1: // Áries
        printf("♈ Áries\n");
        printf("Elemento: Fogo.\n");
        printf("Planeta regente: Marte\n");
        printf("Cores: Vermelho\n");
        printf("Pedras: Diamante, Cornalina\n");
        printf("Qualidades: Energia, coragem, iniciativa, impulsividade\n");
        printf("Frase chave: 'Eu sou'\n");
        getchar();
        break;
    case 2: // Touro
        printf("♉ Touro\n");
        printf("Elemento: Terra.\n");
        printf("Planeta regente: Vênus\n");
        printf("Cores: Verde, Rosa\n");
        printf("Pedras: Esmeralda, Quartzo rosa\n");
        printf("Qualidades: Persistência, estabilidade, paciência, sensualidade\n");
        printf("Frase chave: 'Eu tenho'\n");
        getchar();
        break;
    case 3: // Gêmeos
        printf("♊ Gêmeos\n");
        printf("Elemento: Ar.\n");
        printf("Planeta regente: Mercúrio\n");
        printf("Cores: Amarelo, Azul claro\n");
        printf("Pedras: Ágata, Citrino\n");
        printf("Qualidades: Comunicação, versatilidade, curiosidade, dualidade\n");
        printf("Frase chave: 'Eu penso'\n");
        getchar();
        break;
    case 4: // Câncer
        printf("♋ Câncer\n");
        printf("Elemento: Água.\n");
        printf("Planeta regente: Lua\n");
        printf("Cores: Prata, Branco\n");
        printf("Pedras: Pérola, Água-marinha\n");
        printf("Qualidades: Sensibilidade, intuição, proteção, emocional\n");
        printf("Frase chave: 'Eu sinto'\n");
        getchar();
        break;
    case 5: // Leão
        printf("♌ Leão\n");
        printf("Elemento: Fogo.\n");
        printf("Planeta regente: Sol\n");
        printf("Cores: Dourado, Laranja\n");
        printf("Pedras: Rubi, Olho de Tigre\n");
        printf("Qualidades: Liderança, confiança, criatividade, generosidade\n");
        printf("Frase chave: 'Eu quero'\n");
        getchar();
        break;
    case 6: // Virgem
        printf("♍ Virgem\n");
        printf("Elemento: Terra.\n");
        printf("Planeta regente: Mercúrio\n");
        printf("Cores: Verde, Marrom\n");
        printf("Pedras: Safira, Quartzo\n");
        printf("Qualidades: Organização, precisão, análise, prudência\n");
        printf("Frase chave: 'Eu analiso'\n");
        getchar();
        break;
    case 7: // Libra
        printf("♎ Libra\n");
        printf("Elemento: Ar.\n");
        printf("Planeta regente: Vênus\n");
        printf("Cores: Azul, Rosa\n");
        printf("Pedras: Lápis-lazúli, Ametista\n");
        printf("Qualidades: Harmonia, diplomacia, sociabilidade, justiça\n");
        printf("Frase chave: 'Eu equilibro'\n");
        getchar();
        break;
    case 8: // Escorpião
        printf("♏ Escorpião\n");
        printf("Elemento: Água.\n");
        printf("Planeta regente: Plutão / Marte\n");
        printf("Cores: Vermelho, Preto\n");
        printf("Pedras: Topázio, Granada\n");
        printf("Qualidades: Intensidade, mistério, paixão, determinação\n");
        printf("Frase chave: 'Eu desejo'\n");
        getchar();
        break;
    case 9: // Sagitário
        printf("♐ Sagitário\n");
        printf("Elemento: Fogo.\n");
        printf("Planeta regente: Júpiter\n");
        printf("Cores: Azul, Roxo\n");
        printf("Pedras: Turquesa, Ametista\n");
        printf("Qualidades: Otimismo, liberdade, aventura, sinceridade\n");
        printf("Frase chave: 'Eu busco'\n");
        getchar();
        break;
    case 10: // Capricórnio
        printf("♑ Capricórnio\n");
        printf("Elemento: Terra.\n");
        printf("Planeta regente: Saturno\n");
        printf("Cores: Marrom, Cinza\n");
        printf("Pedras: Ônix, Quartzo\n");
        printf("Qualidades: Determinação, disciplina, responsabilidade, paciência\n");
        printf("Frase chave: 'Eu construo'\n");
        getchar();
        break;
    case 11: // Aquário
        printf("♒ Aquário\n");
        printf("Elemento: Ar.\n");
        printf("Planeta regente: Urano / Saturno\n");
        printf("Cores: Azul, Turquesa\n");
        printf("Pedras: Ametista, Água-marinha\n");
        printf("Qualidades: Originalidade, inovação, humanitarismo, independência\n");
        printf("Frase chave: 'Eu sei'\n");
        getchar();
        break;
    case 12: // Peixes
        printf("♓ Peixes\n");
        printf("Elemento: Água.\n");
        printf("Planeta regente: Netuno / Júpiter\n");
        printf("Cores: Verde, Lilás\n");
        printf("Pedras: Água-marinha, Ametista\n");
        printf("Qualidades: Sensibilidade, intuição, empatia, criatividade\n");
        printf("Frase chave: 'Eu acredito'\n");
        getchar();
        break;
    default:
        printf("Número inválido! Digite um valor entre 1 e 12.\n");
        getchar();
        break;
    }
}

void compatibilidade(void)
{
    // Tive ajuda de IA - GPT-5 mini.
    int signo1, signo2;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧✦   Compatibilidade Amorosa   ✦✧✦✧✦              |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    exibir_lista_signos();

    printf("Escolha o número do seu signo: ");
    scanf("%d", &signo1);
    printf("Escolha o número do signo da outra pessoa: ");
    scanf("%d", &signo2);

    if (signo1 < 1 || signo1 > 12 || signo2 < 1 || signo2 > 12)
    {
        printf("\nNúmero inválido! Digite um valor entre 1 e 12.\n");
        getchar();
        return;
    }

    // Matriz de compatibilidade em percentual (12x12)
    int matriz[12][12] = {
        {80, 60, 70, 50, 85, 65, 55, 60, 75, 50, 70, 55}, // Áries
        {60, 80, 55, 70, 60, 85, 65, 50, 60, 75, 55, 70}, // Touro
        {70, 55, 80, 65, 75, 60, 85, 50, 70, 55, 60, 75}, // Gêmeos
        {50, 70, 65, 80, 55, 75, 60, 85, 50, 70, 55, 60}, // Câncer
        {85, 60, 75, 55, 80, 65, 70, 60, 85, 50, 70, 55}, // Leão
        {65, 85, 60, 75, 65, 80, 55, 70, 60, 85, 50, 70}, // Virgem
        {55, 65, 85, 60, 70, 55, 80, 65, 70, 60, 85, 50}, // Libra
        {60, 50, 50, 85, 60, 70, 65, 80, 55, 70, 60, 85}, // Escorpião
        {75, 60, 70, 50, 85, 60, 70, 55, 80, 65, 70, 60}, // Sagitário
        {50, 75, 55, 70, 50, 85, 60, 70, 65, 80, 55, 70}, // Capricórnio
        {70, 55, 60, 55, 70, 50, 85, 60, 70, 55, 80, 65}, // Aquário
        {55, 70, 75, 60, 55, 70, 50, 85, 60, 70, 65, 80}  // Peixes
    };

    printf("\nA compatibilidade entre %s e %s é de %d%%\n",
           signos[signo1 - 1], signos[signo2 - 1], matriz[signo1 - 1][signo2 - 1]);

    confirmacao();
    getchar();
}

void horoscopo_signo(void)
{
    int signo;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                  ✦✧✦✧✦   Horóscopo do Signo   ✦✧✦✧✦                |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    exibir_lista_signos();
    printf("Digite o número do signo: ");
    scanf("%d", &signo);

    exibir_mensagem_signo(signo);

    confirmacao();
}

void exibir_mensagem_signo(int signo)
{
    switch (signo)
    {
    case 1:
        printf("Áries: Energia e coragem em alta. Evite agir por impulso.\n");
        getchar();
        break;
    case 2:
        printf("Touro: Um bom dia para cuidar de si e valorizar o conforto.\n");
        getchar();
        break;
    case 3:
        printf("Gêmeos: Comunicação será sua aliada. Converse e troque ideias.\n");
        getchar();
        break;
    case 4:
        printf("Câncer: Emoções afloradas. Escute seu coração, mas mantenha o equilíbrio.\n");
        getchar();
        break;
    case 5:
        printf("Leão: Mostre seu brilho, mas sem exageros. O dia pede autoconfiança.\n");
        getchar();
        break;
    case 6:
        printf("Virgem: Organização será essencial. Foque no que é prático.\n");
        getchar();
        break;
    case 7:
        printf("Libra: Harmonia nas relações. Evite se sobrecarregar tentando agradar.\n");
        getchar();
        break;
    case 8:
        printf("Escorpião: Intuição aguçada. Aproveite para resolver pendências emocionais.\n");
        getchar();
        break;
    case 9:
        printf("Sagitário: Liberdade em foco. Planeje aventuras, mas com responsabilidade.\n");
        getchar();
        break;
    case 10:
        printf("Capricórnio: Persistência trará resultados. Não desista dos seus planos.\n");
        getchar();
        break;
    case 11:
        printf("Aquário: Criatividade em alta. Aposte em ideias fora do comum.\n");
        getchar();
        break;
    case 12:
        printf("Peixes: Sensibilidade à flor da pele. Confie nos seus sonhos e na intuição.\n");
        getchar();
        break;
    default:
        printf("Número inválido! Digite um valor entre 1 e 12.\n");
        getchar();
        getchar();
        break;
    }
}

void calcular_signo(void)
{
    FILE *arq_clientes;
    Cliente *clt;
    char cpf[16];
    int dia, mes, ano;
    int encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                   ✦✧✦✧✦   Calcular Signo   ✦✧✦✧✦                        |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    do
    {
        input(cpf, 16, "Digite o CPF cadastrado: ");
        if (!validar_cpf(cpf))
            printf("CPF inválido! Tente novamente.\n");
    } while (!validar_cpf(cpf));

    arq_clientes = fopen("clientes/clientes.dat", "rb");
    if (arq_clientes == NULL)
    {
        printf("\n Erro ao abrir o arquivo de clientes.\n");
        confirmacao();
        return;
    }

    clt = (Cliente *)malloc(sizeof(Cliente));

    while (fread(clt, sizeof(Cliente), 1, arq_clientes))
    {
        if (strcmp(clt->cpf, cpf) == 0 && clt->status == 1)
        {
            sscanf(clt->data_nascimento, "%2d%2d%4d", &dia, &mes, &ano);

            printf("\nNome: %s\n", clt->nome);
            printf("Data de Nascimento: %02d/%02d/%04d\n", dia, mes, ano);
            printf("Seu signo é: %s\n", obter_signo(dia, mes));

            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("\nCPF não encontrado ou cliente inativo.\n");
    }

    fclose(arq_clientes);
    free(clt);

    confirmacao();
}
void calcular_signo_pessoa(void)
{

    int dia, mes;
    char data[12];

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                   ✦✧✦✧✦   Calcular Signo   ✦✧✦✧✦                        |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    input(data, 12, "Digite a data de nascimento (dd/mm): ");

    if (!validar_data_signo(data))
    {
        printf("\nFormato inválido! Use dd/mm.\n");
        confirmacao();
        return;
    }

    sscanf(data, "%02d%02d", &dia, &mes);

    printf("\nData de nascimento: %02d/%02d\n", dia, mes);
    printf("Signo: %s\n", obter_signo(dia, mes));

    confirmacao();
}

char *obter_signo(int dia, int mes)
{
    if ((dia >= 21 && mes == 3) || (dia <= 19 && mes == 4))
        return "Áries";
    else if ((dia >= 20 && mes == 4) || (dia <= 20 && mes == 5))
        return "Touro";
    else if ((dia >= 21 && mes == 5) || (dia <= 20 && mes == 6))
        return "Gêmeos";
    else if ((dia >= 21 && mes == 6) || (dia <= 22 && mes == 7))
        return "Câncer";
    else if ((dia >= 23 && mes == 7) || (dia <= 22 && mes == 8))
        return "Leão";
    else if ((dia >= 23 && mes == 8) || (dia <= 22 && mes == 9))
        return "Virgem";
    else if ((dia >= 23 && mes == 9) || (dia <= 22 && mes == 10))
        return "Libra";
    else if ((dia >= 23 && mes == 10) || (dia <= 21 && mes == 11))
        return "Escorpião";
    else if ((dia >= 22 && mes == 11) || (dia <= 21 && mes == 12))
        return "Sagitário";
    else if ((dia >= 22 && mes == 12) || (dia <= 19 && mes == 1))
        return "Capricórnio";
    else if ((dia >= 20 && mes == 1) || (dia <= 18 && mes == 2))
        return "Aquário";
    else
        return "Peixes";
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
        else if (op_tarot == -1)
        {
            confirmacao();
        }
        else
        {
            printf("                Opção Inexistente!\n");
            confirmacao();
        }
    }
}

char *cartas[22] = {"O Louco", "O Mago", "A Sacerdotisa", "A Imperatriz", "O Imperador", "O Hierofante",
                    "Os Enamorados", "O Carro", "A Força", "O Eremita", "A Roda da Fortuna", "A Justiça", "O Enforcado",
                    "A Morte", "A Temperança", "O Diabo", "A Torre", "A Estrela", "A Lua", "O Sol", "O Julgamento", "O Mundo"};

void exibir_lista_cartas(void)
{
    system("clear|| cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|             ✦✧✦✧✦   Lista de Cartas (Arcanos Maiores)   ✦✧✦✧✦          |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");
    for (int i = 0; i < 22; i++)
    {
        printf("%2d - %s\n", i + 1, cartas[i]);
    }
    printf("\n☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");
    confirmacao();
}

void consultar_cartas(void)
{
    // Tive ajuda do Chat GPT 4.1 para montar a lógica de sorteio das cartas
    srand(time(NULL));
    int sorteadas[3] = {-1, -1, -1};
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                   ✦✧✦✧✦   Consulta de Tarot   ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    for (int i = 0; i < 3; i++)
    {
        int carta;
        int repetida;
        do
        {
            carta = rand() % 22;
            repetida = 0;
            for (int j = 0; j < i; j++)
            {
                if (sorteadas[j] == carta)
                {
                    repetida = 1;
                    break;
                }
            }
        } while (repetida);
        sorteadas[i] = carta;
    }

    char *significados[22] = {
        "Novos começos, espontaneidade, aventura.",
        "Habilidade, iniciativa, poder pessoal.",
        "Intuição, mistério, sabedoria interior.",
        "Fertilidade, criatividade, cuidado.",
        "Autoridade, estrutura, liderança.",
        "Tradição, espiritualidade, ensino.",
        "Escolhas, relacionamentos, harmonia.",
        "Vitória, movimento, conquista.",
        "Coragem, domínio, força interior.",
        "Busca, introspecção, sabedoria.",
        "Mudanças, sorte, ciclos.",
        "Justiça, equilíbrio, verdade.",
        "Sacrifício, pausa, nova perspectiva.",
        "Transformação, fim de ciclo, renascimento.",
        "Equilíbrio, paciência, moderação.",
        "Tentação, vícios, materialismo.",
        "Ruptura, mudanças inesperadas.",
        "Esperança, inspiração, fé.",
        "Ilusões, intuição, confusão.",
        "Alegria, sucesso, vitalidade.",
        "Renovação, julgamento, despertar.",
        "Realização, conclusão, plenitude."};

    printf("Para sua consulta, você irá puxar 3 cartas representando o Passado, Presente e Futuro.\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("Pressione ENTER para começar...");
    getchar();
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("Pressione ENTER para puxar a primeira carta (Passado)...");
    getchar();
    printf(" Passado : %s\n", cartas[sorteadas[0]]);
    printf(" Significado: %s\n", significados[sorteadas[0]]);
    printf("Pressione ENTER para puxar a segunda carta (Presente)...");
    getchar();
    printf(" Presente : %s\n", cartas[sorteadas[1]]);
    printf(" Significado: %s\n", significados[sorteadas[1]]);
    printf("Pressione ENTER para puxar a terceira carta (Futuro)...");
    getchar();
    printf(" Futuro  : %s\n", cartas[sorteadas[2]]);
    printf(" Significado: %s\n", significados[sorteadas[2]]);

    printf("\n☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");
    printf("           Pressione a tecla ENTER para continuar...");
    getchar();
}

int tela_menu_tarot(void)
{
    int op_tarot;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   SIG-Aninha - Módulo Tarot   ✦✧✦✧✦              |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Exibir Todas as Cartas                         |\n");
    printf("|                      2. Realizar Consulta de Tarot                     |\n");
    printf("|                      0. Retornar ao Menu de Serviços                   |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
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
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                ✦✧✦✧✦   SIG-Aninha - Módulo Numerologia   ✦✧✦✧✦         |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                      1. Descobrir qual é o seu Número                  |\n");
    printf("|                      2. Ver o Significado dos Números                  |\n");
    printf("|                      0. Retornar ao Menu de Serviços                   |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
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
        else if (op_num == -1)
        {
            confirmacao();
        }
        else
        {
            printf("                Opção Inexistente!\n");
            confirmacao();
        }
    }
}

void descobrir_numero(void)
{
    // Tive ajuda do Chat GPT 4.1 para montar a lógica de cálculo do número
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|                 ✦✧✦✧✦   Descubra seu Número   ✦✧✦✧✦                    |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    char data_nascimento[12];
    do
    {
        input(data_nascimento, 12, "Digite a data de nascimento (DD/MM/AAAA): ");
        if (!validar_data(data_nascimento))
            printf("Data inválida! Tente novamente.\n");
    } while (!validar_data(data_nascimento));

    int soma = 0;
    for (int i = 0; data_nascimento[i] != '\0'; i++)
    {
        if (data_nascimento[i] >= '0' && data_nascimento[i] <= '9')
        {
            soma += data_nascimento[i] - '0'; // Converte char para int já que os números em ASCII estão em sequência
        }
    }

    while (soma > 9)
    {
        int temp = 0;
        while (soma > 0)
        {
            temp += soma % 10; // Pega o último dígito
            soma /= 10;        // Remove o último dígito
        }
        soma = temp;
    }

    printf("\nSeu número é: %d\n", soma);
    exibir_significados(soma);

    confirmacao();
}

void significado_numeros(void)
{
    int n;
    system("clear||cls");

    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                        |\n");
    printf("|               ✦✧✦✧✦   Significado dos Números   ✦✧✦✧✦                  |\n");
    printf("|                                                                        |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    printf("Digite o número que deseja saber o significado: \n");
    scanf("%d", &n);
    getchar();

    exibir_significados(n);

    confirmacao();
}

void exibir_significados(int n)
{
    printf("\n   ");
    if (n == 1)
    {
        printf("Significado: Liderança, independência e iniciativa.\n");
    }
    else if (n == 2)
    {
        printf("Significado: Cooperação, sensibilidade e diplomacia.\n");
    }
    else if (n == 3)
    {
        printf("Significado: Comunicação, expressão e criatividade.\n");
    }
    else if (n == 4)
    {
        printf("Significado: Organização, estabilidade e disciplina.\n");
    }
    else if (n == 5)
    {
        printf("Significado: Liberdade, aventura e versatilidade.\n");
    }
    else if (n == 6)
    {
        printf("Significado: Amor, família e responsabilidade.\n");
    }
    else if (n == 7)
    {
        printf("Significado: Espiritualidade, introspecção e sabedoria.\n");
    }
    else if (n == 8)
    {
        printf("Significado: Sucesso, poder e realização material.\n");
    }
    else if (n == 9)
    {
        printf("Significado: Compaixão, humanitarismo e generosidade.\n");
    }
    else
    {
        printf("Número inválido! Digite um valor entre 1 e 9.\n");
    }
}

void dados_usuario_servico(char *cpf)
{
    system("clear||cls");
    printf("Antes de continuar, por favor, preencha o dado solicitado: \n\n");

    do
    {
        input(cpf, 16, "Digite o CPF: ");
        if (!validar_cpf(cpf))
            printf("CPF inválido! Tente novamente.\n");
    } while (!validar_cpf(cpf));

    confirmacao();
}

void cadastra_arquivo_servico(char *cpf, int id)
{
    FILE *arq_servicos;
    Servicos srv;
    time_t agora = time(NULL);
    struct tm *tm_info = localtime(&agora);

    arq_servicos = fopen("servicos/servicos.dat", "ab");
    if (arq_servicos == NULL)
    {
        printf("\nErro ao abrir o arquivo de serviços.\n");
        return;
    }

    strncpy(srv.cpf, cpf, 16);
    srv.id = id;

    strftime(srv.data, sizeof(srv.data), "%d%m%Y", tm_info);  // Formato: DDMMYYYY
    strftime(srv.hora, sizeof(srv.hora), "%H%M%S", tm_info);  // Formato: HHMMSS

    fwrite(&srv, sizeof(Servicos), 1, arq_servicos);

    fclose(arq_servicos);
}

void listar_servicos(void)
{
    FILE *arq_servicos;
    Servicos srv;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                        Lista de Serviços Realizados                   |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    arq_servicos = fopen("servicos/servicos.dat", "rb");
    if (arq_servicos == NULL)
    {
        printf("\n Erro ao abrir o arquivo de serviços.\n");
        return;
    }

    while (fread(&srv, sizeof(Servicos), 1, arq_servicos))
    {
        printf(" CPF : %s\n", srv.cpf);
        printf(" ID  : %d (1-Signo 2-Tarot 3-Numerologia 4-Pergunte)\n", srv.id);
        printf(" Data: %s\n", srv.data);
        printf(" Hora: %s\n", srv.hora);
        printf("------------------------------------------------------------\n");
    }

    fclose(arq_servicos);

    confirmacao();
}

int validar_data_signo(const char *data)
{
    int dia, mes;
    // Verifica se o formato está correto: dd/mm
    if (strlen(data) != 4 || sscanf(data, "%2d%2d", &dia, &mes) != 2)
    {
        return 0;
    }
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12)
    {
        return 0;
    }
    return 1;
}

void listar_servicos_por_data(void)
{
    FILE *arq_servicos;
    Servicos *srv;
    char data[12];
    int encontrado = 0;

    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                          Lista de Serviços Por Data                   |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n\n");

    srv = (Servicos *)malloc(sizeof(Servicos));
    ler_data(data);

    arq_servicos = fopen("servicos/servicos.dat", "rb");
    if (arq_servicos == NULL)
    {
        printf("\nErro ao abrir o arquivo de serviços.\n");
        return;
    }

    while (fread(srv, sizeof(Servicos), 1, arq_servicos))
    {   
        if (strcmp(srv->data, data) == 0){
            if (!encontrado)
            {
                int dia, mes, ano;
                sscanf(srv->data, "%2d%2d%4d", &dia, &mes, &ano);
                printf("\nServiços para a data %02d/%02d/%04d:\n", dia, mes, ano);
                printf("------------------------------------------------------\n");
                printf("| %-12s | %-13s | %-10s | %-8s |\n", 
                    "CPF", "Serviço", "Data", "Horário");
                printf("------------------------------------------------------\n");
            }
            encontrado = 1;
            exibir_servicos(srv);
        }
    }

    if (!encontrado) {
        printf("Nenhum Serviço Online Realizado\n");
    }

    fclose(arq_servicos);
    free(srv);

    confirmacao();
}

void exibir_servicos(const Servicos *srv)
{
    int dia, mes, ano, hora, minuto;
    char nome_servico[20];  
    
    
    switch (srv->id) {
        case 1:
            strcpy(nome_servico, "Signos");
            break;
        case 2:
            strcpy(nome_servico, "Numerologia");
            break;
        case 3:
            strcpy(nome_servico, "Tarot");
            break;
        case 4:
            strcpy(nome_servico, "Perguntas");
            break;
        default:
            strcpy(nome_servico, "Desconhecido");
            break;
    }

    
    sscanf(srv->data, "%2d%2d%4d", &dia, &mes, &ano);
    sscanf(srv->hora, "%2d%2d", &hora, &minuto);

    
    printf("| %-12s | %-12s | %02d/%02d/%04d | %02d:%02d   |\n", 
            srv->cpf, nome_servico, dia, mes, ano, hora, minuto);
}