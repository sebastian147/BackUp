#include <stdio.h>
#include <stdlib.h>
#include "listafunc.h"
#include <string.h>
void ordenamiento (lista **enemigo)
{
	lista *final=NULL,*aux,*pos=NULL;
	char nombre[20];
	int i=1;
	aux=*enemigo;
	if (aux==NULL)
	{
		printf("No hay elementos que ordenar\n");
		exit;
	}
	while(i)
	{
		strcpy(nombre,aux->nombre);
		pos=aux;
		for(;aux!=NULL;aux=aux->siguiente)
		{
				printf("%s\n\n%s\n\n",aux->nombre,aux->siguiente->nombre);
			if(aux->siguiente !=NULL && strcmp(aux->nombre,aux->siguiente->nombre)>0 &&strcmp(aux->nombre,nombre)>0)
			{
				strcpy(nombre,aux->nombre);
				pos=aux;
				printf("\n wachin %s\n",nombre);
			}
			else if(strcmp(aux->nombre,nombre)>0)
			{
				strcpy(nombre,aux->nombre);
				pos=aux;
				printf("\nzzzzzzzzzz\n%s\n",nombre);
			}
			else if(aux->siguiente==NULL&& aux->anterior==NULL && strcmp(aux->nombre,nombre)==0)
			{
				strcpy(nombre,aux->nombre);
				pos=aux;
				printf("\naaaaaaaaaaaaaaa\n%s\n",nombre);
			}

		}
		aux=pos;
		printf("\n\n\n\nnombre %s\n\n\n%s\n\n\n",aux->nombre,nombre);
		if (aux->anterior==NULL && aux->siguiente!=NULL)
		{
			printf("error");
			aux=aux->siguiente;
			aux->anterior=NULL;
			*enemigo=aux;
		}
		else if(aux->anterior != NULL && aux->siguiente == NULL)
		{
			printf("error2");
			aux->anterior->siguiente=NULL;
		}
		else if(aux->anterior == NULL && aux->siguiente == NULL)
		{
			i=0;
		}
		else if(aux->anterior!=NULL && aux->siguiente!=NULL)
		{
			printf("error1");
			aux->anterior->siguiente=aux->siguiente;
			aux->siguiente->anterior=aux->anterior;
		}
			printf("hola");

		if(final==NULL)
		{
			final=pos;
			final->siguiente=NULL;
			final->anterior=NULL;
			printf("nada %s\n",final->nombre);

		}
		else
		{
			pos->siguiente=final;
			pos->anterior=NULL;
			final->anterior=pos;
			final=pos;
			printf("%s\n",final->nombre);
		}
		for(pos=final;pos!=NULL;pos=pos->siguiente)
		{
			printf("%s\n",pos->nombre);
		}
		aux=*enemigo;
	}
	*enemigo=final;
/*	int i;
	lista *aux1,*aux2,*aux3,*aux4,*final;
	for(aux1=enemigo;aux1->siguiente!=NULL;aux1=aux1->siguiente)
	{
		for(aux2=enemigo;aux2->siguiente!=NULL;aux2=aux2->siguiente)
		{
			aux4=aux2->anterior;
			if(strcmp(aux2->nombre,aux2->siguiente->nombre)>0)
			{
				//printf(" %s  hola\n",aux2->nombre);
				if(aux2->anterior != NULL)
				{
					aux3=aux2;
				//	printf("%s es  por",aux2->anterior->siguiente->nombre);
					aux2->anterior->siguiente=aux2->siguiente;

				//	printf("%s \n",aux2->anterior->siguiente->nombre);
				//	printf("%s es  por",aux2->siguiente->nombre);
					aux2->siguiente=aux2->siguiente->siguiente;
				//	printf("%s \n",aux2->siguiente->nombre);
				//	printf("%s es por ",aux2->anterior->siguiente->siguiente->nombre);
					aux2->anterior->siguiente->siguiente=aux3;
				//	printf("%s \n",aux2->anterior->siguiente->siguiente->nombre);
				}
				else if(aux2->anterior==NULL)
				{
					aux3=aux2->siguiente;
					aux2->siguiente=aux2->siguiente->siguiente;
					aux3->siguiente=aux2;
					aux2->anterior=NULL;
				}*/
		/*		else if(aux2->anterior!=NULL&&aux2->siguiente->siguiente==NULL)
				{
					printf("hola1\n");
					aux3=aux2;
					aux2->anterior=aux3->siguiente;
					aux3->siguiente->siguiente=aux3;
					aux3->siguiente=NULL;

				}*/
				/*else if(aux2->anterior==NULL&&aux2->siguiente->siguiente==NULL)
				{
					printf("hola1\n");
					aux3=aux2->siguiente;
					aux2->siguiente=NULL;
					aux3->siguiente=aux2;
					aux2->anterior=NULL;
					*enemigo=aux2;

				}*/
		/*		else if(aux2->anterior==NULL&&aux2->siguiente==NULL)
				{
					printf("Hay un solo elemento en la lista\n");
					exit;
				}
				else if(enemigo==NULL)
				{
					printf("no hay elmentos en la lista");
					exit;
				}*/
/*			}
			for(i=4;i;i--)
			{
				aux4->siguiente->anterior=aux4;
				aux4=aux4->siguiente;
			}
		}
	}*/
}
/*void cambio()
{
	int a;

}*/
void instrucciones(void)
{
	printf("Elija una de las siguientes opciones:\n1- Agregar nodo \n2- Eliminar nodo \n3- Listar nodos\n4- Usted saldra del programa\n5- Ordenar\n");
}
void ingresar_datos(lista *nuevo)
{
	printf("Ingrese el nombre\n");
	scanf("%s",nuevo->nombre);
	printf("Ingresar el dni\n");
	scanf("%d",&(nuevo->dni));
}
lista * crear_puntero(lista *enemigo)
{
	lista *aux=NULL,*nuevoEnemigo=NULL;//Declaro variables
	nuevoEnemigo=(lista *)malloc(sizeof(lista));//pido memoria
	if(nuevoEnemigo==NULL)//pregunto si sale error
	{
		printf("Error al crear enemigo");
		//return -1;
	}
	aux=enemigo;//hago la variable auxiliar igual al enemigo
	if(aux==NULL)//si auxiliar no existe creo la lista
	{
		nuevoEnemigo->siguiente=NULL;
		nuevoEnemigo->anterior=NULL;
	}
	else//agrego el nuevo nodo de la lista al principio|
	{
		nuevoEnemigo->siguiente=aux;
		aux->anterior=nuevoEnemigo;
		nuevoEnemigo->anterior=NULL;
	}
	ingresar_datos(nuevoEnemigo);
	return nuevoEnemigo;
/*
	lista *nuevo;
	nuevo=(lista *) malloc(sizeof(lista));
	if (viejo)
	{
		nuevo->sig=viejo;
	}
	else
	{
		nuevo->sig=NULL;
	}
	ingresar_datos(nuevo);
	return nuevo;*/
}

