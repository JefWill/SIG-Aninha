typedef struct servicos Servicos;

int tela_menu_servicos(void);
void modulo_servicos(void);
void perguntas(void);
void dados_usuario_servico(char *cpf);
void cadastra_arquivo_servico(char *cpf, int id);
void listar_servicos(void);

struct servicos {
    char cpf[15];
    int id;
    char data[11];
    char hora[9];
};


/////  SIGNOS  //////
int tela_menu_signos(void);
void modulo_signos(void);
void listar_signos(void);
void exibir_lista_signos(void);
void consultar_signo(void);
void exibir_caracteristicas_signo(int numero);
void compatibilidade(void);
void horoscopo_signo(void);
void exibir_mensagem_signo(int signo);
void calcular_signo(void);
void calcular_signo_pessoa(void);
char *obter_signo(int dia, int mes);

/////  TAROT  //////
void modulo_tarot(void);
void exibir_lista_cartas(void);
void consultar_cartas(void);
int tela_menu_tarot(void);

/////  NUMEROLOGIA  //////
int tela_menu_numerologia(void);
void modulo_numerologia(void);
void descobrir_numero(void);
void exibir_significados(int n);
void significado_numeros(void);
