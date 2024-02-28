#include <stdlib.h>

#include <iostream>
using namespace std;

#include "LE.h"

int main(void)
{
   no *L;
   int x=0, c;
 
   L = inicializaLista(L);
   do 
   {
      printf("\n\n");
      printf("LISTA ENCADEADA \n");
      printf("1 - INSERE INICIO\n");
      printf("2 - REMOVE INICIO\n");
      printf("3 - IMPRIME LISTA\n");
      printf("4 - Sair\n");
      printf("\n Escolha: ");

      cin >> c;

      switch (c) {
         case 1: 
			cout << "Entre com o item a ser inserido no INICIO da lista: ";
			cin >> x;
			L = insereInicioLE(L,x);
            break;
         case 2: 
		    L = removeInicioLE(L,&x);
			break;
         case 3: 
  		    imprimeLista(L);
 			break;
         case 4: 
		    exit(0);
            break;
      };
   } while (c != 4);
}
