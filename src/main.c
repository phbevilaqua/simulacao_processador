#include <stdio.h>
#include "../include/processador.h"  // Cabeçalho para as funções do processador
#include "../include/memoria.h"      // Cabeçalho para as funções de memória

#define TAMANHO_PROGRAMA 5

// Exemplo de um programa com instruções

// Cada instrução será representada por um código de operação e dois operandos
typedef struct {
    Instrucao instrucao;
    int op1;
    int op2;
} Programa;

// Função para carregar o programa na memória
void carregarPrograma(Programa* programa) { //em vez de fazer uma cópia do vetor inteiri, é passado um ponteiro para seu real endereço
    for (int i = 0; i < TAMANHO_PROGRAMA; i++) {
        escreverMemoria(i, programa[i].instrucao); // cada posição de memória terá uma instrução armazenada
    }
}

// Função para executar o programa
void executarPrograma(Programa* programa) {
    for (int i = 0; i < TAMANHO_PROGRAMA; i++) {
        
        Instrucao instrucao = programa[i].instrucao;
        int op1 = programa[i].op1;
        int op2 = programa[i].op2;

        executarInstrucao(instrucao, op1, op2);

        imprimirRegistradores();
    }
}

int main() {

    Programa programa[TAMANHO_PROGRAMA] = {
        {MOV, 5, 10},   // Move o inteiro 10 para o endereço 5 
        {ADD, 0,  5},   // Adiciona 0 + 5 e armazena o valor no ACC
        {SUB, 0,  3},   // Subtrai 0 - 3 e armazena o valor no ACC  
        {JMP, 4,  0},   // Altera o fluxo para a instrução de número 4  
        {LDA, 74,  0},   // Carrega o dado presente no endereço 74 de memória  
    };

    // Carregar o programa na memória
    carregarPrograma(programa);

    // Executar o programa
    executarPrograma(programa);

    return 0;
}

