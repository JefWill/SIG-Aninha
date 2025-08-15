
#include <stdio.h>
#include <stdlib.h>


// Assinatura das funções
void tela_menu_principal(void);
void tela_menu_informacoes(void);

void tela_menu_cliente(void);
void tela_menu_agendamento(void);
void tela_menu_signos(void);
void tela_menu_tarot(void);
void tela_menu_numerologia(void);
void tela_sobre(void);
void tela_equipe(void);
void tela_menu_relatorio(void);

int main(void) {
    tela_menu_principal();
    tela_menu_informacoes();
    tela_menu_cliente();
    tela_menu_signos();
    tela_menu_numerologia();
    tela_menu_relatorio();
    tela_sobre();
    tela_equipe();
    tela_menu_cliente();
    tela_menu_agendamento();
    tela_menu_tarot();
  
    return 0;
}


/// FUNÇÕES: ///

void tela_menu_informacoes(void) {
    system("clear||cls");

    char op_info;
    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("| ✦✧✦✧✦  SIG-Aninha - Módulo Informações  ✦✧✦✧✦ |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("|          1 - Informações sobre o Projeto           |\n");
    printf("|          2 - Informações sobre a Equipe            |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("           Escolha a opção desejada: ");
    scanf("%c", &op_info);
    printf("\n");
    printf("        >>> Tecle <ENTER> para continuar... <<<      \n");
    getchar();
}

void tela_menu_principal(void) {
    char op; //isso é a variável de opção principal
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
    printf("|            Escolha a opção desejada:           |");
    scanf("%c", &op); //o scan é basicamente o input do python, o "C"
    getchar();
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_menu_cliente(void) {
    char op_cliente;  //aqui cria uma variável de opção só pro modulo de cliente
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧✦ SIG-Aninha - Módulo Cliente   ✦✧✦✧✦ |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Cadastrar Cliente                 |\n");
    printf("|           2. Buscar cliente                    |\n");
    printf("|           3. Listar Clientes                   |\n");
    printf("|           4. Atualizar Cliente                 |\n");
    printf("|           5. Excluir Cliente                   |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("|            Escolha a opção desejada: ");
    scanf("%c", &op_cliente);
    getchar();
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_menu_signos(void) {
    char op_signos;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧✦   SIG-Aninha - Módulo signos  ✦✧✦✧✦ |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Listar Signos                     |\n");
    printf("|           2. Consultar Signo                   |\n");
    printf("|           3. Consultar Compatibilidade         |\n");
    printf("|           4. Gerar Horoscopo Diário            |\n");
    printf("|           5. Calcular Signo                    |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("|            Escolha a opção desejada:           |");
    scanf("%c", &op_signos);
    getchar();
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();    
}

void tela_menu_tarot(void) {
    char op_tarot;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧✦   SIG-Aninha - Módulo tarot   ✦✧✦✧✦ |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Menu Cartas                       |\n");
    printf("|           2. Menu Consultas tarot              |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("|            Escolha a opção desejada:           |");
    scanf("%c", &op_tarot);
    getchar();
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();    
}

void tela_menu_agendamento(void) {
    char op_agendamento;
    system("clear||cls");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                |\n");
    printf("| ✦✧✦✧ SIG-Aninha - Módulo agendamento ✧✦✧✦  |\n");
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|           1. Agendar consulta                  |\n");
    printf("|           2. Atualizar agendamento             |\n");
    printf("|           3. Listar agendamentos (no dia)      |\n");
    printf("|           4. Buscar agendamento por cliente    |\n");
    printf("|           5. Cancelar agendamento              |\n");
    printf("|           0. Sair                              |\n");
    printf("|                                                |\n");
    printf("|            Escolha a opção desejada:           |");
    scanf("%c", &op_agendamento);
    getchar();
    printf("|                                                |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n/\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  
}

void tela_sobre(void) {
    system("clear||cls");

    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|           ✦✧✦✧✦  SIG-Aninha - Cigana Vitual  ✦✧✦✧✦             |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
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
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("\n");
    printf("                   >>> Tecle <ENTER> para continuar... <<<            \n");
    getchar();
}


void tela_equipe(void) {
    system("clear||cls");

    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                                     |\n");
    printf("|           ✦✧✦✧✦  SIG-Aninha - Cigana Vitual  ✦✧✦✧✦             |\n");
    printf("|                                                                     |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
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
    printf("|                    ✦✧✦✧✦  EQUIPE  ✦✧✦✧✦                        |\n");
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
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("\n");
    printf("                   >>> Tecle <ENTER> para continuar... <<<            \n");
    getchar();
}

void tela_menu_numerologia(void) {
    system("clear||cls");

    char op_num;
    printf("\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("| ✦✧✦✧✦  SIG-Aninha - Módulo Numerologia  ✦✧✦✧✦ |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("|                                                    |\n");
    printf("|          1. Descobrir qual é o seu Número          |\n");
    printf("|          2. Significado dos Números                |\n");
    printf("|          0. Voltar para o menu Principal           |\n");
    printf("|                                                    |\n");
    printf("☽☉☾━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━☽☉☾\n");
    printf("           Escolha a opção desejada: ");
    scanf("%c", &op_num);
    printf("\n");
    printf("        >>> Tecle <ENTER> para continuar... <<<      \n");
    getchar();
}