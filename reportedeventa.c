#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

//void reporteVentas(char dep[15],char nom, int tmp, int total)
int main()
{
	int tmp=100;//ESTA VARIABLE TIENE QUE SER LA QUE GUARDA LA CANTIDAD
	int total=500;//ESTA VARIABLE TIENE QUE SER LA QUE GUARDA EL TOTAL
	//char nom[15];//ESTA VARIABLE ES PARA EL NOMBRE DEL PRODUCTO
	int nom;
	FILE *reporteventas;
	reporteventas=fopen("PRUEBA.txt","a");//AQUI VA EN VEZ DE PRUEBA.txt EL dep DEL NOMBRE DEL DEPARTAMENTO
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
        fprintf(reporteventas,"Omar\t\t\t%d\t\t\t%d\n",tmp,total);
        fclose(reporteventas);

	}
}