#include <stdlib.h>
#include <iostream>
#include "Pilha.h"

using namespace std;

struct no {
    int info;
    no *link;
};

int main() {
    no *L;
    int x = 0, c;

    L = inicializaPilha(L);
    do {
        printf("\n\n");
        printf("PILHA \n");
        printf("1 - PUSH\n");
        printf("2 - POP\n");
        printf("3 - IMPRIME PILHA\n");
        printf("4 - IMPRIME ITEM DO TOPO DA PILHA\n");
        printf("5 - Sair\n");
        printf("\n Escolha: ");

        cin >> c;
        switch (c) {
            case 1: 
                cout << "Entre com o item a ser inserido na PILHA: ";
                cin >> x;
                L = PUSH(L, x);
                break;
            case 2: 
                L = POP(L, &x);
                break;
            case 3: 
                imprimePilha(L);
                break;
            case 4: 
                imprimeTopoPilha(L);
                break;
            case 5: 
                exit(0);
                break;
            default:
                cout << "Escolha inválida. Tente novamente." << endl;
                break;
        };
    } while (c != 5);
    
    return 0;
}

