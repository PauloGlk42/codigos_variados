//   _________________________           _____
// |                          \          \ U \__      _____
// |   TRABALHO 2 DE AED       \__________\   \/_______\___\_____________
// |                          /           < /_/   .....................  `-.s
// |_________________________/             `-----------,----,--------------'
//                                                   _/____/

#include <iostream>
#include <fstream>

using namespace std;


struct aviao {
    int codigoVoo;
    int prioridade;
    struct aviao *proximoNo;
};


aviao *inicializafilaAtendimento(aviao *L)
{
    L = NULL;
    return L;
}

aviao *inserefilaAtendimento(aviao *L, int codigo)
{
    aviao *N, *P, *ANT;

    N = new aviao;
    N->codigoVoo = codigo;
    N->prioridade = codigo % 10;

    if (L == NULL) {
        L = N;
        N->proximoNo = NULL;
    }
    else {
        P = L;

        while ((P != NULL) && (N->prioridade >= P->prioridade)) {
            ANT = P;
            P = P->proximoNo;
        }
        if (P == L) {
            N->proximoNo = L;
            L = N;
        }
        else {
            ANT->proximoNo = N;
            N->proximoNo = P;
        }
    }
    return L;
}

aviao *removefilaAtendimento(aviao *L, int *n, int *prioridade) {
    aviao *AUX;

    if (L != NULL) {
        *n = L->codigoVoo;
        *prioridade = L->prioridade;
        AUX = L;
        L = L->proximoNo;
        delete AUX;
    }
    return L;
}

aviao* insereFilaChegada(aviao *L, int codigoVoo) {
    aviao *P, *N;

    int prioridade = codigoVoo % 10;

    N = new aviao;
    N->codigoVoo = codigoVoo;
    N->prioridade = prioridade;
    N->proximoNo = NULL;

    if (L == NULL) {
        L = N;
    }
    else {
        P = L;

        while (P->proximoNo != NULL) {
            P = P->proximoNo;
        }
        P->proximoNo = N;
    }
    return L;
}

int verificaSeVazia(aviao *L) {
    if (L == NULL)
        return 1;
    else
        return 0;
}

void exibe(aviao *L, ofstream &saida) {

    string dados[12] = { "PT-17   ", "A6M Zero", "Piper J3", "Cirrus  ", "Cessna  ", "Sukhoi57",
                        "BoeingAM", "Antonov ", "Pouso", "Decol" };

    int codigo, acao, prioridade, nome;

    aviao *P = L;

    while (P != NULL) {  
        codigo = P->codigoVoo;
        acao = codigo / 10 % 10;
        prioridade = codigo % 10;
        nome = codigo / 100 % 10;

        saida << "| Codigo: " << codigo << " | Aeronave: " << dados[nome] << " | Acao: " << dados[acao] << " | Prioridade: " << prioridade << " |" << endl;
            P = P->proximoNo;
    }
}

int main() {
    
    aviao *filaEntrada, *filaAtendimento;
    int unidadeTemporal, codigoVoo, prioridade, i;
    int continuidade = 1;
    ofstream saida;
    saida.open("fila.txt");
    

    filaEntrada = inicializafilaAtendimento(filaEntrada);
    filaAtendimento = inicializafilaAtendimento(filaAtendimento);

    filaEntrada = insereFilaChegada(filaEntrada, 181);
    filaEntrada = insereFilaChegada(filaEntrada, 294);
    filaEntrada = insereFilaChegada(filaEntrada, 393);
    filaEntrada = insereFilaChegada(filaEntrada, 482);
    filaEntrada = insereFilaChegada(filaEntrada, 594);
    filaEntrada = insereFilaChegada(filaEntrada, 681);
    filaEntrada = insereFilaChegada(filaEntrada, 794);
    filaEntrada = insereFilaChegada(filaEntrada, 293);
    filaEntrada = insereFilaChegada(filaEntrada, 182);
    filaEntrada = insereFilaChegada(filaEntrada, 181);
    filaEntrada = insereFilaChegada(filaEntrada, 294);
    filaEntrada = insereFilaChegada(filaEntrada, 393);
    filaEntrada = insereFilaChegada(filaEntrada, 482);
    filaEntrada = insereFilaChegada(filaEntrada, 594);
    filaEntrada = insereFilaChegada(filaEntrada, 681);
    filaEntrada = insereFilaChegada(filaEntrada, 794);
    filaEntrada = insereFilaChegada(filaEntrada, 293);
    filaEntrada = insereFilaChegada(filaEntrada, 182);
    filaEntrada = insereFilaChegada(filaEntrada, 794);
    filaEntrada = insereFilaChegada(filaEntrada, 293);
    filaEntrada = insereFilaChegada(filaEntrada, 182);
    
    saida << "                               REQUISICOES DE PISTA: " << endl;
    saida << " _________________________________________________________________" << endl;
    exibe(filaEntrada, saida);
    saida << "|_____________|____________________|_____________|_______________|" << endl;
    saida << endl;

    for (unidadeTemporal = 3; continuidade; unidadeTemporal++) {
        saida << "-----------------------------------------------------------------";
        saida << "                                                 UNIDADE DE TEMPO: " << unidadeTemporal-2 << endl;
        for (i = 1; i <= 2; i++) {
            if (!verificaSeVazia(filaEntrada)) {
                filaEntrada = removefilaAtendimento(filaEntrada, &codigoVoo, &prioridade);
                filaAtendimento = inserefilaAtendimento(filaAtendimento, codigoVoo);
            }
        }
        saida << "                        AVIOES DA FILA:" << endl;
        saida << " _________________________________________________________________" << endl;
        exibe(filaAtendimento, saida);
        saida << "|_____________|____________________|_____________|_______________|" << endl;
        saida << endl;

        if (!(unidadeTemporal % 3) && (continuidade)) {
            for (i = 1; i <= 2; i++) {
                if (filaAtendimento != NULL) {
                    filaAtendimento = removefilaAtendimento(filaAtendimento, &codigoVoo, &prioridade);
                    saida << "VOO DE CODIGO " << codigoVoo << " EM PROGRESSO..." << endl;
                    saida << endl;
                }
                else {
                    saida << "SEM REQUISICOES DE PISTA." << endl;
                    saida << endl;
                    continuidade = 0;
                }
            }
            if (!verificaSeVazia(filaAtendimento)) {
                saida << endl;
                saida << "AVIOES DA FILA: " << endl;
                saida << " _________________________________________________________________"<< endl;
                exibe(filaAtendimento, saida);
                saida << "|________________________________________________________________|"<< endl;
                saida << endl;
            }
        }
        else {
            saida << endl;
            saida << "PISTAS AINDA OCUPADAS NO MOMENTO..." << endl;
            saida << endl;
        }
    }

    saida.close();

    return 0;
}
