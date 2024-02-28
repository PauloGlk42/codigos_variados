//LISTA DUPLAMENTE ENCADEADA
 
typedef struct NoTag {
	int info;
	struct NoTag *prox;
	struct NoTag *prev;
} no;

no *inicializa_Pilha(no *L) {
	L = NULL;
	return L;
}

void imprime_Lista(no *L) {
	no *P;
	P = L;
	if (L != NULL){
		printf("\n Itens da lista:");	
		do{
			printf("\n %d", P->info);	
			P = P->prox;
		}while(P != L); 
		printf("\n");
	}
}
   
void imprime_inverso(no *L) {
    if (L != NULL) {
        no *P = L->prev; // Começa do último nó

        printf("\nItens da lista em ordem inversa:");
        do {
            printf("\n%d", P->info);
            P = P->prev;
        } while (P != L->prev);
        printf("\n");
    }
}

no *PUSH(no *L, int x) {
	no *N, *ULT;

	N = (no *) malloc (sizeof(no));
	N->info = x;

	if (L == NULL){
		N->prev = N;
		N->prox = N;
	}
	else{
		ULT = L->prev;
		N->prev = ULT;
		L->prev = N;
		N->prox = L;
		ULT->prox = N;
	}
	L = N;
	return L;

}


no *POP(no *L, int *n) {
	no *AUX, *ULT;

	if (L != NULL) {
		AUX = L;
		*n = L->info;

		if (L == L->prev){
			L = NULL;
		}
		else{
			L = L->prox;
			ULT = AUX->prev;
			L->prev = ULT;
			ULT->prox = L;
		}
		free(AUX);
	}
	else{
		*n = -1;
	}
	return L;

}

no *insereFinal_LDEC(no *L, int x) {
    no *N = (no *)malloc(sizeof(no));
    N->info = x;

    if (L == NULL) {
        N->prev = N;
        N->prox = N;
        L = N; 
    } else {
        no *ULT = L->prev; 

        N->prox = L; 
        N->prev = ULT; 
        L->prev = N; 
        ULT->prox = N; 
    }

    return L;
}
