#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"
#include "Tarea.h"
#include "Menu.h"

void echo(void)
{
	//Variables
	char opcion;
	Tarea tarea;
	char *titulo = (char *)malloc(100);
	char *descripcion = (char *)malloc(200);
	char *fecha = (char *)malloc(11);
	int *minutos = (int *)malloc(6);
	int *importancia = (int *)malloc(2);

	//Variables fecha
	time_t t = time(NULL);
	struct tm tiempoLocal = *localtime(&t);
	char fechaActual[11];
	char *formato = "%d/%m/%Y";

	do
    {
		mostrarMenu();

		do
		{
			opcion = menuOpcion();

		} while ( opcion < '1' || opcion > '8' );

		switch ( opcion )
		{
			case '1': // Ver lista de tareas

				printf("----------------------------\n");
				printf("Lista de Tareas: \n");
				leerTareas();
				printf("----------------------------\n");
				printf("\n");
				break;

			case '2': // Añadir tarea

				//Titulo
				printf("Introduce un titulo: ");
				fflush( stdin );
				fgets(titulo, 100, stdin);
				titulo[strcspn(titulo, "\n")] = 0;
				strcpy(tarea.tit,titulo);

				//Descripcion
				printf("Introduce una descripcion: ");
				fflush( stdin );
				fgets(descripcion, 200, stdin);
				descripcion[strcspn(descripcion, "\n")] = 0;
				strcpy(tarea.desc,descripcion);

				//Fecha
				printf("Introduce una fecha con el formato (00/00/0000) : ");
				fflush( stdin );
				scanf("%s", fecha);
				strcpy(tarea.fech,fecha);

				//Minutos
				printf("Introduce una duracion en minutos: ");
				fflush( stdin );
				scanf("%i", minutos);
				tarea.min= *minutos;

				//Importancia
				printf("Introduce la importancia del  1 al 10: ");
				fflush( stdin );
				scanf("%i", importancia);
				tarea.imp= *importancia;

				printf("\n");
				limpiar_pantalla();
				guardar(tarea);
				printf("\n");
				printf("\n");
				break;

			case '3': // Editar tarea
				leerTareas();
				printf("Introduce el numero de tarea que quieres editar: \n");
				int numeroEditar;
				scanf( "%i", &numeroEditar );

				//Titulo
				printf("Introduce un titulo: ");
				fflush( stdin );
				fgets(titulo, 100, stdin);
				titulo[strcspn(titulo, "\n")] = 0;
				strcpy(tarea.tit,titulo);

				//Descripcion
				printf("Introduce una descripcion: ");
				fflush( stdin );
				fgets(descripcion, 200, stdin);
				descripcion[strcspn(descripcion, "\n")] = 0;
				strcpy(tarea.desc,descripcion);

				//Fecha
				printf("Introduce una fecha con el formato (00/00/0000) : ");
				fflush( stdin );
				scanf("%s", fecha);
				strcpy(tarea.fech,fecha);

				//Minutos
				printf("Introduce una duracion en minutos: ");
				fflush( stdin );
				scanf("%i", minutos);
				tarea.min= *minutos;

				//Importancia
				printf("Introduce la importancia del  1 al 10: ");
				fflush( stdin );
				scanf("%i", importancia);
				tarea.imp= *importancia;

				limpiar_pantalla();
				editarTarea(numeroEditar, tarea);
				break;

			case '4': // Borrar tarea
				leerTareas();
				printf("Introduce el numero de tarea que quieres borrar: \n");
				fflush( stdin );
				int numero;
				scanf( "%i", &numero );
				limpiar_pantalla();
				borrarTareas(numero);
				break;

			case '5': // Ver tareas de hoy
				strftime(fechaActual, sizeof fechaActual, formato, &tiempoLocal);
				printf("Fecha y hora: %s \n", fechaActual);
				printf("  \n");
				leerTareasFecha(fechaActual);
				break;

			case '6': // Ver tareas de una fecha determinada
				printf("Introduce una fecha con el formato (00/00/0000) : ");
				fflush( stdin );
				scanf("%s", fechaActual);
				leerTareasFecha(fechaActual);
				break;

			case '7': // Marcar una tarea como completada
				leerTareas();
				printf("Introduce el numero de tarea que quieres marcar como completada: \n");
				fflush( stdin );
				int numeroTareaComp;
				scanf( "%i", &numeroTareaComp);
				limpiar_pantalla();
				marcarTareaCompletada(numeroTareaComp);
				break;

			case '8': // Ver tareas completadas
				printf("----------------------------\n");
				printf("Lista de Tareas Completadas: \n");
				leerTareasCompletadas();
				printf("----------------------------\n");
				printf("\n");
				break;

		}

    } while ( opcion != '9' );

	limpiar_pantalla();

	// TODO LIBERAR MEMORIA
	free(titulo);
	free(descripcion);
	free(fecha);
	free(minutos);
	free(importancia);

	titulo=NULL;
	descripcion=NULL;
	fecha=NULL;
	minutos=NULL;
	importancia=NULL;

}

int main(void)
{
	printf("----------------------------\n");
	printf(" Bienvenido a AgendaMatic! \n");
	printf("----------------------------\n");
	echo();

	return 0;
}

