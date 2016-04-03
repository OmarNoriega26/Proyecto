
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
   char produ[15];
   struct nodoInt *sig;
} NodoInt;

/*Función listaInt_ingresar
	Agrega un valor al final de la lista.
*/
NodoInt* listaInt_ingresar(NodoInt *inicio, int c, int v,char p[15]);

/*Función listaInt_ingresarEn
	Agrega un valor en una posición en especifico de la lista.
*/
NodoInt* listaInt_ingresarEn(NodoInt *inicio, int c, int v,char p[15], unsigned int indice);

/*Función listaInt_obtener
	Obtiene un valor en una posición en especifico de la lista.
*/
int listaInt_obtenerV(NodoInt *inicio, unsigned int indice);
int listaInt_obtenerC(NodoInt *inicio, unsigned int indice);
char* listaInt_obtenerp(NodoInt *inicio, unsigned int indice);

/*Función listaInt_imprimir
	Imprime en pantalla todos los datos de la lista
*/
void listaInt_imprimir(NodoInt *inicio);

/*Función listaInt_remover
	Remueve un valor en una posición en especifico de la lista.
*/
NodoInt* listaInt_remover(NodoInt *inicio, unsigned int indice);

/*Función listaInt_borrar
	Libera la memoria de toda la lista
*/
NodoInt* listaInt_borrar(NodoInt *inicio);

/*Funcion imprime_productos
	imprime el listado de productos de un departamento
*/
void imprime_productos(NodoInt *inicio);

void imprime_productos_precio(NodoInt *inicio);

#endif // LISTALIGINT_H_