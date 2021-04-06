#include <stdio.h>
#include <ctype.h>
#include "main.h"

void echo(void)
{
	char opcion;

	do
    {
		printf("  \n");
		printf("  1.Opcion (Introduce una tarea nueva) \n");
		printf("  2.Opcion \n");
		printf("  3.Salir \n");

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
				
    			char* tarea = (char*) malloc(sizeof(tarea)*100);
				printf("Has elegido la opcion: 1 \n");
				printf("Introduce una nueva tarea: ");
				scanf("%s", &tarea);
				fflush(stdin);
				getch();
				printf("%c", tarea);
				break;

			case '2':
				printf("  \n");
				printf("Has elegido la opcion: 2 \n");

				break;

		}

    } while ( opcion != '3' );

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

