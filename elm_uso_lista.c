#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "lista.c"

int main(){
	NodoInt *lista = NULL;

	lista = listaInt_ingresar(lista,5,10);
	lista = listaInt_ingresar(lista,5,8);
	lista = listaInt_ingresar(lista,1,5);
	lista = listaInt_ingresarEn(lista,6,9,1);
	
	listaInt_imprimir(lista);

	lista = listaInt_borrar(lista);
	return 0;
}
