#include "ListaLigInt.h"

/*Estructura nodoInt
	Guarda un nodo para una lista ligada de enteros.
		valor - Valor almacenado
		sig   - Apuntador al siguiente nodo de la lista
*/


/*Funci�n listaInt_ingresar
	Agrega un valor al final de la lista.
*/
NodoInt* listaInt_ingresar(NodoInt *inicio, int c, int v){
	NodoInt *nodoActual = inicio;
	if(inicio==NULL){
		nodoActual = malloc(sizeof(NodoInt));
		nodoActual->canti = c;
		nodoActual->valor = v;
		nodoActual->sig = NULL;
		inicio = nodoActual;
	}
	else{
		while(nodoActual->sig != NULL){
			nodoActual = nodoActual->sig;
		}
		NodoInt *nuevoNodo = malloc(sizeof(NodoInt));
		nuevoNodo->canti = c;
		nuevoNodo->valor = v;
		nuevoNodo->sig = NULL;
		nodoActual->sig = nuevoNodo;
	}
	return inicio;
}


/*Funci�n listaInt_ingresarEn
	Agrega un valor en una posici�n en especifico de la lista.
*/
NodoInt* listaInt_ingresarEn(NodoInt *inicio,int c, int v, unsigned int indice){
	NodoInt *nodoActual = inicio;
	if(inicio==NULL || indice == 0){
		nodoActual = malloc(sizeof(NodoInt));
		nodoActual->canti = c;
		nodoActual->valor = v;
		nodoActual->sig = inicio;
		inicio = nodoActual;
	}
	else{
		NodoInt *anterior = inicio;
		int i = 0;
		while(i<indice && nodoActual != NULL){
			anterior = nodoActual;
			nodoActual = nodoActual->sig;
			i++;
		}
		NodoInt *nuevoNodo = malloc(sizeof(NodoInt));
		nodoActual->canti = c;
		nodoActual->valor = v;
		nuevoNodo->sig = nodoActual;
		anterior->sig = nuevoNodo;
	}
	return inicio;
}

/*Funci�n listaInt_obtener
	Obtiene un valor en una posici�n en especifico de la lista.
*/
int listaInt_obtener(NodoInt *inicio, unsigned int indice){
	NodoInt *nodoActual = inicio;
	int i = 0;
	if(inicio==NULL){
		return 0;
	}
	while(i<indice && nodoActual->sig != NULL){
		nodoActual = nodoActual->sig;
		i++;
	}
	return nodoActual->valor;
}

/*Funci�n listaInt_imprimir
	Imprime en pantalla todos los datos de la lista
*/
void listaInt_imprimir(NodoInt *inicio){
	NodoInt *nodoActual = inicio;
	int i =0;
	while(nodoActual != NULL){
		printf("Producto: %d 	Valor: %d  	Cantidad %d\n",i++,nodoActual->valor,nodoActual->canti);
		nodoActual = nodoActual->sig;
	}
	printf("---------------\n");
}

/*Funci�n listaInt_remover
	Remueve un valor en una posici�n en especifico de la lista.
*/
NodoInt* listaInt_remover(NodoInt *inicio, unsigned int indice){
	NodoInt *nodoActual = inicio;
	if(inicio==NULL){
		return NULL;
	}
	else if(indice == 0){
		nodoActual = inicio->sig;
		free(inicio);
		return nodoActual;
	}
	else{
		NodoInt *anterior = inicio;
		int i = 0;
		while(i<indice && nodoActual->sig != NULL){
			anterior = nodoActual;
			nodoActual = nodoActual->sig;
			i++;
		}
		anterior->sig = nodoActual->sig;
		free(nodoActual);
		if(i==0){
			return NULL;
		}
	}
	return inicio;
}

/*Funci�n listaInt_borrar
	Libera la memoria de toda la lista
*/
NodoInt* listaInt_borrar(NodoInt *inicio){
	if(inicio==NULL){
		return NULL;
	}
	NodoInt *nodoActual = inicio;
	NodoInt *nodoSig = inicio->sig;
	while(nodoSig != NULL){
		free(nodoActual);
		nodoActual = nodoSig;
		nodoSig = nodoActual->sig;
	}
	free(nodoActual);
	return NULL;
}

