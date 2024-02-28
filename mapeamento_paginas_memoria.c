#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PAGINA 4
#define TAMANHO_MEMORIA_FISICA 16
#define TAMANHO_MEMORIA_VIRTUAL 32
#define NUMERO_PAGINAS (TAMANHO_MEMORIA_VIRTUAL / TAMANHO_PAGINA)

typedef struct {
    int numeroPagina;
    int dados[TAMANHO_PAGINA];
} Pagina;

typedef struct {
    Pagina* paginas[NUMERO_PAGINAS];
} TabelaPaginas;

char memoriaFisica[TAMANHO_MEMORIA_FISICA];

void inicializarMemoriaFisica() {
    for (int i = 0; i < TAMANHO_MEMORIA_FISICA; i++) {
        memoriaFisica[i] = 0;
    }
}

void alocarPagina(Pagina* pagina) {
    int indicePagina = pagina->numeroPagina;
    char* enderecoFisico = memoriaFisica + (indicePagina * TAMANHO_PAGINA);
    memcpy(enderecoFisico, pagina->dados, TAMANHO_PAGINA * sizeof(int));
}

int lerDaMemoriaVirtual(TabelaPaginas* tabelaPaginas, int enderecoVirtual) {
    int indicePagina = enderecoVirtual / TAMANHO_PAGINA;
    int offset = enderecoVirtual % TAMANHO_PAGINA;
    Pagina* pagina = tabelaPaginas->paginas[indicePagina];
    
    if (pagina != NULL) {
        char* enderecoFisico = memoriaFisica + (pagina->numeroPagina * TAMANHO_PAGINA);
        return ((int*)enderecoFisico)[offset];
    }
    
    return -1;
}

int main() {
    TabelaPaginas tabelaPaginas;
    inicializarMemoriaFisica();

    Pagina pagina1 = {0, {0}};
    Pagina pagina2 = {1, {0}};
    Pagina pagina3 = {2, {0}};

    for (int i = 0; i < TAMANHO_PAGINA; i++) {
        pagina1.dados[i] = i + 1;
        pagina2.dados[i] = (i + 1) * 10;
        pagina3.dados[i] = (i + 1) * 100;
    }

    tabelaPaginas.paginas[0] = &pagina1;
    tabelaPaginas.paginas[1] = &pagina2;
    tabelaPaginas.paginas[2] = &pagina3;

    int enderecoVirtual = 7;
    int dados = lerDaMemoriaVirtual(&tabelaPaginas, enderecoVirtual);

    if (dados != -1) {
        printf("Valor lido da memória virtual (endereço %d): %d\n", enderecoVirtual, dados);
    } else {
        printf("Página não presente na memória virtual.\n");
    }

    return 0;
}
