#include "banco.h"
#include <stdio.h>
#include <string.h>

void menu(){
  printf("1. Novo Cliente\n");
  printf("2. Apaga Cliente\n");
  printf("3. Listar Clientes\n");
  printf("4. Débito\n");
  printf("5. Depósito\n");
  printf("6. Extrato\n");
  printf("7. Transferência entre contas\n");
  printf("8. Sair\n");
}
//strcmp compara duas strings: 0 igual, 1 diferentes

void clearBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

void criaCliente(listaClientes *Lt){
  char tipo[5];
  int resul1;
  int resul2;

  if (Lt->quantidade < 1000){
    printf("Digite seu nome: ");
    scanf("%s", Lt->Cliente[Lt->quantidade].nome);
    clearBuffer();
    printf("Digite seu cpf: ");
    fgets(Lt->Cliente[Lt->quantidade].cpf,11,stdin);
    printf("Digite o tipo da sua conta: ");
    scanf("%s",tipo);
    resul1 = strcmp(tipo, "comum");
    resul2 = strcmp(tipo, "plus");
    if (resul1 == 0){
      Lt->Cliente[Lt->quantidade].tipoConta = 0;
        }
    else if (resul2 == 0){
      Lt->Cliente[Lt->quantidade].tipoConta = 1;
    }
    else{
      printf("Erro\n");
      return;
    }
    printf("Digite seu saldo: ");
    scanf("%f", &Lt->Cliente[Lt->quantidade].saldo);
    printf("Digite sua senha(maximo 10): ");
    fgets(Lt->Cliente[Lt->quantidade].senha,10,stdin);
    clearBuffer();
    Lt -> quantidade = Lt -> quantidade + 1;
    printf("\n");
  }
  else{
    printf("Erro ao criar a conta");
  } 
}
  
int deletarCliente(listaClientes *Lt){
int numero = 0;
    printf("Digite o cpf do tarefa que deseja deletar: ");
    scanf("%d",&numero);
    if (Lt->quantidade == 0 || Lt->quantidade <= numero){   
        printf("Falha ao deletar a tarefa :( \n ");
        return 1;
    }
    for (int search = numero - 1; search < Lt->quantidade; search ++ ){
        strcpy(Lt->Cliente[search].cpf, Lt->Cliente[search +1].cpf);
        Lt->Cliente[search].saldo = Lt->Cliente[search +1].saldo;   
        Lt->Cliente[search].tipoConta =Lt->Cliente[search +1].tipoConta;  
        strcpy(Lt->Cliente[search].nome, Lt->Cliente[search +1].nome); 
        strcpy(Lt->Cliente[search].senha, Lt->Cliente[search +1].senha);      
        *Lt->Cliente[search].cpf = Lt->Cliente[search +1].cpf;
        Lt->quantidade--;
    }
    printf("Deletou com sucesso!\n");
    return 0;
}

void clearBuffer();
