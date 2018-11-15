#include "transformacao.h"

int CarrySoma(int num1, int num2, int CarryIn) {
	int CarryOut;
	
	if (num1 + num2 + CarryIn >= 10) {
		CarryOut = 1;
	} else {
		CarryOut = 0;
	}
	
	return CarryOut;
}

int Soma(int num1, int num2, int CarryIn) {
	int res = num1 + num2 + CarryIn, soma;
	
	if (res >= 10) {
		soma = res % 10;
	} else {
		soma = res;
	}
	
	return soma;
}

TNUM *SomaTotal(TNUM *lA, TNUM *lB) {
	TNUM *lC = Inicializa();
	
	TNUM *p = lA, *q = lB;
	int CarryOut = 0, res;
	while ((p) && (q)) {
		res = Soma(p->valor, q->valor, CarryOut);
		CarryOut = CarrySoma(p->valor, q->valor, CarryOut);
		
		lC = Montagem(lC, res);

		p = p->prox;
		q = q->prox;
	}

	while (q) {
		res = Soma(0, q->valor, CarryOut);
		CarryOut = CarrySoma(0, q->valor, CarryOut);

		lC = Montagem(lC, res);

		q = q->prox;
	}

	while (p) {
		res = Soma(p->valor, 0, CarryOut);
		CarryOut = CarrySoma(p->valor, 0, CarryOut);

		lC = Montagem(lC, res);

		p = p->prox;
	}

	if (CarryOut && (!p && !q)) lC = Montagem(lC, CarryOut);

	return lC;
}