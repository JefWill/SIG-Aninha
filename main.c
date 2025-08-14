
#include <stdio.h>
#include <stdlib.h>


// Assinatura das funções
void tela_menu_principal(void);
void tela_sobre(void);
void tela_equipe(void);

void tela_menu_cliente(void);
void tela_menu_agendamento(void);
void tela_menu_signos(void);
void tela_menu_tarot(void);
void tela_menu_relatorio(void);

int main(void) {
    tela_menu_principal();
    return 0;
}

void tela_menu_principal(void) {
    char op;
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
    printf("|           5. Módulo Relatórios                 |\n");
    printf("|           6. Sobre                             |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("|            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}