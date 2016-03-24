#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "lista.c"

NodoInt* leerArchivo(char dep[15],NodoInt *lista ){
	FILE *f;
	f=fopen(dep,"rt");
	if (f==0){
		printf("Error\n");
		system("pause");
	}
	int i,j,n=0;
	char a[15],c;
	do{
      c = fgetc (f);
     if (c == '\n'){
		fscanf(f,"%s\t%d\t%d",&a,&i,&j);
		lista = listaInt_ingresar(lista,i,j,a);
		n++;
		}
	} while (c != EOF);
	fclose(f);
	return lista;
}
void guardarArchivo(char dep[15],int cantidad,int costo,char nuevoP[15]){
	FILE *f;
	f=fopen(dep,"at");
	if (f==0){
		printf("Error\n");
		system("pause");
	}
	fprintf( f, "\n%s\t%d\t%d",nuevoP,costo,cantidad);
	fclose(f);
}
NodoInt* agregar(char dep[15],NodoInt *lista)
{
	
	lista=leerArchivo(dep,lista );
	char nuevoP[15];
	int costo,cantidad;
	printf("\nEscriba el nuevo nombre del producto:	");
	scanf("%s",&nuevoP);
	printf("\nEscriba el costo del producto: ");
	scanf("%d",&costo);
	printf("\nEscriba la cantidad inicial del producto: ");
	scanf("%d",&cantidad);
	lista = listaInt_ingresar(lista,cantidad,costo,nuevoP);
	guardarArchivo(dep,cantidad,costo,nuevoP);//Aqui se colocaria una funcion que guarde el contenido de la lista en un archivo y posteriormente borre la lista.
	return lista;
}


int main(){
	NodoInt *lista = NULL;
	int opcion,depto;
	do{
		printf("\n\n\t Bienvenido a nuestro inventario \n\n\t Seleccione una de nuestras opciones:   ");
		printf("\n\t1.- Ingresar un nuevo producto");
		printf("\n\t2.- Eliminar un producto");
		printf("\n\t3.- Venta de un producto");
		printf("\n\t4.- Compra de un producto");
		printf("\n\t5.- Imprimir reporte de ventas");
		printf("\n\t6.- Imprimir reporte de compras");
		printf("\n\t7.- Imprimir reporte por departamento");
		printf("\n\t8.- Salir\n\t");
		scanf("%d",&opcion);
		system("clear");
		switch (opcion)
		{
		case 1:
			do{
				printf("\n\n\t Seleccione a que departamento ingresara el nuevo producto:");
				printf("\n\t1.- Comida");
				printf("\n\t2.- Juguetes");
				printf("\n\t3.- Vestimenta");
				printf("\n\t4.- Magia");
				printf("\n\t5.- Electronica");
				printf("\n\t6.- Regresar al menu principal\n\t");
				scanf("%d",&depto);
				system("clear");
				switch (depto)
				{
					case 1:{
						char archivo[]="comida.txt";
						lista=agregar(archivo,lista);
						listaInt_imprimir(lista);
						break;
							}
					case 2:{
						char archivo[]="juguetes.txt";
						lista=agregar(archivo,lista);
						break;
							}
					case 3:{
						char archivo[]="vestimenta.txt";
						agregar(archivo,lista);
						break;
							}
					case 4:{
						char archivo[]="magia.txt";
						agregar(archivo,lista);
						break;
							}
					case 5:{
						char archivo[]="electronica.txt";
						agregar(archivo,lista);
						break;
							}
					default:
						break;
				}
			}while(depto!=6);		
		default:
		break;
		}
	}while(opcion !=8);
	return 0;
}