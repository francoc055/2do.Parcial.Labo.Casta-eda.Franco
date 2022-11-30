#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movies.h"

eMovie* movie_new()
{
    eMovie* m = (eMovie*) malloc(sizeof(eMovie));
    if(m != NULL)
    {
        m->id = 0;
        *(m->titulo) = '\0';
        *(m->genero) = '\0';
        m->duracion = 0;
    }
    return m;
}
eMovie* movie_newParametros(char* idStr,char* titulo,char* genero, char* duracionStr)
{
    eMovie* m = movie_new();
    if(m != NULL)
    {
        if(!(movie_setId(m, atoi(idStr)) &&
        movie_setTitulo(m, titulo) &&
        movie_setGenero(m, genero) &&
        movie_setDuracion(m, atof(duracionStr))))
        {
            free(m);
            m = NULL;
        }
    }

	return m;
}

void movie_delete(eMovie* this)
{
    free(this);
}

int movie_setId(eMovie* this,int id)
{
    int ret = 0;

	    if(this != NULL && id >= 1)
	    {
	        this->id = id;
	        ret = 1;
	    }

	return ret;
}
int movie_getId(eMovie* this,int* id)
{
    int ret = 0;
	    if(this != NULL && id != NULL)
	    {
	        *id = this->id;
	        ret = 1;
	    }
	return ret;
}

int movie_setTitulo(eMovie* this,char* titulo)
{
    int ret = 0;
	    if(this != NULL && titulo != NULL && strlen(titulo) <= 100)
	    {
	        strcpy(this->titulo, titulo);
	        this->titulo[0] = toupper(this->titulo[0]);
	        ret = 1;
	    }
	return ret;
}
int movie_getTitulo(eMovie* this,char* titulo)
{
    int ret = 0;

	    if(this != NULL && titulo != NULL)
	    {
	        strcpy(titulo, this->titulo);

	        ret = 1;
	    }
	return ret;
}

int movie_setGenero(eMovie* this,char* genero)
{
    int ret = 0;
	    if(this != NULL && genero != NULL && strlen(genero) <= 100)
	    {
	        strcpy(this->genero, genero);
	        this->genero[0] = toupper(this->genero[0]);
	        ret = 1;
	    }
	return ret;
}
int movie_getGenero(eMovie* this,char* genero)
{
    int ret = 0;

	    if(this != NULL && genero != NULL)
	    {
	        strcpy(genero, this->genero);

	        ret = 1;
	    }
	return ret;
}

int movie_setDuracion(eMovie* this,int duracion)
{
    int ret = 0;

	    if(this != NULL && duracion >= 0)
	    {
	        this->duracion = duracion;
	        ret = 1;
	    }

	return ret;
}
int movie_getDuracion(eMovie* this,int* duracion)
{
    int ret = 0;
	    if(this != NULL && duracion != NULL)
	    {
            *duracion = this->duracion;
	        ret = 1;
	    }
	return ret;
}

