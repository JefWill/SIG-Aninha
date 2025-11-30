typedef struct servicos Servicos;

int tela_menu_servicos(void);
void modulo_servicos(void);
void perguntas(void);
void dados_usuario_servico(char *cpf);
void cadastra_arquivo_servico(char *cpf, int id);
void listar_servicos(void);

enum Serv{
    Signos=1,
    Tarot,
    Numerologia,
    Pergunte
};

struct servicos
{
    char cpf[16];
    int id;
    char data[12];
    char hora[9];
};

typedef struct servicosDinamico ServicosDinamico;

struct servicosDinamico
{
    Servicos servico;
    ServicosDinamico* prox;
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
int validar_data_signo(const char *data);

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

void listar_servicos_por_data(void);
void exibir_servicos(const Servicos *srv);
ServicosDinamico* carregar_servicos_por_cpf(void);
void exibir_servicos_por_cpf(ServicosDinamico* lista);