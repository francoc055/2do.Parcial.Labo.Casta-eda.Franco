#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct{
int id;
char titulo[20];
char genero[20];
int duracion;
}eMovie;


#endif // MOVIES_H_INCLUDED

eMovie* movie_new();
eMovie* movie_newParametros(char* idStr,char* titulo,char* genero, char* duracionStr);

void movie_delete(eMovie* this);

int movie_setId(eMovie* this,int id);
int movie_getId(eMovie* this,int* id);

int movie_setTitulo(eMovie* this,char* titulo);
int movie_getTitulo(eMovie* this,char* titulo);

int movie_setGenero(eMovie* this,char* genero);
int movie_getGenero(eMovie* this,char* genero);

int movie_setDuracion(eMovie* this,int duracion);
int movie_getDuracion(eMovie* this,int* duracion);
