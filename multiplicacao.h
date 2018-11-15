#include "soma.h"

int CarryMulti(int num1, int num2, int CarryIn) {
	int CarryOut;
	
	if (num1 * num2 + CarryIn >= 10) {
		CarryOut = (num1 * num2 + CarryIn) / 10;
	} else {
		CarryOut = 0;
	}

	return CarryOut;
}

TNUM *MultiPorDigito(TNUM *l, int num) {
	TNUM *p, *res = Inicializa();

	int multi, CarryIn = 0;
	for (p = l; p; p = p->prox) {
		multi = num * p->valor + CarryIn;

		res = Montagem(res, multi % 10);

		CarryIn = CarryMulti(num, p->valor, multi / 10);
	}

	return res;
}

TNUM *MultiTotal(TNUM *lA, TNUM *lB) {
	TNUM *p = lA, *l0 = Inicializa();

	l0 = Montagem(l0, 0);
	TNUM *l1 = MultiPorDigito(lB, p->valor);
	InverteLista(l1);
	
	if (!p->ant && !p->prox) return l1;

	while (p->prox) {
		p = p->prox;

		TNUM *l2 = MultiPorDigito(lB, p->valor);
		InverteLista(l2);
		l2 = AddZero(l0, l2);

		TNUM *lC = SomaTotal(l1, l2);
		InverteLista(lC);

		l0 = Montagem(l0, 0);

		if (p->prox) l1 = lC; else return lC;
	}

}