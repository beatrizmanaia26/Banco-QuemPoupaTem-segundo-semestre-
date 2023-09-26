#include "banco.h"
#include <stdio.h>

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

void clearBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

void criaCliente(cliente *Lt){
  printf("Digite seu nome: ");
  scanf("%s", Lt->nome);
  clearBuffer();
  printf("Digite seu cpf: ");
  fgets(Lt->cpf,11,stdin);
  clearBuffer(); //ERRO
  printf("Digite o tipo da sua conta: ");
  scanf("%d", &Lt->tipoConta);
  printf("Digite seu saldo: ");
  scanf("%f", &Lt->saldo);
  printf("Digite sua senha(maximo 10): ");
  fgets(Lt->senha,10,stdin);
  //oi
  clearBuffer();
}
