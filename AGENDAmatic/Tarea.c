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
