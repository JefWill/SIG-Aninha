
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
    tela_sobre();
    tela_equipe();

    tela_menu_cliente();
    tela_menu_agendamento();
    tela_menu_signos();
    tela_menu_tarot();
    tela_menu_relatorio();
    
    return 0;
}
