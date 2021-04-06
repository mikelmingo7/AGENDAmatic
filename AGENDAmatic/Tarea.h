/*
 * Tarea.h
 *
 *  Created on: 5 abr. 2021
 *      Author: Julen
 */

#ifndef TAREA_H_
#define TAREA_H_
#define MAXCHAR 1000

typedef struct Tarea
{
	char tit[101];
    char desc[201];
    char fech[12];
    int min;
    int imp;

}Tarea;

void guardar(Tarea t);
void borrarTareas(int numeroTarea);
void editarTarea(int numeroTarea, Tarea tarea);

#endif /* TAREA_H_ */