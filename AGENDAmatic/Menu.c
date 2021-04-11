#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Tarea.h"

char opcion;

void mostrarMenu()
{
	printf("  1.Ver tareas \n");
	printf("  2.Anyadir una tarea \n");
	printf("  3.Editar una tarea \n");
	printf("  4.Borrar una tarea \n");
	printf("  5.Ver tareas de hoy \n");
	printf("  6.Ver tareas de una fecha determinada \n");
	printf("  7.Marcar una tarea como completada \n");
	printf("  8.Salir \n");
	printf("\n");

}

char menuOpcion()
{
	printf( "  Introduce una opcion: \n");
	fflush( stdin );
	scanf( "%c", &opcion );

	limpiar_pantalla();
	printf("\n");
	printf("Has elegido la opcion: %c\n", opcion);
	printf("\n");

	return opcion;
}
