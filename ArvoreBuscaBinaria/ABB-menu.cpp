//ÁRVORE DE BUSCA BINÁRIA	
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#include "ABB.h"

int main(void)
{
   no *T, *p;
   int x, c;
   int conta=0;
   no *pmaior, *pmenor;
   
   T=ini_AB(T);
   
   do 
   {
      printf("\n");
      printf("1 - Insere Item na ARVORE DE BUSCA BINARIA\n");
      printf("2 - EMORDEM -  Lista Itens da ARVORE DE BUSCA BINARIA - Em Ordem\n");
      printf("3 - PREORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pre Ordem\n");
      printf("4 - POSORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pos Ordem\n");
      printf("5 - CONTA nos da ARVORE DE BUSCA BINARIA \n");
      printf("6 - APAGA nos da ARVORE DE BUSCA BINARIA \n");
      printf("7 - Encontra MAIOR nos da ARVORE DE BUSCA BINARIA \n");
      printf("8 - Encontra MENOR nos da ARVORE DE BUSCA BINARIA \n");
      printf("9 - Retorna ALTURA da ARVORE DE BUSCA BINARIA \n");
	  printf("10 - ROTACAO A DIREITA - ARVORE DE BUSCA BINARIA \n");
	  printf("11 - ROTACAO A ESQUERDA - ARVORE DE BUSCA BINARIA \n");
	  printf("12 - Remove Item da ARVORE DE BUSCA BINARIA \n");
	  //printf("13 - PERCURSO EM LARGURA da ARVORE DE BUSCA BINARIA \n");
	  printf("14 - Sair\n");
      printf("\n Escolha: ");

      cin >> c;

      switch(c) {
         case 1: 
			cout << " \nEntre com o item a ser inserido: ";
			cin >> x;
			T = insere_AB(T,x); 
			break;
         case 2: 
			emOrdem_AB(T);
 			printf("\n");	
			break;
         case 3: 
  		    preOrdem_AB(T);
 			printf("\n");	
			break;
         case 4: 
  		    posOrdem_AB(T);
 			printf("\n");	
			break;
		case 5: 
			printf("\n %d", conta_AB(T, conta));
			printf("\n");	
			break;
        case 6: 
			T = apaga_AB(T);
			printf("\n");	
			break;
		case 7: 
			p = maior_AB(T);
			printf("\n");
 			cout << p->info;
 			printf("\n");	
			break;
        case 8: 
			p = menor_AB(T);
			printf("\n");
 			cout << p->info;
 			printf("\n");	
			break;
        case 9: 
		    printf("\n %d", altura_AB(T));
			printf("\n");	
			break;
        case 10: 
			T = rodaDireita(T);

			printf("\n");	
			break;
        case 11: 
			printf("\n");	
			break;
		case 12: 
			cout << " \nEntre com o item a ser removido: ";
			cin >> x;
			T = remove_AB(T,x); 
            break;
		case 13: 

            break;
        case 14: 
		    exit(0);
            break;
      };
   } while (c != 14);
}
