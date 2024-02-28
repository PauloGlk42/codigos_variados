#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

#define numMusicas 40

typedef struct Tempo {
    int minutos;
    int segundos;
} Tempo;

typedef struct Musicas {
    string musica;
    Tempo duracao;
    Musicas *proximo;
    Musicas *anterior;
} Musicas;

typedef struct Historico {
    string musica;
    Historico *proximo;
} Historico;

void sugestoesDoArquivo(Musicas *vetorMusicas, int tamanhoVetor) {
    ifstream arquivo("C:\\Users\\paulo\\Desktop\\musicas.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    int indice = 0;
    string linha;
    while (getline(arquivo, linha) && indice < tamanhoVetor) {
        vetorMusicas[indice].musica = linha;
        vetorMusicas[indice].duracao.minutos = (rand() % 7) + 1;
        vetorMusicas[indice].duracao.segundos = (rand() % 59) + 1;
        indice++;
    }

    arquivo.close();
}

int buscarMusica(Musicas *vetorMusicas, int tamanhoVetor, string musicaBuscar) {
    for (int indice = 0; indice < tamanhoVetor; indice++) {
        if (vetorMusicas[indice].musica == musicaBuscar) {
            return indice;
        }
    }
    return -1;
}

Musicas *inicializaEstrutura() {
    return NULL;
}

void adicionarMusica(Musicas *&biblioteca, string musica) {
    Musicas *N = new Musicas;
    N->musica = musica;
    N->duracao.minutos = (rand() % 7) + 1;
    N->duracao.segundos = (rand() % 59) + 1;

    if (biblioteca == NULL) {
        N->anterior = N;
        N->proximo = N;
        biblioteca = N;
    } else {
        Musicas *ULT = biblioteca->anterior;
        N->anterior = ULT;
        N->proximo = biblioteca;
        biblioteca->anterior = N;
        ULT->proximo = N;
    }
}

void exibeNo(Musicas *ponteiro) {
    cout << "Nome: " << ponteiro->musica << endl;
    cout << "Duracao: " << ponteiro->duracao.minutos << ":" << ponteiro->duracao.segundos << endl;
}

Historico *addNoHistorico(Historico *L, string musicaNome) {
    Historico *N = new Historico;
    N->musica = musicaNome;
    N->proximo = L;
    return N;
}

void mostraHistorico(Historico *L) {
    while (L != NULL) {
        cout << L->musica << endl;
        L = L->proximo;
    }
}

int main() {
    char opcao, opcao2, ch, tecla;
    string musicaBuscar;
    int resultadoBusca;
    bool continuidade, continuidade1, continuidade2;
    Musicas *biblioteca = inicializaEstrutura();
    Historico *historico = inicializaEstrutura();
    Musicas arrayMusicasSugestoes[numMusicas];
    continuidade = continuidade1 = continuidade2 = true;
    sugestoesDoArquivo(arrayMusicasSugestoes, numMusicas);

 

    while (continuidade) {
        cout << " __________________________________________________________________________"<< endl;
        cout << "| a = musicas sugeridas | d = busca/historico | b = biblioteca | s = sair |" << endl;
        cout << "---------------------------------------------------------------------------" << endl;

        cin >> opcao;

        switch (opcao) {
            case 'a':
                for (int indice = 0; indice < numMusicas; indice++) {
                    cout << " _______________________________" << endl;
                    cout << "(a = add | b = passar | s = sair)" << endl;
                    cout << " -------------------------------" << endl;
                    cout << arrayMusicasSugestoes[indice].musica << endl;
                    cin >> tecla;
                    system("cls");
                    if (tecla == 'a') {
                        adicionarMusica(biblioteca, arrayMusicasSugestoes[indice].musica);
                    }
                    if (tecla == 's') {
                        break;  
                    }
                }
                break;
            case 'd':
                while (continuidade2) {
                    cout << " _______________________________________" << endl;
                    cout << "{ b = buscar | h = historico | m = menu }" << endl; 
                    cout << " --------------------------------------" << endl;
                    cin >> opcao2;
                    switch (opcao2) {
                        case 'b':
                            cout << "Qual musica deseja buscar? ";
                            while (1) {
                                ch = _getch();                                                     
                                if (ch == '\r')                
                                    break;
                                musicaBuscar += ch;
                            }
                            historico = addNoHistorico(historico, musicaBuscar);
                            resultadoBusca = buscarMusica(arrayMusicasSugestoes, numMusicas, musicaBuscar);
                            if (resultadoBusca == -1) {
                                cout << "Musica nao encontrada" << endl;
                            } else {
                                cout << "Musica encontrada. Acabei de adiciona-la a sua biblioteca :)" << endl;
                                adicionarMusica(biblioteca, arrayMusicasSugestoes[resultadoBusca].musica);
                            }
                            musicaBuscar="";
                            break;
                        case 'h':
                            mostraHistorico(historico);
                            break;
                        case 'm':
                            continuidade2 = false;
                            break;
                    }
                }
                break;
            case 'b':
                cout << " ________________________________________________________________________________" << endl;
                cout << "[ Voltar = 'v' | Play = 'p' | Pausar = 'l' | Avancar = 'a' | Menu Principal = 'm'] " << endl;
                cout << " --------------------------------------------------------------------------------" << endl;
                while (continuidade1) {
                    exibeNo(biblioteca);
                    cin >> opcao2;
                    switch (opcao2) {
                        case 'a':
                            biblioteca = biblioteca->proximo;
                            break;
                        case 'v':
                            biblioteca = biblioteca->anterior;
                            break;
                        case 'p':
                            cout << "Musica tocando" << endl;
                            break;
                        case 'l':
                            cout << "Musica pausada" << endl;
                            break;
                        case 'm':
                            continuidade1 = false;
                            break;
                    }
                }
                break;
            case 's':
                continuidade = false;
                break;
        }
    }

    return 0;
}
