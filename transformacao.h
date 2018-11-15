#include "scanEprint.h"

TNUM *Encadea(TNUM *l, char *string) {
	int i;
	for (i = 0; i < strlen(string); i++) l = Montagem(l, string[i] - 48);

	return l;
}

void InverteLista(TNUM *l) {
	TNUM *p = l, *q = l;

	int tam = 1;
	while (p->prox) {
		p = p->prox;
		tam++;
	}

	int i = 0;
	while (i < tam / 2) {
		int temp = p->valor;
		p->valor = q->valor;
		q->valor = temp;

		p = p->ant;
		q = q->prox;

		i++;
	}

}