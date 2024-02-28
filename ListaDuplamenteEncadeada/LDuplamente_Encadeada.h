no *inicializa_Pilha(no *L) {
    L = NULL;
    return L;
}

no *PUSH(no *L, int x) {
    no *N;
    N = (no *) malloc (sizeof(no));
    N->info = x;
    N->prev = NULL;
    N->prox = L;
    if (L != NULL)
        L->prev = N;
    L = N;
    return L;
}

no *POP(no *L, int *n) {
    no *AUX;
    if (L != NULL) {
        *n = L->info;
        AUX = L;
        L = L->prox;
        if (L != NULL)
            L->prev = NULL;
        free(AUX);
    }
    return L;
}

void imprime_Pilha(no *L) {
    no *P;
    P = L;
    printf("\n Itens da Pilha (lista LIFO):");    
    while(P != NULL) {
        printf("\n %d", P->info);    
        P = P->prox;
    }
    printf("\n");
}

no *inicializa_Fila(no *L) {
    L = NULL;
    return L;
}

no *insere_Final_Fila(no *L, int x) {
    no *N, *P;
    N = (no *) malloc (sizeof(no));
    N->info = x;
    N->prox = NULL;
    if (L == NULL)
        return N;
    P = L;
    while (P->prox != NULL)
        P = P->prox;
    P->prox = N;
    return L;
}

no *remove_Inicio_Fila(no *L, int *n) {
    no *AUX;
    if (L != NULL) {
        *n = L->info;
        AUX = L;
        L = L->prox;
        free(AUX);
    }
    return L;
}

void imprime_Fila(no *L) {
    no *P;
    P = L;
    printf("\n Itens da Fila (lista FIFO):");    
    while(P != NULL) {
        printf("\n %d", P->info);    
        P = P->prox;
    }
    printf("\n");
}

void imprime_Inverso_Fila(no *L) {
    no *P;
    P = L;
    printf("\n Itens da Fila em Ordem Inversa:");    
    while(P->prox != NULL) {
        P = P->prox;
    }
    while(P != NULL) {
        printf("\n %d", P->info);    
        P = P->prev;
    }
    printf("\n");
}