void listar(lista *primero)
{
	lista *aux;
	for(aux = primero; aux != NULL; aux = aux->siguiente)
	{
		printf("El nombre es: %s\nEl dni es:%d\n", aux->nombre,aux->dni);

		printf("El nombre DEL ANTERIOR es: %s\nEl dni es:%d\n", aux->anterior->nombre,aux->dni);
	}
}
int comparar(char *letra, char *nombre)
{
	int i=0,j=0;
	for(;(letra[i]==nombre[j])&&(i<=20);i++,j++)
	{
		
	}
	if((nombre[j] ==letra[i]) )
		return 0;
	else 
		return 1;

}
void eliminar(lista *ini,char *letra)
{
	lista *aux,*p;
	aux=ini;
/*	if(strcmp(aux->nombre,letra))
	{
		p=aux;
		aux=aux->sig;
		free(p);
		return aux;
	}	
*///	printf("\n\n %d\n\n",strcmp(aux->nombre,letra));
	while((strcmp(aux->siguiente->nombre,letra)!=0)&&(aux->siguiente->siguiente!=NULL)&&(aux->siguiente!=NULL))
	{
		aux=aux->siguiente;
		printf ("\n\n%d\n\n",strcmp(aux->siguiente->nombre,letra));
	}
	

	if(strcmp(aux->siguiente->nombre,letra)==0)
	{
		if((aux->siguiente->siguiente)==NULL)
		{
			p=aux->siguiente;
			aux->siguiente=NULL;
			free (p);
		}
		else
		{
			p=aux->siguiente;
			aux->siguiente=aux->siguiente->siguiente;
			free(p);
		}
		printf("Se elimino exitosamente\n");	
	}
	else
	{
		printf("No existe el nombre\n");
	}
}

