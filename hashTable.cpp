#include <iostream>

using namespace std;

#define N 10

typedef struct No {
    int valor;
    struct No *prox;
} no;

void startTable(no** ht) {
    for(int i = 0; i < N; i++) {
        ht[i] = NULL;
    }
}

no* startQueue() {
    return NULL;
}

void putInQueue(no **F, int item) {
    no *new_node = new no; 
    new_node->valor = item;
    new_node->prox = NULL;

    if (*F == NULL) {
        *F = new_node;
    } else {
        no *temp = *F;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = new_node;
    }
}

void imprimeLista(no *L) {
    while (L != NULL) {
        cout << L->valor << " ";
        L = L->prox;
    }
}

void exibeTudo(no **v) {
    for (int j = 0; j < N; j++) {
        if (v[j] != NULL) {
            cout << "Posição " << j << ": ";
            imprimeLista(v[j]);
            cout << endl;
        }
    }
}

void removeClass(no** zeta, int valorClasse) {
    if (*zeta == NULL) {
        return;
    }
    
    if ((*zeta)->valor == valorClasse) {
        no* temp = *zeta;
        *zeta = (*zeta)->prox;
        delete temp;
        return;
    }

    no* atual = *zeta;

    while (atual->prox != NULL && atual->prox->valor != valorClasse) {
        atual = atual->prox;
    }

    if (atual->prox == NULL) {
        return;
    }

    no* temp = atual->prox;
    atual->prox = temp->prox;
    delete temp;
}

int main() {
    const int classes = 10;
    no* hashTable[classes];
    startTable(hashTable);
    int contadorColisoes=0;

    int conjuntoValores[20] = {12, 32, 39, 42, 21, 154, 721, 422, 1234, 124, 10, 567, 892, 203, 67, 890, 1784, 90, 87, 45};

    for(int p = 0; p < 20; p++) {
        putInQueue(&hashTable[conjuntoValores[p] % N], conjuntoValores[p]);
        if((hashTable[conjuntoValores[p] % N])!=NULL){
            contadorColisoes++;
        }
    }

    exibeTudo(hashTable);
    
    removeClass(&hashTable, 154);
   

    cout << "colisoes: " << contadorColisoes << endl;
    
    return 0;
}
