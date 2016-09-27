struct lista
{
	char nombre[20];
	int dni;
	struct lista *siguiente;
	struct lista *anterior;
};
typedef struct lista lista;

void instrucciones(void);
lista *crear_puntero(lista *viejo);
void ingresar_datos(lista *nueva);
void listar(lista *primero);
void eliminar(lista *ini,char *letra);
int comparar(char *letra,char *nombre);
void ordenamiento(lista **ini);
