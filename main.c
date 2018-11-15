#include "calculadora.h"

int main(void) {
	TNUM *lA = Inicializa();
	TNUM *lB = Inicializa();

	lA = Encadea(lA, Scanea());
	lB = Encadea(lB, Scanea());

	TNUM *lS = SomaTotal(lA, lB);
	InverteLista(lS);

	TNUM *lM = MultiTotal(lA, lB);

	printf("Soma: ");
	Imprime(lS);
	printf("\n");

	printf("Multiplicação: ");
	Imprime(lM);
	printf("\n");

	return 0;
}

/*
gcc -c estrutura.h
gcc -c scanEprint.h
gcc -c transformacao.h
gcc -c soma.h
gcc -c multiplicacao.h
gcc -c subtracao.h
gcc -c divisao.h
gcc -c calculadora.h
gcc main.c -o teste.exe -lm
./teste.exe
*/