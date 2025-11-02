/////  FUNCIONARIO  //////
typedef struct funcionario Funcionario;

#define TRUE 1
#define FALSE 0

struct funcionario
{
    char cpf[16];
    char nome[50];
    char cargo[50];
    int status;
};

int tela_menu_funcionario(void);
void modulo_funcionario(void);
void cadastrar_funcionario(void);
void exibir_funcionario(const Funcionario *fnc);
void buscar_funcionario(void);
void listar_funcionarios(void);
void alterar_funcionario(void);
void excluir_funcionario(void);
void excluir_funcionario_fisico(void);
int menu_alteracao_func(void);
void modulo_alteracao_func(char *nome, char *cargo);
int validar_funcionario_por_cargo(const char *cpf, const char *tipo_consulta);
void listar_funcionarios_por_cargo(const char *tipo_consulta, char *cpf_escolhido, char *nome_escolhido);
Funcionario *preenche_funcionario(void);
void ler_cpf_funcionario(char *cpf);
