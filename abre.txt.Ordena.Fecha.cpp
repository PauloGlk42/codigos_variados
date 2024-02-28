#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int buscaBinaria(int x, int *v, int n);

void troca(int *menor, int *i){
    int aux;
    aux = *menor;
    *menor = *i;
    *i = aux;
}
void bubble(int *vetor, int N) {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vetor[j] > vetor[j+1]) {
                troca(&vetor[j], &vetor[j+1]);
            }
        }
    }
}
int buscaBinaria(int x, int *v, int n){
    int inicio = 0;
    int fim = n-1;
    while(inicio<=fim){
        int meio = (inicio + fim)/2;
        if(v[meio]==x)
            return meio;
        if(v[meio] < x)
            inicio = meio+1;
        else 
            fim=meio;
    }
    return -1;
}
int manipularArq(int x){
    string linha;
    int valor, N = 0;

    ifstream arquivo("C:\\Users\\Desktop\\arquivo.txt");
    if (!arquivo) {
        cout << "Erro ao abrir arquivo" << endl;
        return -1;
    }

    int *vetor = nullptr;

    getline(arquivo, linha);                    
    istringstream iss(linha);                    
    while (iss >> valor) {                                //
        N++;
        int *novoVetor  = new int[N];
        for (int i = 0; i < N - 1; i++){
            novoVetor[i] = vetor[i];
        }
        novoVetor[N - 1] = valor;
        delete[] vetor;
        vetor = novoVetor;
    }
    arquivo.close();

    bubble(vetor, N);

    int posicao = buscaBinaria(x, vetor, N);

    ofstream arquivo_saida("C:\\Users\\Desktop\\arquivo.txt", ios::out | ios::trunc);
    for (int i = 0; i < N; i++) {
        arquivo_saida << *(vetor + i) << " ";
    }
    arquivo_saida << "buceta kkk";
    arquivo_saida.close();

    delete[] vetor;
    vetor=NULL;

    return posicao;
}
int main(){
    int x;
    cout << "Elemento: ";
    cin >> x;
    int posicao = manipularArq(x);
    if (posicao != -1) {
        cout << "Elemento encontrado na posicao " << posicao << endl;
    } else {
        cout << "Elemento nao encontrado" << endl;
    }
    return 0;
}
