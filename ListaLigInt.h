#ifndef LISTALIGINT_H_
#define LISTALIGINT_H_

#include <stdio.h>
#include <stdlib.h>

/*Estructura nodoInt
	Guarda un nodo para una lista ligada de enteros.
		valor - Valor almacenado
		sig   - Apuntador al siguiente nodo de la lista
*/
typedef struct nodoInt {
   int valor;
   int canti;
   struct nodoInt *sig;
} NodoInt;


/*Funci�n listaInt_ingresar
	Agrega un valor al final de la lista.
*/
NodoInt* listaInt_ingresar(NodoInt *inicio, int c, int v);


/*Funci�n listaInt_ingresarEn
	Agrega un valor en una posici�n en especifico de la lista.
*/
NodoInt* listaInt_ingresarEn(NodoInt *inicio, int c, int v, unsigned int indice);

/*Funci�n listaInt_obtener
	Obtiene un valor en una posici�n en especifico de la lista.
*/
int listaInt_obtener(NodoInt *inicio, unsigned int indice);

/*Funci�n listaInt_imprimir
	Imprime en pantalla todos los datos de la lista
*/
void listaInt_imprimir(NodoInt *inicio);

/*Funci�n listaInt_remover
	Remueve un valor en una posici�n en especifico de la lista.
*/
NodoInt* listaInt_remover(NodoInt *inicio, unsigned int indice);

/*Funci�n listaInt_borrar
	Libera la memoria de toda la lista
*/
NodoInt* listaInt_borrar(NodoInt *inicio);


#endif // LISTALIGINT_H_
