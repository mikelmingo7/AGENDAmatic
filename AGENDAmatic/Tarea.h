/*
 * tarea.h
 */

#ifndef TAREA_H_
#define TAREA_H_

typedef struct Tarea
{
	char tit[101];
    char desc[201];
    char fech[12];
    int min;
    int imp;

}Tarea;

void leerTareas();
void guardar(Tarea t);
void borrarTareas(int numeroTarea);
void editarTarea(int numeroTarea, Tarea tarea);
void leerTareasFecha(char fechaActual[11]);
void marcarTareaCompletada(int numeroTareaCompletada);
void leerTareasCompletadas();
void limpiar_pantalla();

#endif /* TAREA_H_ */
