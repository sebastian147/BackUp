#include <stdio.h>
#include <stdlib.h>
#include "listafunc.h"
int main(int argc, char **argv)
{
	int c;
	char *dato;
	lista *ini;
	ini = NULL;
	while ((c)!=5)
	{
		printf("Decida que quiere hacer:\n1-Ingresar un dato\n2-Verificar si esta vacia\n3-Eliminar una dato\n4-Listar los datos\n5-Salir del programa\n");
		scanf("%d", &c);
		switch(c)
		{
			case 1:
				printf("Ingrese el valor\n");
				//scanf("%s", dato);
				ini=crear_puntero(ini);
				break;
			case 2:
				/*if(ls_vacia)
					printf("La lista esta vacia\n");
				else
					printf("La lista tiene datos\n");

				break;*/
			case 3:
				printf("Escriba el valor que desea eliminar\n");
				scanf("%s", dato);
				eliminar(ini, dato);
				break;

			case 4:
				listar(ini);
			case 5:
				printf("Va a salir del programa\n");
				break;
			case 6:
				ordenamiento(&ini);
			default:
				printf("No ingreso ninguna opcion\n");
				break;
		}

	}
	return 0;
}
