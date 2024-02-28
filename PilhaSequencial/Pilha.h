#ifndef PILHA_H
#define PILHA_H

#define MAXSIZE 5

#define ERROPILHACHEIA -1
#define ERROPILHAVAZIA -2

typedef struct {
    int topo;
    int item[MAXSIZE];
} pilha;

void ini_pi(pilha *p) {
    p->topo = 0;
}

int vazia_pi(pilha *p) {
    return (p->topo == 0);
}

int cheia_pi(pilha *p) {
    return (p->topo == MAXSIZE);
}

int empilha(pilha *p, int x) {
    if (cheia_pi(p)) {
        return (ERROPILHACHEIA);
    } else {
        p->item[p->topo] = x;
        p->topo++;
        return (p->topo);
    }
}

int desempilha(pilha *p) {
    if (vazia_pi(p)) {
        return (ERROPILHAVAZIA);
    } else {
        p->topo--;
        return p->item[p->topo];
    }
}

int lista_pi(pilha *p) {
    int i;
    if (vazia_pi(p)) {
        return (ERROPILHAVAZIA);
    } else {
        printf("\nItens da PILHA\n");
        for (i = (p->topo - 1); i >= 0; i--) {
            printf("%d\n", p->item[i]);
        }
        return 1;
    }
}

