/////  CLIENTE  //////
#define TRUE 1
#define FALSE 0

typedef struct cliente Cliente;

struct cliente
{
    char cpf[15];
    char nome[50];
    char data_nascimento[12];
    char telefone[20];
    int status;
};

void modulo_cliente(void);
void cadastrar_cliente(void);
int tela_menu_cliente(void);
void buscar_cliente(void);
void listar_clientes(void);
void excluir_cliente(void);
void alterar_cliente(void);
int menu_alteracao(void);
void modulo_alteracao(char *nome, char *data_nascimento, char *telefone);
Cliente *preenche_cliente(void);