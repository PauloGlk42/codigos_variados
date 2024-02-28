#include <stdio.h>
#define TAM 7

#include <iostream>
using namespace std;

int busca_filho_esq(int pos, int *T)
{
    if(pos>0 && (2*pos)<=TAM)
        return 2*pos;
    else
		return -1;
}

int busca_filho_dir(int pos, int *T)
{
    if(pos>0 && ((2*pos)+1)<=TAM)
        return (2*pos)+1;
    else
		return -1;
}

void preordem(int pos, int *T)
{
    if(pos>0 && T[pos]!='\0')
    {
        cout << T[pos] << " - "; 
        preordem(busca_filho_esq(pos, T), T); 
        preordem(busca_filho_dir(pos, T), T); 
    }
}

void posordem(int pos, int *T)
{
    if(pos>0 && T[pos]!='\0')
    {
        posordem(busca_filho_esq(pos, T), T);
        posordem(busca_filho_dir(pos, T), T);
        cout << T[pos] << " - "; 
    }
}

void emordem(int pos, int *T)
{
    if(pos>0 && T[pos]!='\0')
    {
        emordem(busca_filho_esq(pos, T), T);
        cout << T[pos] << " - "; 
        emordem(busca_filho_dir(pos, T), T);
    }
}

void emlargura(int *T) {
  cout << "\n";
  for (int i = 1; i <= TAM; i++) {
    cout << T[i] << " - "; 
  }
}

int imprime_parente(int *T, int x){
  int i;
  printf("\n");
  for (i = 1; (i <= TAM) && (T[i] != x); i++);

  if ( i>1 && i <= TAM){
	cout << " \nPAI: \n" << T[i/2];
	if ((i*2) <= TAM){
		cout << " \nFilho da esquerda: \n" << T[i*2];
  		cout << " \nFilho da direita: \n" << T[(i*2)+1];
  	}
  }
  return 0;
}

int main()
{
	int T[] = {0, 30, 20, 50, 10, 28, 37, 55};
	int x;

    cout << "Preordem:\n";
    preordem(1, T);
    cout << "\nPosordem:\n";
    posordem(1, T);
    cout << "\nEmordem:\n";
    emordem(1, T);
    cout << "\nEm Largura:\n";
    emlargura(T);
    printf("\n");
    
   	cout << " \nEntre com o elemento para imprimir o PAI, FILHO ESQ E FILHO DIR: \n";
    cin >> x;
    imprime_parente(T,x);
    return 0;
}

