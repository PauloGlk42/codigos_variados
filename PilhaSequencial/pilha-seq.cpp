#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "Pilha.h"

int main(void){
   pilha p;
   
   int x;
   int c;
   int retorno;

   ini_pi(&p);
   do {
      printf("\n");
      printf("1 - PUSH - Insere Item na Pilha\n");
      printf("2 - POP - Exclui Item da Pilha\n");
      printf("3 - IMPRIME PILHA - Lista Itens da Pilha\n");
      printf("4 - Sair\n");
      printf("\n Escolha: ");

      cin >> c;

      switch (c) {
         case 1: 
            printf(" \nEntre com o item: ");
            cin >> x;
            retorno = empilha(&p,x);
            if (retorno == ERROPILHACHEIA) {
                printf("\n ERRO! PILHA CHEIA! Estouro de memoria! \n");
            }
            else {
                printf("\n Operacao realizada com sucesso! \n");
            }
            break;
         case 2: 
            x = desempilha(&p);
            if (x == ERROPILHAVAZIA){
                cout << "\n ERRO! PILHA VAZIA! Nao ha elementos a retirar! \n";
            }
            else {
                cout << " \nItem retirado: " << x << endl;
            }
            break;
         case 3: 
            retorno = lista_pi(&p);
            if (retorno == ERROPILHAVAZIA) {
                cout << "\n ERRO! PILHA vazia! Nao ha elementos a exibir! \n";
            }
            break;
         case 4: 
            exit(0);
            break;
      };
   } while (c != 4);
}

