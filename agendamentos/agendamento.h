/////  AGENDAMENTO  //////
typedef struct agendamento Agendamento;

struct agendamento
{
    char cpf[15];
    char nome[50];
    char tipo_consulta[20];
    char data[15];
    char horario[10];
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