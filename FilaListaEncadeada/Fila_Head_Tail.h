//FILA - Head e Tail - REPRESENTAÇÃO ENCADEADA

typedef struct NoTag {
	int info;
	struct NoTag *link;
} no;

void inicializa_Fila(no **Head, no **Tail) {
	*Head = NULL;
	*Tail = NULL;
}

void insere_Fila(no **Head, no **Tail,  int x) {
	no *N;

	N = (no *) malloc (sizeof(no));
	N->info = x;
	N->link = NULL;
	
	if (*Tail == NULL){
		*Head = N;
		*Tail = N;
	}
	else {
		(*Tail)->link = N;
		*Tail = N;
	}		
}


void remove_Fila(no **Head, no **Tail, int *n) {
	no *AUX;

	if (*Head != NULL) {
		*n = (*Head)->info;
		AUX = *Head;
		*Head = (*Head)->link;
		free(AUX);
		if (*Head == NULL)
			*Tail = NULL;
	}
}

int verificaSeVazia_Fila(no** Head){
	if (*Head == NULL)
		return 1;
	else
		return 0;
}

void exibe_Fila(no **Head) {
	no *P;
	 
	P = *Head;	
	
	printf("\n Exibe itens da Fila (lista FIFO)");	
	while(P != NULL) {
		printf("\n %d", P->info);	
		P = P->link;
	}
}
