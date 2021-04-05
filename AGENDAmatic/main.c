#include <stdio.h>
#include <ctype.h>
#include "main.h"
#include "Tarea.h"
#include <stdlib.h>

#include <string.h>

void echo(void)
{
	char opcion;
	Tarea tarea;

	do
    {
		printf("  \n");
		printf("  1.Ver tareas \n");
		printf("  2.Anadir una tarea \n");
		printf("  3.Editar una tarea \n");
		printf("  4.Borrar una tarea \n");
		printf("  5.Salir \n");

		do
		{
			printf( "  Introduce una opcion : \n");
			fflush( stdin );
			scanf( "%c", &opcion );

		} while ( opcion < '1' || opcion > '3' );

		switch ( opcion )
		{
			case '1':
				printf("  \n");
				printf("Has elegido la opcion: 1 \n");

				break;

			case '2':
				printf("  \n");
				printf("Has elegido la opcion: 2 Anadir tarea\n");

				char *titulo = (char *)malloc(100);
				printf("Introduce un titulo");
				fflush( stdin );
				fgets(titulo, 100, stdin);
				//scanf("%s", titulo);
				//tarea.tit= titulo;
				//Para borrar el salto de linea
				titulo[strcspn(titulo, "\n")] = 0;
				strcpy(tarea.tit,titulo);

				char *descripcion = (char *)malloc(200);
				printf("Introduce una descripcion");
				fflush( stdin );
				//scanf("%s", descripcion);
				//tarea.desc= *descripcion;
				fgets(descripcion, 200, stdin);
				descripcion[strcspn(descripcion, "\n")] = 0;
				strcpy(tarea.desc,descripcion);

				char *fecha = (char *)malloc(11);
				printf("Introduce una fecha");
				fflush( stdin );
				scanf("%s", fecha);
				//tarea.fech= *fecha;
				strcpy(tarea.fech,fecha);

				int *minutos = (int *)malloc(6);
				printf("Introduce una duracion en minutos ");
				fflush( stdin );
				scanf("%i", minutos);
				tarea.min= *minutos;
				//strcpy(tarea.min,minutos);

				int *importancia = (int *)malloc(2);
				printf("Introduce la importancia del  1 al 10");
				fflush( stdin );
				scanf("%i", importancia);
				tarea.imp= *importancia;
				//strcpy(tarea.imp,importancia);

				printf("\n");
				guardar(tarea);

				break;

		}

    } while ( opcion != '5' );

}

int main(void)
{
	printf("Hola soy AGENDAmatic!\n");
	printf("Bienvenido a AgendaMatic\n");
	printf("Hola!");
	printf("awa");
	echo();
	return 0;
}

