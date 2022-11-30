#include "LinkedList.h"
#include "movies.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

int menu();
int confirmarSalida(char* pVariable, char confirma, char rechaza);

//carga de datos
int pedirArchivo(char cadena[]);
int cargarDatosMovieText(char* path,LinkedList* listaMovies);

//lista movie
int listarMovie(eMovie* m);
int listarMovies(LinkedList* listaMovies);

//duracion aleatoria
void* generarDuracion(void* pElement);
int listMap(LinkedList* lista);

//filtrar por genero
int menuGeneros();
int filtrarGenero(LinkedList* listaMovies, LinkedList* listaGenero);

//funciones filter
int filterGeneroDrama(void* pElement);
int filterGeneroAdventure(void* pElement);
int filterGeneroRomance(void* pElement);
int filterGeneroHorror(void* pElement);
int filterGeneroMusical(void* pElement);
int filterGeneroAction(void* pElement);
int filterGeneroComedy(void* pElement);
int filterGeneroDocumentary(void* pElement);
int filterGeneroThriller(void* pElement);
int filterGeneroHorror(void* pElement);
int filterGeneroAnimation(void* pElement);
int filterGeneroWestern(void* pElement);

//guardo genero
int guardarGenero(char* path, LinkedList* listaGenero);
//funcion compare
int compareGenero(void* p, void* q);

//ordenamiento
int ordenar(LinkedList* listaMovies);

//guardo lista ordenada
int guardarListaOrdenada(char* path, LinkedList* listaOrdenada);
