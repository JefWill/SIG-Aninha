#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "validacao.h"

// Obtive ajuda de IA - Chagpt GPT-5
int validar_data(const char *data)
{
    int dia, mes, ano;

    // Pega o ano atual do sistema
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int dia_atual = tm.tm_mday;
    int mes_atual = tm.tm_mon + 1;
    int ano_atual = tm.tm_year + 1900;

    // Verifica se a data está no formato correto
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3)
        return 0;

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
