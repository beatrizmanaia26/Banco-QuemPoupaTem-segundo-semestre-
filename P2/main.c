#include <stdio.h>
#include "banco.h"

int main(void) {
  char arquivo[]= "tarefa";
  listaClientes Lt;
  int opcao;
  do{
    menu();
    printf("Digite o número de sua escolha: ");
    scanf("%d",&opcao);
    switch(opcao){
      case 1 :
        criaCliente(&Lt);
        break;
      case 3 :
        listaCliente(Lt);
        break;
      
    }
    
  }while(opcao != 0);
  
  
  return 0;
}