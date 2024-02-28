struct no {
	int info;
	no *link;
};

no *inicializaLista(no *L) {
	return NULL;
}

void imprimeLista(no *L) {
	no *P;
	P = L;	
	
	printf("\n Imprime Itens da lista: \n");	
	while(P != NULL) {
		cout << P->info << " ";	
		P = P->link;
	}	
}

no *insereInicioLE(no *L, int x) {
	no *N;

	N = new no;
	N->info = x;

    N->link = L;
	
	L = N;
	return (L);
}

no *removeInicioLE(no *L, int *n) {
	no *AUX;

	if (L != NULL) {
		*n = L->info;
		AUX = L;
		L = L->link;
		delete AUX;
	}
	else{
		*n = 0;
	}
	return (L);
}

