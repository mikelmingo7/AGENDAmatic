#include <stdio.h>
#include <ctype.h>
#include "main.h"
#include "Tarea.h"
#include <stdlib.h>
#include <string.h>
#include<windows.h>


void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
void echo(void)
{
	char opcion;
	Tarea tarea;
	char *titulo = (char *)malloc(100);
	char *descripcion = (char *)malloc(200);
	char *fecha = (char *)malloc(11);
	int *minutos = (int *)malloc(6);
	int *importancia = (int *)malloc(2);

	do
    {
		printf("  1.Ver tareas \n");
		printf("  2.Anadir una tarea \n");
		printf("  3.Editar una tarea \n");
		printf("  4.Borrar una tarea \n");
		printf("  5.Salir \n");
		printf("\n");

		do
		{
			printf( "  Introduce una opcion: \n");
			fflush( stdin );
			scanf( "%c", &opcion );

		} while ( opcion < '1' || opcion > '5' );

		switch ( opcion )
		{
			case '1':
				limpiar_pantalla();
				printf("\n");
				printf("Has elegido la opcion: 1 (Ver lista de Tareas)\n");
				printf("\n");
				printf("----------------------------\n");
				printf("Lista de Tareas: \n");
				leerTareas();
				printf("----------------------------\n");
				printf("\n");
				break;

			case '2':
				limpiar_pantalla();
				printf("\n");
				printf("Has elegido la opcion: 2 (Anadir tarea)\n");
				printf("\n");

				//char *titulo = (char *)malloc(100);
				printf("Introduce un titulo: ");
				fflush( stdin );
				fgets(titulo, 100, stdin);
				//scanf("%s", titulo);
				//tarea.tit= titulo;
				//Para borrar el salto de linea
				titulo[strcspn(titulo, "\n")] = 0;
				strcpy(tarea.tit,titulo);

				//char *descripcion = (char *)malloc(200);
				printf("Introduce una descripcion: ");
				fflush( stdin );
				//scanf("%s", descripcion);
				//tarea.desc= *descripcion;
				fgets(descripcion, 200, stdin);
				descripcion[strcspn(descripcion, "\n")] = 0;
				strcpy(tarea.desc,descripcion);

				//char *fecha = (char *)malloc(11);
				printf("Introduce una fecha: ");
				fflush( stdin );
				scanf("%s", fecha);
				//tarea.fech= *fecha;
				strcpy(tarea.fech,fecha);

				//int *minutos = (int *)malloc(6);
				printf("Introduce una duracion en minutos: ");
				fflush( stdin );
				scanf("%i", minutos);
				tarea.min= *minutos;
				//strcpy(tarea.min,minutos);

				//int *importancia = (int *)malloc(2);
				printf("Introduce la importancia del  1 al 10: ");
				fflush( stdin );
				scanf("%i", importancia);
				tarea.imp= *importancia;
				//strcpy(tarea.imp,importancia);

				printf("\n");
				limpiar_pantalla();
				guardar(tarea);
				printf("\n");
				printf("\n");
				break;
			case '4':
				limpiar_pantalla();
				printf("  \n");
				printf("Has elegido la opcion: 4 (Borrar tarea)\n");
				leerTareas();
				printf("Introduce el numero de tarea que quieres borrar: \n");
				int numero;
				scanf( "%i", &numero );
				limpiar_pantalla();
				borrarTareas(numero);
				break;
			case '3':
				limpiar_pantalla();
				printf("  \n");
				printf("Has elegido la opcion: 3 (editar tarea) \n");
				printf("  \n");
				leerTareas();
				printf("Introduce el numero de tarea que quieres editar: \n");
				int numeroEditar;
				scanf( "%i", &numeroEditar );

				/////////
				printf("Introduce un titulo: ");
				fflush( stdin );
				fgets(titulo, 100, stdin);
				titulo[strcspn(titulo, "\n")] = 0;
				strcpy(tarea.tit,titulo);

				printf("Introduce una descripcion: ");
				fflush( stdin );
				fgets(descripcion, 200, stdin);
				descripcion[strcspn(descripcion, "\n")] = 0;
				strcpy(tarea.desc,descripcion);


				printf("Introduce una fecha: ");
				fflush( stdin );
				scanf("%s", fecha);
				strcpy(tarea.fech,fecha);


				printf("Introduce una duracion en minutos: ");
				fflush( stdin );
				scanf("%i", minutos);
				tarea.min= *minutos;

				printf("Introduce la importancia del  1 al 10: ");
				fflush( stdin );
				scanf("%i", importancia);
				tarea.imp= *importancia;
				/////////
				limpiar_pantalla();
				editarTarea(numeroEditar, tarea);
				break;

		}

    } while ( opcion != '5' );

	limpiar_pantalla();
	free(titulo);
	titulo=NULL;
	free(descripcion);
	descripcion=NULL;
	free(fecha);
	fecha=NULL;
	free(minutos);
	minutos=NULL;
	free(importancia);
	importancia=NULL;

}

int main(void)
{
	printf("----------------------------\n");
	printf("¡Bienvenido a AgendaMatic! \n");
	printf("----------------------------\n");
	echo();

	return 0;
}

