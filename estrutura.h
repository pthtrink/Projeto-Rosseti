#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct num {
	int valor;
	struct num *ant, *prox;
} TNUM;

/*
typedef struct sinal {
	TNUM *prim;
} TSINAL;
*/

TNUM *Inicializa(void) {
	return NULL;
}

TNUM *Montagem(TNUM *l, int elem) {
	TNUM *novo = (TNUM *) malloc (sizeof(TNUM));

	novo->valor = elem;
	novo->ant = NULL;
	novo->prox = l;
	if (l) l->ant = novo;
	
	return novo;
}

void Libera(TNUM *l) {
	TNUM *p = l, *q;
	while (p) {
		q = p;
		p = p->prox;
		free(q);
	}
}

TNUM *AddZero(TNUM *l0, TNUM *l) {
	TNUM *p = l0;
	while (p->prox) p = p->prox;
	p->prox = l;

	return l0;
}