
# Simulador de Processador

Este projeto implementa um **simulador de processador** simples em C, com a finalidade de simular a execução de um conjunto limitado de instruções em um processador básico. Ele inclui operações como mover dados entre registradores, operações aritméticas, controle de fluxo, leitura e escrita na memória.

## Funcionalidades

- **Registradores**: Manipulação de três registradores básicos:
  - **CI** (Contador de Instrução)
  - **RI** (Registrador de Instrução)
  - **AC** (Acumulador)

- **Operações Aritméticas**: Implementação de operações básicas como soma e subtração, com base nas instruções `ADD` e `SUB`.

- **Controle de Fluxo**: Suporte para a instrução `JMP`, que altera o fluxo de execução do programa.

- **Memória**: Simulação de uma memória principal onde as instruções e dados podem ser lidos e escritos.

- **Execução de Programas**: Capacidade de carregar um programa simples na memória e executar as instruções sequencialmente.

## Tecnologias Usadas

- **Linguagem de Programação**: C
- **Bibliotecas**: `stdio.h` (para entrada e saída de dados)
		   `stdbool.h` (para uso de booleanos)

## Instalação

1. Clone este repositório para o seu computador:

   ```bash
   git clone https://github.com/seu_usuario/seu_repositorio.git
   ```

2. Navegue até o diretório do projeto:

   ```bash
   cd seu_repositorio
   ```

3. Compile o código com o comando:

   ```bash
   gcc -o simulador simulador.c
   ```

4. Execute o simulador:

   ```bash
   ./simulador
   ```

## Como Usar

1. O simulador pode ser configurado para carregar um programa simples, que é uma sequência de instruções, cada uma com seus parâmetros.

2. Exemplo de programa:

   ```c
   Programa programa[TAMANHO_PROGRAMA] = {
       {MOV, 0, 10},  // MOV para o registrador AC
       {ADD, 0, 5},   // ADD
       {SUB, 0, 3},   // SUB
       {JMP, 4, 0},   // JMP
       {LDA, 0, 0}    // LDA
   };
   ```

3. As instruções disponíveis são:

   - **MOV**: Move um valor para o registrador AC.
   - **ADD**: Adiciona um valor e o armazena no AC.
   - **SUB**: Subtrai um valor e o armazena no AC.
   - **JMP**: Altera o fluxo de execução.
   - **LDA**: Carrega um valor da memória para o AC.

4. O simulador vai executar as instruções conforme definidas no programa, com a memória e os registradores sendo manipulados.

## Estrutura do Código

- **memoria.c**: Contém as funções de manipulação da memória (leitura e escrita).
- **processador.c**: Implementa a lógica de execução do processador, incluindo registradores e instruções.
- **ciclo_instrucoes.c**: Controla a execução sequencial das instruções.
- **main.c**: Função principal que orquestra a execução do programa.

## Contribuindo

Se você quiser contribuir para o projeto, fique à vontade para enviar um *pull request*. Se tiver sugestões, melhorias ou correções, sinta-se à vontade para abrir uma *issue*.

1. Faça um fork deste repositório.
2. Crie uma nova branch:
   ```bash
   git checkout -b minha-feature
   ```
3. Realize suas modificações e faça commit:
   ```bash
   git commit -m 'Adiciona nova funcionalidade'
   ```
4. Envie para o seu repositório remoto:
   ```bash
   git push origin minha-feature
   ```
5. Abra um pull request.

## Licença

Este projeto está licenciado sob a [Licença MIT](https://opensource.org/licenses/MIT).

## Contato

Desenvolvido por [Pedro Henrique de Souza Bevilaqua](https://github.com/phbevilaqua).
