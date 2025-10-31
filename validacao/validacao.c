#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "validacao.h"
#include "../clientes/cliente.h"

// Obtive ajuda de IA - Chagpt GPT-5
int validar_data(const char *data)
{
    int dia, mes, ano;

    // Verifica se a data tem exatamente 8 caracteres (sem barras)
    if (strlen(data) != 8)
        return 0;

    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < 8; i++)
    {
        if (!isdigit(data[i]))
            return 0;
    }

    // Extrai dia, mês e ano a partir da string sem as barras
    sscanf(data, "%2d%2d%4d", &dia, &mes, &ano);

    // Pega o ano atual do sistema
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int dia_atual = tm.tm_mday;
    int mes_atual = tm.tm_mon + 1;
    int ano_atual = tm.tm_year + 1900;

    // Verifica se o ano está em um intervalo aceitável
    if (ano < 1900 || ano > ano_atual)
        return 0;

    // Verifica se o mês é válido
    if (mes < 1 || mes > 12)
        return 0;

    // Determina o número de dias do mês
    int dias_mes;
    switch (mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        dias_mes = 30;
        break;
    case 2:
        // Verifica se o ano é bissexto para o mês de fevereiro
        dias_mes = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
        break;
    default:
        dias_mes = 31;
    }

    // Verifica se o dia é válido
    if (dia < 1 || dia > dias_mes)
        return 0;

    // Verifica se a data é maior que a data atual
    if (ano > ano_atual)
        return 0;
    if (ano == ano_atual && mes > mes_atual)
        return 0;
    if (ano == ano_atual && mes == mes_atual && dia > dia_atual)
        return 0;

    return 1;
}

// Obtive ajuda de IA - Chagpt GPT-5
int validar_nome(const char *nome)
{
    if (nome == NULL)
        return 0;

    size_t len = strlen(nome);
    if (len == 0)
        return 0;

    // Trim manual
    size_t start = 0;
    while (start < len && (nome[start] == ' ' || nome[start] == '\t'))
        start++;

    size_t end = len;
    while (end > start && (nome[end - 1] == ' ' || nome[end - 1] == '\t'))
        end--;

    if (end - start < 2)
        return 0; // menos de 2 letras

    for (size_t i = start; i < end; i++)
    {
        unsigned char c = (unsigned char)nome[i];

        // Letras ASCII A-Z / a-z
        int eh_letra_ascii = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
        int eh_espaco = (c == ' ');
        int eh_hifen_ou_apostrofo = (c == '-' || c == '\'');

        // Qualquer caractere acima de 127 (acentos UTF-8) é aceito
        int eh_letra_acentuada = (c > 127);

        if (!eh_letra_ascii && !eh_letra_acentuada && !eh_espaco && !eh_hifen_ou_apostrofo)
            return 0;
    }

    return 1;
}

#include <stdio.h>

int validar_horario_servico(const char *horario)
{
    int hora, minuto;

    if (sscanf(horario, "%d:%d", &hora, &minuto) != 2)
        return 0;

    if (hora < 8 || hora > 20)
        return 0;
    if (minuto < 0 || minuto > 59)
        return 0;

    if (hora == 20 && minuto > 0)
        return 0;

    return 1;
}

int validar_cpf(const char *cpf)
{
    // Tive ajuda do Chat GPT 4.1 para montar a lógica de validação do CPF
    int i, j, digito1 = 0, digito2 = 0;
    int num[11];
    int tamanho = 0;

    // Remove caracteres não numéricos e verifica tamanho
    for (i = 0, j = 0; cpf[i] != '\0'; i++)
    {
        if (cpf[i] >= '0' && cpf[i] <= '9')
        {
            if (j < 11)
                num[j++] = cpf[i] - '0';
        }
    }
    tamanho = j;
    if (tamanho != 11)
        return 0;

    // Verifica se todos os dígitos são iguais (inválido)
    int todos_iguais = 1;
    for (i = 1; i < 11; i++)
    {
        if (num[i] != num[0])
        {
            todos_iguais = 0;
            break;
        }
    }
    if (todos_iguais)
        return 0;

    // Calcula primeiro dígito verificador
    for (i = 0; i < 9; i++)
        digito1 += num[i] * (10 - i);
    digito1 = 11 - (digito1 % 11);
    if (digito1 >= 10)
        digito1 = 0;

    // Calcula segundo dígito verificador
    for (i = 0; i < 10; i++)
        digito2 += num[i] * (11 - i);
    digito2 = 11 - (digito2 % 11);
    if (digito2 >= 10)
        digito2 = 0;

    // Verifica dígitos
    if (digito1 == num[9] && digito2 == num[10])
        return 1;
    else
        return 0;
}

