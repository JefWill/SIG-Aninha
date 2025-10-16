/////  AGENDAMENTO  //////
typedef struct agendamento Agendamento;

#define TRUE 1
#define FALSE 0

struct agendamento
{
    int id;
    char cpf[15];
    char nome[50];
    char tipo_consulta[20];
    char cpf_funcionario[15];
    char nome_funcionario[50];
    char data[15];
    char horario[10];
    int status;
};

int tela_menu_agendamento(void);
void modulo_agendamentos(void);
void agendar_consulta(void);
void atualizar_agendamento(void);
void listar_agendamentos(void);
void buscar_agendamento_por_cpf(void);
void excluir_agendamento(void);
int gerar_novo_id();
int menu_alterar_agendamento(void);
void modulo_alteracao_agend(char *nome, char *tipo_consulta, char *data, char *horario);
void exibir_agendamento(const Agendamento *agd);