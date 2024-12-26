#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "memoria.h"

// Definição da estrutura do processador
typedef struct {
    int CI; // Contador de instrução
    int RI; // Registrador de instrução
    int AC; // Acumulador
} Processador;

// Declaração da variável global do processador
extern Processador processador;

// Definição do tipo de instrução
typedef enum {
    MOV,  // Mover dado da memória para o registrador
    ADD,  // Adicionar dois operandos
    SUB,  // Subtrair dois operandos
    JMP,  // Alterar o fluxo de execução
    LDA   // Carregar dado da memória no acumulador
} Instrucao;

// Funções do módulo processador
void inicializarProcessador();          // Inicializa o processador
void carregarRegistrador(int registrador, int valor); // Carrega valor no registrador
void executarInstrucao(Instrucao instrucao, int op1, int op2); // Executa uma instrução
int operacoesAritmeticas(int op1, int op2, int operacao); // Executa operações aritméticas
void lerDado(int endereco); // Carrega valor da memória para o acumulador
void moverDado(int endereco); // Move valor do acumulador para a memória
void alterarFluxo(int novoEndereco); // Modifica o contador de instrução
void imprimirRegistradores(); // Exibe os valores dos registradores
void atualizarCI(); // Atualiza o contador de instrução (incrementa)

#endif // PROCESSADOR_H

