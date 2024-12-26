#include <stdio.h>
#define TAMANHO_MEMORIA 512
#define ENDERECO_INVALIDO -1

int memoriaPrincipal[TAMANHO_MEMORIA]; //Inicializa a memória principal

void inicializarMemoria() { //Popula todas as células da memória
	
	for (int i=0; i<TAMANHO_MEMORIA; i++) {
		memoriaPrincipal[i] = 0;
	}
}

void escreverMemoria(int endereco, int valor) {

	if (endereco<0 || endereco>=TAMANHO_MEMORIA) { //Valida o endereço
		printf("Endereço inválido. O intervalo válido é [0. %d]\n", TAMANHO_MEMORIA-1);
	} else {
		memoriaPrincipal[endereco] = valor; //Popula uma posição específica com o valor recebido
	}
}

int lerMemoria (int endereco) {

	if (endereco<0 || endereco>=TAMANHO_MEMORIA) { //Valida o endereço
		return ENDERECO_INVALIDO;
	} else {
		return memoriaPrincipal[endereco]; //Retorna o valor específico armazenado numa posição determinada
	}
}

void visualizarMemoria (int inicio, int fim) {
	if (inicio<0 || fim>=TAMANHO_MEMORIA || inicio>=fim) {
		printf("Intervalo inválido.\n");
		return;
	}

	for (int i=inicio; i<fim; i++) {
		printf("Posição de memória: %d\nConteúdo: %d\n", i, memoriaPrincipal[i]);

	}
}
