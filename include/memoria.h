#ifndef MEMORIA_H
#define MEMORIA_H

#define TAMANHO_MEMORIA 512 //Define o tamanho da memória 

extern int memoria[TAMANHO_MEMORIA]; //Declara o array global

void inicializarMemoria ();
void escreverMemoria    (int endereco, int valor);
int  lerMemoria         (int endereco);
void visualizarMemoria  (int inicio, int fim);

#endif
