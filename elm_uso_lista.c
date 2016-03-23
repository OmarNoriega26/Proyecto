#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "lista.c"
int main(){
	NodoInt *lista = NULL;

	lista = listaInt_ingresar(lista,5,5,"leche");
	lista = listaInt_ingresar(lista,6,6,"pan");
	lista = listaInt_ingresar(lista,7,7,"huevo");
	lista = listaInt_ingresar(lista,8,8,"piña");
	lista = listaInt_ingresar(lista,4,4,"pera");

	lista = listaInt_ingresarEn(lista,4,4,"pera",3);

	
	listaInt_imprimir(lista);
	return 0;
}
