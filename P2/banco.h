typedef struct{
  float valor;
  char texto[20]; //palavra pequena
}operacao;

typedef struct{
  operacao extrato[100];
  char cpf[11];//número grande
  float saldo;
  int tipoConta;
  char nome[300];
  char senha[10]; //limite do tamanho da senha
  
}cliente;
typedef enum{COMUM, PLUS} tipoConta; //comparação com enum é mais fácil  COMUM = 0, PLUS = 1
typedef enum{err_cria,err_del,err_tipo,err_valor,err_saldo_comum}erros;
void menu();

void criaCliente(cliente *Lt);

void clearBuffer();
