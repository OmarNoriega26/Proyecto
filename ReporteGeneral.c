#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

int main(void)
{
	FILE *reporteventas;
	FILE *reportegeneral;
	char g='\0';
	reporteventas=fopen("PRUEBA.txt","r");//AQUI VA EN VEZ DE PRUEBA.txt EL dep DEL NOMBRE DEL DEPARTAMENTO
	reportegeneral=fopen("General.txt","a");
	if(reporteventas==0||reportegeneral==0)
	{
		printf("Error");
	}
	else
	{
		rewind(reporteventas);
		g=fgetc(reporteventas);
		while(feof(reporteventas)==0)
		{
			fputc(g,reportegeneral);
			printf("\t\t\t");
			printf("%c",g);
			g=fgetc(reporteventas);
		}
		fclose(reporteventas);
		fclose(reportegeneral);
	}	
}