int validar_telefone(const char *telefone)
{
    int i, j = 0;
    char digitos[12]; // 11 dígitos + '\0'

    // Extrai apenas os dígitos numéricos
    for (i = 0; telefone[i] != '\0'; i++)
    {
        if (telefone[i] >= '0' && telefone[i] <= '9')
        {
            if (j < 11)
                digitos[j++] = telefone[i];
        }
    }
    digitos[j] = '\0';

    // Telefone deve ter 10 (fixo) ou 11 (celular) dígitos
    if (j != 10 && j != 11)
        return 0;

    // DDD não pode começar com 0 ou 1
    if (digitos[0] < '2' || digitos[0] > '9')
        return 0;

    // O terceiro dígito deve ser 9 para celulares
    if (j == 11 && digitos[2] != '9')
        return 0;

    return 1;
}

int validar_cargo(const char *cargo)
{
    if (cargo == NULL)
        return 0;

    if (
        strcasecmp(cargo, "Tarot") == 0 ||
        strcasecmp(cargo, "Signos") == 0 ||
        strcasecmp(cargo, "Numerologia") == 0)
    {
        return 1;
    }
    return 0;
}

int validar_confirmacao(const char *opcao)
{
    if (opcao == NULL)
        return 0;

    if (strcasecmp(opcao, "s") == 0 ||
        strcasecmp(opcao, "n") == 0 ||
        strcasecmp(opcao, "sim") == 0 ||
        strcasecmp(opcao, "nao") == 0 ||
        strcasecmp(opcao, "não") == 0)
        return 1;

    return 0;
}

int cliente_existe(const char *cpf_procurado)
{
    FILE *arq_clientes;
    Cliente clt;
    int encontrado = 0;

    arq_clientes = fopen("clientes/clientes.dat", "rb");
    if (arq_clientes == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes!\n");
        return 0;
    }

    while (fread(&clt, sizeof(Cliente), 1, arq_clientes))
    {
        if ((strcmp(clt.cpf, cpf_procurado) == 0) && (clt.status == 1))
        {
            encontrado = 1;
            break;
        }
    }

    fclose(arq_clientes);
    return encontrado;
}

int buscar_nome_cliente(const char *cpf_procurado, char *nome_cliente)
{
    FILE *arq_clientes;
    Cliente clt;
    int encontrado = 0;

    arq_clientes = fopen("clientes/clientes.dat", "rb");
    if (arq_clientes == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes!\n");
        return 0;
    }

    while (fread(&clt, sizeof(Cliente), 1, arq_clientes))
    {
        if ((strcmp(clt.cpf, cpf_procurado) == 0) && (clt.status == 1))
        {
            strcpy(nome_cliente, clt.nome);
            encontrado = 1;
            break;
        }
    }

    fclose(arq_clientes);
    return encontrado;
}

int validar_data_agendamento(const char *data)
{
    int dia, mes, ano;

    // Pega o ano atual do sistema (usado apenas para validar intervalo)
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int ano_atual = tm.tm_year + 1900;

    // Verifica se a data está no formato correto
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3)
        return 0;

    // Verifica se o ano está em um intervalo aceitável
    if (ano < 1900 || ano > ano_atual + 5) // permite agendar até 5 anos no futuro
        return 0;

    // Verifica se o mês é válido
    if (mes < 1 || mes > 12)
        return 0;

    // Determina o número de dias do mês
    int dias_mes;
    switch (mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        dias_mes = 30;
        break;
    case 2:
        dias_mes = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
        break;
    default:
        dias_mes = 31;
    }

    // Verifica se o dia é válido
    if (dia < 1 || dia > dias_mes)
        return 0;

    return 1; // Data válida
}
