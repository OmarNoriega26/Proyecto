#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 	FILE *archivo;
 	
 	char caracteres[100];
 	char dpt[30];
 	int i=0;
 	
 	archivo = fopen("deptos.txt","r");
 	
 	if (archivo == NULL)
 		exit(1);
 	while (feof(archivo) == 0)
 	{
 		fgets(caracteres,100,archivo);
 		dpy[i]=caracteres;
 		i++;
 	}
 	i=0;
        system("PAUSE");

        fclose(archivo);
	return 0;
}