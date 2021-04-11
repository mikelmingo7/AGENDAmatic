#include <stdio.h>
#include "Tarea.h"
#include <string.h>
#include <windows.h>

void limpiar_pantalla() // Funcion principal para limpiar la pantalla (eliminar texto para la visión del usuario)
{
  //windows
  #ifdef _WIN32
    system("cls");
  //linux
  #else
    system("clear");
  #endif
}

void guardar(Tarea t)
{
	//Print de la tarea
    printf("Titulo %s, Descripcion %s, Fecha %s, Minutos %i, Importancia %i \n", t.tit, t.desc, t.fech, t.min, t.imp);
    FILE *f;
    f = fopen("Tareas.txt", "a");
    fprintf(f, "%s %i %i %s %s \n",t.fech, t.min, t.imp, t.tit,t.desc);
    fclose(f);
    printf("Tarea guardada con exito \n");
}

void leerTareas()
{
	char linea[350];
	FILE *l;
	l = fopen("Tareas.txt", "r");
	int i=0;
	while (fgets(linea, 350, l) != NULL)
	{
		i=i+1;
		printf(" %i. %s ", i,linea);
	}
	fclose(l);
	printf("  \n");
	if (i==0)
		{
			printf("Ninguna tarea creada \n");
		}else {
			printf("Mostradas las %i tareas creadas \n",i);
		}
	printf("  \n");
}
void leerTareasFecha(char fechaActual[11])
{
	char linea[350];
	char fecha[350];
	int resultadoComparacion;
	FILE *l;
	l = fopen("Tareas.txt", "r");
	int i=0;
	while (fgets(linea, 350, l) != NULL)
	{
		strcpy(fecha,linea);
		fecha[strcspn(fecha, " ")] = 0;
		resultadoComparacion = stricmp(fechaActual, fecha);
		if (resultadoComparacion==0) {
			i=i+1;
			printf(" %i. %s \n", i,linea);
		}

	}
	fclose(l);
	printf("  \n");
	if (i==0)
	{

		printf("Ninguna tarea creada \n");
	}else {
		printf("Mostradas las %i tareas creadas \n",i);
	}
	printf("  \n");
}

void leerTareasCompletadas()
{
	const char invalid_chars[10] = "Completada";
	char linea[350];
	// Abrimos el fichero
	FILE *l;
	l = fopen("Tareas.txt", "r");
	int i=0;
	int cont = 0;
	while (fgets(linea, 350, l) != NULL)
	{
		i=i+1;
		if (strchr(linea, *invalid_chars)) { // Comprobar si está completada
			printf(" %i. %s ", i,linea);
			cont++;
		}

	}
	fclose(l);
	printf("  \n");
	if (cont==0)
		{
			printf("Ninguna tarea completada \n");
		}else {
			printf("Mostradas las %i tareas completadas \n",cont);
		}
	printf("  \n");
}

void borrarTareas(int numeroTarea)
{
	char linea[350];
	FILE *b;
	b = fopen("Tareas.txt", "r");
	int i=0;
	FILE *t;
	t = fopen("TareasTemp.txt", "a");
	while (fgets(linea, 350, b) != NULL)
		{
			i=i+1;
			if (i!=numeroTarea)
			{
				fprintf(t, "%s", linea);
			}
		}
	fclose(b);
	fclose(t);
	b = fopen("Tareas.txt", "w");
	fclose(b);
	b = fopen("Tareas.txt", "a");
	t = fopen("TareasTemp.txt", "r");
	while (fgets(linea, 350, t) != NULL)
	{
		fprintf(b, "%s", linea);

	}
	fclose(b);
	fclose(t);
	t = fopen("TareasTemp.txt", "w");
	fclose(t);
	printf(" \n");
	printf("Tarea borrada con exito \n");
	printf(" \n");
}
void editarTarea(int numeroTarea, Tarea tarea)
{
	char linea[350];
	FILE *b;
	b = fopen("Tareas.txt", "r");
	int i=0;
	FILE *t;
	t = fopen("TareasTemp.txt", "a");
	while (fgets(linea, 350, b) != NULL)
		{
			i=i+1;
			if (i==numeroTarea)
			{
				fprintf(t, "%s %i %i %s %s \n",tarea.fech, tarea.min, tarea.imp, tarea.tit,tarea.desc);
			}else
			{
				fprintf(t, "%s", linea);
			}
		}
	fclose(b);
	fclose(t);
	b = fopen("Tareas.txt", "w");
	fclose(b);
	b = fopen("Tareas.txt", "a");
	t = fopen("TareasTemp.txt", "r");
	while (fgets(linea, 350, t) != NULL)
	{
		fprintf(b, "%s", linea);

	}
	fclose(b);
	fclose(t);
	t = fopen("TareasTemp.txt", "w");
	fclose(t);
	printf(" \n");
	printf("Tarea editada con exito \n");
	printf(" \n");
}
void marcarTareaCompletada(int numeroTareaCompletada)
{
	char linea[350];
	FILE *b;
	b = fopen("Tareas.txt", "r");
	int i=0;
	FILE *t;
	t = fopen("TareasTemp.txt", "a");
	while (fgets(linea, 350, b) != NULL)
		{
			i=i+1;
			if (i==numeroTareaCompletada)
			{
				linea[strcspn(linea, "\n")] = 0;
				strcat(linea," Completada \n");
				fprintf(t, "%s", linea);
			}else
			{
				fprintf(t, "%s", linea);
			}
		}
	fclose(b);
	fclose(t);
	b = fopen("Tareas.txt", "w");
	fclose(b);
	b = fopen("Tareas.txt", "a");
	t = fopen("TareasTemp.txt", "r");
	while (fgets(linea, 350, t) != NULL)
	{
		fprintf(b, "%s", linea);

	}
	fclose(b);
	fclose(t);
	t = fopen("TareasTemp.txt", "w");
	fclose(t);
	printf(" \n");
	printf("Tarea marcada como completada \n");
	printf(" \n");
}

