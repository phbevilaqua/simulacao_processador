#include <stdio.h>
#include <stdbool.h>
#include "../include/memoria.h"

typedef struct {
	int CI;
	int RI;
	int AC;
} Processador;

Processador processador;

typedef enum {
	MOV,
	ADD,
	SUB,
	JMP,
	LDA
} Instrucao;

void inicializarProcessador() {
	processador.CI = 0;
	processador.RI = 0;
	processador.AC = 0;
}

void carregarRegistrador(int registrador, int valor) {

	switch (registrador) {
		case 0:
			if (valor >= 0 && valor <= JMP){
				processador.CI = valor;
			} else {
				printf("Digite um valor válido para instrução. Intervalo válido [0,%d]", LDA);
			}
			break;
		case 1:
			processador.RI = valor;
			break;
		case 2:
			processador.AC = valor;
			break;

		default:
			printf("Registrador %d inválido! digite um registrador no intervalo [0,2].\n", registrador);
			break;
	}
}

void executarInstrucao(Instrucao instrucao, int op1, int op2) {
	bool fluxoNaoAlterado = true; // variável que evita incrementos no CI quando uma instrução do tipo JMP for acionada

	switch (instrucao) {
		case MOV:
			moverDado(op1, op2);
			break;
		case ADD:
			processador.AC = operacoesAritmeticas(op1, op2, 0);
			break;
		case SUB:
			processador.AC = operacoesAritmeticas(op1, op2, 1);
			break;
		case JMP:
			alterarFluxo(op1);
			fluxoNaoAlterado = false;
			break;
		case LDA:
			lerDado(op1);
			break;
		default:
			printf("Instrução %d desconhecida. Digite uma instrução no intervalo [0,2].\n", instrucao);
			break;
	}

	if (processador.CI >= 0 && processador.CI < LDA && fluxoNaoAlterado) {
        	atualizarCI();
    	} else if (processador.CI > LDA) {
		processador.CI = 0;
	}

}

//Operações: 0 para soma, 1 para subtração
int operacoesAritmeticas(int op1, int op2, int operacao) {
	if (operacao == 0) {
		op1 += op2;
		return op1;
	} else if (operacao == 1) {
		op1 -= op2;
		return op1;
	} else {
		printf("Operação inválida!\n");
		return 0;
	}
}

void lerDado(int endereco) {

	if (endereco>=0 && endereco<TAMANHO_MEMORIA) {
                processador.AC = lerMemoria(endereco);
                printf("Valor %d armazenado no registrador ACC.\n", processador.AC);

        } else {
                printf("Endereço %d inválido! Deve estar no intervalo [0, %d].\n", endereco, TAMANHO_MEMORIA - 1);
    }
}

void moverDado(int endereco, int dado) {
	processador.AC = dado;

	if (endereco>=0 && endereco<TAMANHO_MEMORIA) {
		escreverMemoria(endereco, processador.AC);
		printf("Valor %d movido para o endereço %d na memória.\n", processador.AC, endereco);
		
    	} else {
        	printf("Endereço %d inválido! Deve estar no intervalo [0, %d].\n", endereco, TAMANHO_MEMORIA - 1);
    }
}

void alterarFluxo (int novaInstrucao) {
	processador.CI = novaInstrucao;
}

void imprimirRegistradores() {
	printf("\nCI = %d\nRI = %d\nAC = %d\n", processador.CI, processador.RI, processador.AC);
}

void atualizarCI() {
	processador.CI++;
}
