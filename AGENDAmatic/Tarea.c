#include <stdio.h>
#include "Tarea.h"

void guardar(Tarea t)
{
	//Print de prueba
    printf("Titulo %s, Descripcion %s, Fecha %s, Minutos %i, Importancia %i ", t.tit, t.desc, t.fech, t.min, t.imp);
    FILE *f;
    f = fopen("Tareas.txt", "a");
    fprintf(f, "%s %s %s %i %i \n", t.tit,t.desc, t.fech, t.min, t.imp);
    fclose(f);
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
}

void borrarTareas(int numeroTarea)
{
	/*
	char linea[350];
	FILE *b;
	b = fopen("TareasTemp.txt", "a");
	int i=0;
	while (fgets(linea, 350, b) != NULL)
	{
		i=i+1;
		if (i!=numeroTarea)
		{
			fprintf(b, "%s\n", linea);
		}
	}
	fclose(b);
	*/
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
				fprintf(t, "%s %s %s %i %i \n", tarea.tit,tarea.desc, tarea.fech, tarea.min, tarea.imp);
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
}

