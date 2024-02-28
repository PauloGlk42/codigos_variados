#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_Duplamente_Encadeada_Circular.h"

int main(void)
{
    no *L = NULL;
    char aux[10];
    int x, c;
    char choice[10];

    L = inicializa_Pilha(L);
    do 
    {
        printf("\n------------------------------------\n");
        printf("LISTA DUPLAMENTE ENCADEADA CIRCULAR\n");
        printf("1 - INSERE ITEM NO INICIO DA LISTA\n");
        printf("2 - REMOVE ITEM DO INICIO DA LISTA\n");
        printf("3 - INSERE ITEM NO FINAL DA LISTA\n");
        printf("4 - Imprime Itens da LISTA\n");
        printf("5 - Imprime Inverso da LISTA\n");
        printf("\n------------------------------------\n");
        printf("6 - SAIR\n");
        printf("\n Escolha: ");

        fgets(choice, sizeof(choice), stdin);
        c = atoi(choice);

        switch (c) {
            case 1: 
                printf(" \nEntre com o item a ser inserido no INÍCIO da LISTA: ");
                fgets(aux, sizeof(aux), stdin);
                x = atoi(aux);
                L = PUSH(L, x);
                break;
            case 2: 
                L = POP(L, &x);
                if (x != -1)
                    printf(" \nItem retirado do INÍCIO da LISTA: %d", x);
                break;
            case 3: 
                printf(" \nEntre com o item a ser inserido no FINAL da LISTA: ");
                fgets(aux, sizeof(aux), stdin);
                x = atoi(aux);
                L = insereFinal_LDEC(L, x);
                break;
            case 4: 
                printf("\n");
                imprime_Lista(L);
                break;
            case 5: 
                printf("\n");
                imprime_inverso(L);
                break;
            case 6: 
                exit(0);
                break;
            default:
                printf("\nEscolha inválida. Tente novamente.\n");
                break;
        };
    } while (c != 6);

    return 0;
}
