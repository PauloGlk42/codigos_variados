#include <iostream>

using namespace std;

typedef struct{
    string nome;
    int serie;
    float nota;
} Alunos;

float media(Alunos *ptr, int quantalunos){
    float soma = 0.0;
    for(int i=0; i<quantalunos; i++){
        soma += ptr->nota;
        ptr++;
    }
    return soma/quantalunos;
}
void preenche(Alunos *ptr, int quantalunos){
    for(int i=0; i<quantalunos; i++){
        cout << "Nome: ";
        cin >> ptr->nome;
        cout << "Serie: ";
        cin >> ptr->serie;
        cout << "Nota: "; 
        cin >> ptr->nota;
        ptr++;
    }
}
int main()
{   
    int quantalunos;
    Alunos *ptr;
    
    cout << "Digite a quantidade de alunos: " << endl;
    cin >> quantalunos;
    
    if (!(ptr = new(nothrow) Alunos[quantalunos])){
        cout << "Falha de alocacao de memoria" << endl;
        return -1;
    }
    
    preenche(ptr, quantalunos);
    cout << media(ptr, quantalunos);
    
    delete[] ptr;
    ptr = NULL;
    return 0;
}
