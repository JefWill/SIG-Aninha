/////  FUNCIONARIO  //////
typedef struct funcionario Funcionario;

struct funcionario
{
    char cpf[15];
    char nome[50];
    char cargo[50];
    char cpf_lido[15];
};

int tela_menu_funcionario(void);
void modulo_funcionario(void);
void cadastrar_funcionario(void);
void buscar_funcionario(void);
void listar_funcionarios(void);
void alterar_funcionario(void);
void excluir_funcionario(void);
