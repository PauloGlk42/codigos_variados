#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LDuplamente_Encadeada.h"

int main(void) {
   no *P = NULL, *F = NULL;
   char choice[10];
   int c, x;
 
   P = inicializa_Pilha(P);
   F = inicializa_Fila(F);
   do {
      printf("\n------------------------------------\n");
      printf("PILHA - LISTA DUPLAMENTE ENCADEADA \n");
      printf("1 - PUSH - INSERE ITEM NA PILHA\n");
      printf("2 - POP - REMOVE ITEM DA PILHA\n");
      printf("3 - IMPRIME ITENS DA PILHA\n");
      printf("------------------------------------\n");
      printf("FILA - LISTA DUPLAMENTE ENCADEADA \n");
      printf("4 - INSERE ITEM NA FILA\n");
      printf("5 - REMOVE ITEM DA FILA\n");
      printf("6 - IMPRIME ITENS DA FILA\n");
      printf("7 - IMPRIME ITENS DA FILA NA ORDEM INVERSA\n");
      printf("------------------------------------\n");
      printf("8 - SAIR\n");
      printf("\nEscolha: ");

      fgets(choice, sizeof(choice), stdin);
      c = atoi(choice);

      switch (c) {
         case 1: 
            printf("Entre com o item a ser inserido na PILHA: ");
            scanf("%d", &x);
            P = PUSH(P, x);
            break;
         case 2:
            x = -1; 
            P = POP(P, &x);
            if (x != -1)
               printf("Item retirado da PILHA: %d\n", x);
            break;
         case 3: 
            printf("\n");
            imprime_Pilha(P);
            break;
         case 4: 
            printf("Entre 

