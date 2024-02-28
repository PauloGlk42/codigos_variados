//typedef struct TreeNo {
	int info;
	struct TreeNo *Llink;
	struct TreeNo *Rlink;
} no;

no *ini_AB(no *T) {
	return NULL;
}
no *insere_AB(no *T, int x) {
	if (T == NULL){
		T = (no *) malloc (sizeof(no));
		T->info = x;
		T->Llink = NULL;
		T->Rlink = NULL;
		return T;
	}
	else {
		if (x < T->info) 
			T->Llink = insere_AB(T->Llink, x);
		else {	 
			T->Rlink = insere_AB(T->Rlink, x);
		}
		return T;
	}
}
void emOrdem_AB(no *T) {
	if(T != NULL) {
		emOrdem_AB(T->Llink);
		printf("\n %d", T->info);	
		emOrdem_AB(T->Rlink);
	}
}
void preOrdem_AB(no *T) {
	if(T != NULL) {
		printf("\n %d", T->info);	
		preOrdem_AB(T->Llink);
		preOrdem_AB(T->Rlink);
	}
}
void posOrdem_AB(no *T) {
	if(T != NULL) {
		posOrdem_AB(T->Llink);
		posOrdem_AB(T->Rlink);
		printf("\n %d", T->info);	
	}
}
int conta_AB(no *T, int x) {
	if(T != NULL) {
		x++;
		x=conta_AB(T->Llink, x);
		x=conta_AB(T->Rlink, x);	
	}
	return x;
}
void conta_AB(no *T, int *x) {
	if(T != NULL) {
		(*x)++;
		conta_AB(T->Llink, x);
		conta_AB(T->Rlink, x);	
	}
} 
no *apaga_AB(no *T) {
	no *p;
	if(T != NULL) {
		apaga_AB(T->Llink);
		apaga_AB(T->Rlink);
		printf("apagando - %d - ", T->info);
		p = T;	
		free(p);
		T = NULL;		
	}
	return T;
}
no *maior_AB(no *T) {
    no *p;
	if (T != NULL) {
		while (T->Rlink != NULL){
			T = T->Rlink;
		}
		return T;  
	}
	else
		return NULL;
}
no *maior_AB(no *T) {
	no *p;
 	if (T != NULL){
 		if(T->Rlink != NULL)
			p = maior_AB(T->Rlink);
		else
			p=T;
		return p;
	}
}
no *menor_AB(no *T) {
    no *p;
	if (T !=NULL) {
		while (T->Llink != NULL){
			T = T->Llink;
		}
			return T;  
	}
	else
		return NULL;
}
int altura_AB(no *T) {
	int aL, aR;
		
	if(T == NULL) {
		return -1;
	}
	else {
		aL = altura_AB(T->Llink);
		aR =  altura_AB(T->Rlink);
		if (aL < aR){
			return (aR+1);
		}
		else{
			return (aL+1);
		}
	}
}
no *remove_AB(no *T, int x){
	no *p;

	if (T == NULL) {
		return NULL;
	}
	else{
		if (x < T->info)
			T->Llink = remove_AB(T->Llink, x);
		else {
			if (x > T->info)
				T->Rlink = remove_AB(T->Rlink, x);
			else {
				if ((T->Llink == NULL) && (T->Rlink == NULL)){
					p = T;
					free(p);
					T = NULL;
					return T;
				}
				else{
					if (T->Llink == NULL){ 
						p = T;
						T = T->Rlink;
						free(p);
						return T;
					}
					else{
						if (T->Rlink == NULL){ 
							p = T;
							T = T->Llink;
							free(p);
							return T;
						}
						else { 
							p = maior_AB(T->Llink);
							T->info = p->info;
							T->Llink = remove_AB(T->Llink,p->info);
						}
					}
				}
			}
		}
	}
}
no *rodaDir(no *T, int x){
	if (T == NULL) {
		return NULL;
	}
	else{
		if (x < T->info)
			T->Llink = rodaDir(T->Llink, x);
		else {
			if (x > T->info)
				T->Rlink = rodaDir(T->Rlink, x);
			else {
			    no *temp, *q;
				q = T->Llink;
				temp = q->Rlink;
				q->Rlink = T;
				T->Llink = temp;
				return q;
			}
		}
	}
}
no *busca(no *T, int x) {
	no *p;
	if(T == NULL){
		return NULL;
    }
	else {
		if (T->info == x)
			return T;
		else{
			if (x < T->info){
				p = (busca(T->Llink, x));
				return p;
			}
			else{
				p = (busca(T->Rlink, x));
				return p;
			}
		}
	}
} 
no *imprime_PAI_rec(no *T, int x) {
	no *p;
	if(T == NULL){
		return NULL;
    }
	else {
		if (T->info == x)
			return T;
		else{
			if (x < T->info){
				p = (imprime_PAI_rec(T->Llink, x));
				if (T->Llink->info == x)
					cout << "PAI:" << T->info;
				return p;
			}
			else{
				p = (imprime_PAI_rec(T->Rlink, x));
				if (T->Rlink->info == x)
					cout << "PAI:" << T->info << " \n";
				return p;
			}
		}
	}
} 
no *imprime_PAI(no *T, int x) {
	no *p=NULL;
	while ((T!=NULL) && (T->info != x)){
		p = T;
		if (x < T->info) 
		    T = T->Llink;
		else
			T = T->Rlink;
	}
	if ((T!=NULL) && (p!=NULL))
		cout << " \nPAI: " << p->info << " \n";
} 



