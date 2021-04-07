#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

char opcion;

void mostrarMenu()
{
	printf("  1.Ver tareas \n");
	printf("  2.Anadir una tarea \n");
	printf("  3.Editar una tarea \n");
	printf("  4.Borrar una tarea \n");
	printf("  5.Borrar una tarea \n");
	printf("  6.Borrar una tarea \n");
	printf("  8.Salir \n");
	printf("\n");

}

char menuOpcion()
{
	printf( "  Introduce una opcion: \n");
	fflush( stdin );
	scanf( "%c", &opcion );
	return opcion;
}
