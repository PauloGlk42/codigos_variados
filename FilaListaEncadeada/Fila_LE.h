typedef struct NoTag {
    int info;
    struct NoTag *link;
} no;

no *inicializaFila(no *L) {
    return NULL;
}

void exibeFila(no *L) {
    no *P;
    P = L;

    while(P != NULL) {
        printf("%d ", P->info);
        P = P->link;
    }
}

no *insereFila(no *L, int x) {
    no *P, *N;
    N = (no *) malloc (sizeof(no)); 
    N->info = x; 
    N->link = NULL;
    
    if (L == NULL) {
        L = N;
    } else {
        P = L;
        while(P->link != NULL) {
            P = P->link;
        }
        P->link = N;
    } 
    return L;
}

no *removeFila(no *L, int *n) {
    no *AUX;

    if (L != NULL) {
        *n = L->info;
        AUX = L;
        L = L->link;
        free(AUX);
    }
    return L;
}

int verificaSeVazia_Fila(no *L) {
    if (L == NULL)
        return 1;
    else
        return 0;
}

