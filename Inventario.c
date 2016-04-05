#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "lista.c"

void imprimereporte(char reporte[15])
{
	FILE *f;
	f=fopen(reporte,"r");
	if (f==0)
		printf("Error, el archiv no existe");
	else
	{
		char c;
		rewind(f);
		c=fgetc(f);
		while(feof(f)==0)
		{
			printf("%c",c);
			c=fgetc(f);
		}
		fclose(f);
	}
}

NodoInt* leerArchivo(char dep[15],NodoInt *lista ){
	FILE *f;
	f=fopen(dep,"rt");
	if (f==0){
		printf("Error\n");
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

void reporteVentas(char dep[15],char nom[15], int tmp, int total)
{
	//int tmp=100;//ESTA VARIABLE TIENE QUE SER LA QUE GUARDA LA CANTIDAD
	//int total=500;//ESTA VARIABLE TIENE QUE SER LA QUE GUARDA EL TOTAL
	//char nom[15];//ESTA VARIABLE ES PARA EL NOMBRE DEL PRODUCTO
	FILE *reporteventas;
	reporteventas=fopen(dep,"a");//AQUI VA EN VEZ DE PRUEBA.txt EL dep DEL NOMBRE DEL DEPARTAMENTO
	if(reporteventas==0)
	{
		printf("Error no fue posible abrir el archvio");
	}
	else
	{
		time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
        fprintf(reporteventas,"%s\t",output);
        fprintf(reporteventas,"%s\t\t\t%d\t\t\t%d\n",nom,tmp,total);
        fclose(reporteventas);
	}
}


void guardarArchivo(char dep[15],int cantidad,int costo,char nuevoP[15]){
	FILE *f;
	f=fopen(dep,"at");
	if (f==0){
		printf("Error\n");
	}
	fprintf( f, "\n%s\t%d\t%d",nuevoP,costo,cantidad);
	fclose(f);
}

void reescribeArchivo(char dep[15],NodoInt *inicio)
{
	NodoInt *nodoActual = inicio;
 	FILE *f;
 	f = fopen ( dep, "w" );
	while(nodoActual != NULL){
		fprintf(f,"\n%s\t%d\t%d",nodoActual->produ,nodoActual->canti,nodoActual->valor);
		nodoActual = nodoActual->sig;
	}
	fclose ( f );	
}




NodoInt* agregar(char dep[15],NodoInt *lista)
{
	
	lista=leerArchivo(dep,lista );
	char nuevoP[15];
	int costo,cantidad;
	printf("\nEscriba el nuevo nombre del producto:	");
	getchar();
	scanf("%s",&nuevoP);
	printf("\nEscriba el costo del producto: ");
	scanf("%d",&costo);
	printf("\nEscriba la cantidad inicial del producto: ");
	scanf("%d",&cantidad);
	lista = listaInt_ingresar(lista,cantidad,costo,nuevoP);
	guardarArchivo(dep,cantidad,costo,nuevoP);
	return lista;
}

NodoInt* eliminar(char dep[15], NodoInt *lista)
{
	int eliminado;
	lista=leerArchivo(dep,lista);
	printf("Selecciona el producto que deseas eliminar \n");
	imprime_productos(lista);
	scanf("%d",&eliminado);
	eliminado--;
	lista=listaInt_remover(lista,eliminado);
	reescribeArchivo(dep,lista);
	return lista;
}

NodoInt* vender(char dep[15], NodoInt *lista, char repo[15])
{
	lista=leerArchivo(dep,lista);
	int v,c;	//v= valor c=cantidad
	int venta,cuantos,tmp,total;
	char nom[15]; //guardara el nombre del producto
	printf("Selecciona el producto que deseas vender\n");
	imprime_productos_precio(lista);
	scanf("%d",&venta);
	if (venta<1)
	{
		printf("Error\n");
	}
	else
	{
	venta = venta-1;
	v=listaInt_obtenerV(lista,venta);
	c=listaInt_obtenerC(lista,venta);
	strcpy(nom,(listaInt_obtenerP(lista,venta,nom)));
	printf("¿Cuantos productos deseas vender?\n");
	scanf("%d",&cuantos);
	if(c<cuantos)
	{
		printf("Lo sentimos no contamos con esa cantidad de productos\n  Contamos con : %d\n",c);
	}
	else
	{


	tmp=c-cuantos;
	total=v*cuantos;
	printf("\n\nSu venta total es de %d pesos\n",total);
	printf("quedaran disponibles  %d productos\n",tmp);
	reporteVentas("Ventas.txt",nom,cuantos,total);
	reporteVentas(repo,nom,cuantos,total);

	if (tmp == 0)
	{
		lista=listaInt_remover(lista,venta);
		reescribeArchivo(dep,lista);
	}
	else
	{
		lista=listaInt_remover(lista,venta);
		lista = listaInt_ingresar(lista,tmp,v,nom);
		reescribeArchivo(dep,lista);
	}
	listaInt_borrar(lista);
	}
	
	return lista;
	}
}

NodoInt* comprar(char dep[15], NodoInt *lista,char repo[15])
{
	lista=leerArchivo(dep,lista);
	int v,c;	//v= valor c=cantidad
	int venta,cuantos,tmp,total;
	char nom[15]; //guardara el nombre del producto
	printf("Selecciona el producto que deseas comprar\n");
	imprime_productos_precio(lista);
	scanf("%d",&venta);
	if (venta<1)
	{
		printf("Error\n");
	}
	else
	{
	venta = venta-1;
	v=listaInt_obtenerV(lista,venta);
	c=listaInt_obtenerC(lista,venta);
	strcpy(nom,(listaInt_obtenerP(lista,venta,nom)));
	printf("¿Cuantos productos deseas comprar?\n");
	scanf("%d",&cuantos);

	tmp=c+cuantos;
	total=v*cuantos;

	printf("Su compra total es de %d pesos\n",total);
	printf("quedaran disponibles  %d productos\n",tmp);
	reporteVentas("Compras.txt",nom,cuantos,total);
	reporteVentas(repo,nom,cuantos,total);

	if (tmp == 0)
	{
		lista=listaInt_remover(lista,venta);
		reescribeArchivo(dep,lista);
	}
	else
	{
		lista=listaInt_remover(lista,venta);
		lista = listaInt_ingresar(lista,tmp,v,nom);
		reescribeArchivo(dep,lista);
	}
	listaInt_borrar(lista);
	return lista;
	}
}

int main(){
	int opcion,depto;
	do{
		NodoInt *lista = NULL;
		printf("\n\n\t Bienvenido a nuestro inventario \n\n\t Seleccione una de nuestras opciones:   ");
		printf("\n\t1.- Ingresar un nuevo producto");
		printf("\n\t2.- Eliminar un producto");
		printf("\n\t3.- Venta de un producto");
		printf("\n\t4.- Compra de un producto");
		printf("\n\t5.- Imprimir reporte de ventas");
		printf("\n\t6.- Imprimir reporte de compras");
		printf("\n\t7.- Imprimir reporte de ventas por departamento");
		printf("\n\t8.- Imprimir reporte de compras por departamento");
		printf("\n\t9.- Salir\n\t");
		scanf("%d",&opcion);
		system("clear");
		switch (opcion)
		{
		case 1:
		{
			do{
				NodoInt *lista = NULL;
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
						listaInt_borrar(lista);
						break;
							}
					case 2:{
						char archivo[]="juguetes.txt";
						lista=agregar(archivo,lista);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 3:{
						char archivo[]="vestimenta.txt";
						lista=agregar(archivo,lista);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 4:{
						char archivo[]="magia.txt";
						lista=agregar(archivo,lista);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 5:{
						char archivo[]="electronica.txt";
						lista=agregar(archivo,lista);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					default:
						break;
				}
			}while(depto!=6);

		break;
		}

		case 2:
		{
			do{
				NodoInt *lista = NULL;
				printf("\n\n\t Seleccione en que departamento se encuentra el producto \n que desea eliminar:");
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
						lista=eliminar(archivo,lista);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 2:{
						char archivo[]="juguetes.txt";
						lista=eliminar(archivo,lista);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 3:{
						char archivo[]="vestimenta.txt";
						lista=eliminar(archivo,lista);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 4:{
						char archivo[]="magia.txt";
						lista=eliminar(archivo,lista);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 5:{
						char archivo[]="electronica.txt";
						lista=eliminar(archivo,lista);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					default:
						break;
				}
			}while(depto!=6);
		break;
		}
		case 3:
		{
			do{
				NodoInt *lista = NULL;
				printf("\n\n\t Seleccione en que departamento se encuentra el producto \n  que desea vender:");
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
						char reporte[]="RComida.txt";
						vender(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 2:{
						char archivo[]="juguetes.txt";
						char reporte[]="RJuguetes.txt";
						vender(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 3:{
						char archivo[]="vestimenta.txt";
						char reporte[]="RVestimenta.txt";
						vender(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 4:{
						char archivo[]="magia.txt";
						char reporte[]="RMagia.txt";
						vender(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 5:{
						char archivo[]="electronica.txt";
						char reporte[]="RElecronica.txt";
						vender(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					default:
						break;
				}

			}while(depto!=6);
		break;
		}
		case 4:
		{
			do{
				NodoInt *lista = NULL;
				printf("\n\n\t Seleccione en que departamento se encuentra el producto que\n  desea Comprar:");
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
						char reporte[]="CComida.txt";
						comprar(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 2:{
						char archivo[]="juguetes.txt";
						char reporte[]="CJuguetes.txt";
						comprar(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 3:{
						char archivo[]="vestimenta.txt";
						char reporte[]="CVestimenta.txt";
						comprar(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 4:{
						char archivo[]="magia.txt";
						char reporte[]="CMagia.txt";
						comprar(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					case 5:{
						char archivo[]="electronica.txt";
						char reporte[]="CElectronica.txt";
						comprar(archivo,lista,reporte);
						listaInt_imprimir(lista);
						listaInt_borrar(lista);
						break;
							}
					default:
						break;
				}

			}while(depto!=6);
		}
		break;
		case 5:
		{
			char repo[]="Ventas.txt";
			imprimereporte(repo);

		}
		break;
		case 6:
		{
			char repo[]="Compras.txt";
			imprimereporte(repo);
		}
		break;
		case 7:
		{
			do{
				NodoInt *lista = NULL;
				printf("\n\n\t Seleccione el departamento \n");
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
						imprimereporte("RComida.txt");
						break;
							}
					case 2:{
						imprimereporte("RJuguetes.txt");
						break;
							}
					case 3:{
						imprimereporte("RVestimenta.txt");
						break;
							}
					case 4:{
						imprimereporte("RMagia.txt");
						break;
							}
					case 5:{
						imprimereporte("RElectronica.txt");
						break;
							}
					default:
						break;
				}

			}while(depto!=6);
		}

		case 8:
		{
			do{
				NodoInt *lista = NULL;
				printf("\n\n\t Seleccione el departamento \n");
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
						imprimereporte("CComida.txt");
						break;
							}
					case 2:{
						imprimereporte("CJuguetes.txt");
						break;
							}
					case 3:{
						imprimereporte("CVestimenta.txt");
						break;
							}
					case 4:{
						imprimereporte("CMagia.txt");
						break;
							}
					case 5:{
						imprimereporte("CElectronica.txt");
						break;
							}
					default:
						break;
				}

			}while(depto!=6);
		}

		default:
		break;
		}
	}while(opcion !=9);
	return 0;
}