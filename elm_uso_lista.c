#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "lista.c"

void cargar(char depto[])  //esta funcion leera el documento de un departamento y guardara el contenido en una lista ligada
{
	FILE *f;
	char caracter;
	f = fopen(depto,"r");
	if (f == NULL)
			printf("\nError de apertura del archivo. \n\n");
    else{
		    printf("\nEl contenido del archivo de prueba es \n\n");
		    while (feof(f) == 0)
		    {
				caracter = fgetc(f);
				printf("%c",caracter);
		    }
        }
    fclose(f);
}

int main(){
	NodoInt *lista = NULL;
	lista = listaInt_ingresar(lista,5,10);
	lista = listaInt_ingresar(lista,5,8);
	lista = listaInt_ingresar(lista,1,5);
	lista = listaInt_remover(lista,1);
	listaInt_imprimir(lista);
	lista = listaInt_borrar(lista);

	char depto[]="comida.txt";
	cargar(depto);
	return 0;
}
