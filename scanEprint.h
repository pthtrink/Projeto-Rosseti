#include "estrutura.h"

char *Scanea(void) {
	char *string = (char *) malloc (sizeof(char) * 1000);

	printf("Número: ");
	scanf(" %s", string);
	
	return string;
}

void Imprime(TNUM *l) {
	if (l) {
		Imprime(l->prox);
		printf("%d", l->valor);
	}
}