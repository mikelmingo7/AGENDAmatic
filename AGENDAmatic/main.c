#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "main.h"
#include "Tarea.h"
#include "Menu.h"

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

	//Variables fecha
	time_t t = time(NULL);
	struct tm tiempoLocal = *localtime(&t);
	char fechaActual[11];
	char *formato = "%d/%m/%Y";

	int tiempoDispone;

	do
    {
		mostrarMenu();

		do
		{
			opcion = menuOpcion();

		} while ( opcion < '1' || opcion > '8' );

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
				printf("Introduce una fecha con el formato (00/00/0000) : ");
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


				printf("Introduce una fecha con el formato (00/00/0000) : ");
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
			case '5':
				limpiar_pantalla();
				printf("  \n");
				printf("Has elegido la opcion: 5 (Ver tareas de hoy) \n");
				printf("  \n");
				strftime(fechaActual, sizeof fechaActual, formato, &tiempoLocal);
				printf("Fecha y hora: %s \n", fechaActual);
				printf("  \n");
				leerTareasFecha(fechaActual);

				break;

			case '6':
				limpiar_pantalla();
				printf("  \n");
				printf("Has elegido la opcion: 6 (Ver tareas de una fecha determinada) \n");
				printf("  \n");

				//strftime(fechaActual, sizeof fechaActual, formato, &tiempoLocal);
				//printf("Fecha y hora: %s \n", fechaActual);
				//leerTareasFecha(fechaActual);

				printf("Introduce una fecha con el formato (00/00/0000) : ");
				fflush( stdin );
				scanf("%s", fechaActual);
				leerTareasFecha(fechaActual);
				break;

			case '7':
				limpiar_pantalla();
				printf("  \n");
				printf("Has elegido la opcion: 7 (Sugerir una tarea) \n");
				printf("  \n");
				printf("Introduce el tiemo en minutos del que dispones");
				fflush( stdin );
				scanf("%i", &tiempoDispone);
				sugerirTarea(tiempoDispone);

				break;

		}

    } while ( opcion != '8' );

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

