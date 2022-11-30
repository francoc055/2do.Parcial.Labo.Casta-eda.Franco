#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "controller.h"
//#include "movies.h"


int menu()
{
    int opcion;
    printf("1-cargar archivo\n");
    printf("2-listar movies\n");
    printf("3-asignar duracion\n");
    printf("4-elegir genero\n");
    printf("5-ordenar por genero\n");
    printf("6-guardar lista ordenada\n");
    printf("7-salir\n");
    scanf("%d", &opcion);

    return opcion;
}

int confirmarSalida(char* pVariable, char confirma, char rechaza)
{
    int ret = 0;
    char resp;
    if(pVariable != NULL)
    {
       printf("confirma salir?");
       fflush(stdin);
       resp = getchar();
       if(resp == 's')
       {
           *pVariable = confirma;
       }
       else
       {
           *pVariable = rechaza;
       }
        ret = 1;
    }

    return ret;
}



int pedirArchivo(char cadena[])
{
    int ret = 0;
    if(cadena != NULL)
    {
        printf("ingrese el nombre del archivo\n");
        fflush(stdin);
        gets(cadena);
        ret = 1;
    }
    return ret;
}

int cargarDatosMovieText(char* path,LinkedList* listaMovies)
{
    int ret = -1;
    FILE* f = NULL;
    char buffer[4][100];
	int cant;
	eMovie* aux;
    if(path != NULL && listaMovies != NULL)
    {
        f = fopen(path, "r");
        if(f == NULL)
        {
            ret = 0;
        }
        else
        {
            fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            do
            {
                cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
                    if(cant < 4)
                    {
                        break;
                    }

                aux = movie_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(aux != NULL)
                {
                    ll_add(listaMovies, aux);
                    aux = NULL;
                    ret = 1;
                }

            }while(!feof(f));
        }
    }
    fclose(f);
    return ret;
}

int listarMovie(eMovie* m)
{
    int ret = 0;
    int id;
    char titulo[50];
    char genero[50];
    int duracion;

    if(m != NULL)
    {
        if(movie_getId(m, &id)
           && movie_getTitulo(m, titulo)
           && movie_getGenero(m, genero)
           && movie_getDuracion(m, &duracion))
        {
            printf("%-5d %26s %20s %15d\n", m->id, m->titulo, m->genero, m->duracion);
            ret = 1;
        }
    }
    return ret;
}
int listarMovies(LinkedList* listaMovies)
{
    int ret = 0;
	int leng;
	eMovie* aux;
		    if(listaMovies != NULL && ll_len(listaMovies) > 0)
		    {
		        leng = ll_len(listaMovies);
		        printf("id\t\t\t titulo\t\t\tgenero\t\tduracion\n"
		        		"---------------------------------------------------------------------------\n");
		        for(int i = 0; i < leng; i++)
		        {
		            aux = (eMovie*) ll_get(listaMovies, i);
		        	listarMovie(aux);
		        }
		        printf("\n\n");
		        ret = 1;
		    }
    return ret;
}

void* generarDuracion(void* pElement)
{
    eMovie* auxMovie = NULL;
    int id;
    char titulo[30];
    char genero[30];
    int duracion;
    char idStr[30];
    char duracionStr[30];
    int min = 100;
    int max = 240;
    if(pElement != NULL)
    {
        movie_getId(pElement, &id);
        movie_getTitulo(pElement, titulo);
        movie_getGenero(pElement, genero);

        duracion = (rand() % (max - min + 1)) + min;

        itoa(id, idStr, 10);
        itoa(duracion, duracionStr, 10);

        auxMovie = movie_newParametros(idStr, titulo, genero, duracionStr);
    }
    return auxMovie;
}

int listMap(LinkedList* lista){
    system("cls");
	int ret=0;
	LinkedList* auxLinkedList;
	eMovie* aux = NULL;
	if(lista != NULL){
		auxLinkedList = ll_map(lista, generarDuracion);
		if(auxLinkedList != NULL){
            ll_clear(lista);
            for(int i = 0; i< ll_len(auxLinkedList); i++)
            {
                aux = (eMovie*) ll_get(auxLinkedList, i);
                ll_add(lista, aux);
            }
			listarMovies(auxLinkedList);
			ret=1;
		}
	}
	return ret;
}

int menuGeneros()
{
    int opcion;
    printf("1-drama\n");
    printf("2-Adventure\n");
    printf("3-Romance\n");
    printf("4-Horror\n");
    printf("5-Musical\n");
    printf("6-Action\n");
    printf("7-Comedy\n");
    printf("8-Documentary\n");
    printf("9-Thriller\n");
    printf("10-Animation\n");
    printf("11-Western\n");
    scanf("%d", &opcion);

    return opcion;
}

int filtrarGenero(LinkedList* listaMovies, LinkedList* listaGenero)
{
    int ret = 0;
    if(listaMovies != NULL)
    {
        switch(menuGeneros())
        {
        case 1:
            listaGenero = ll_filter(listaMovies, filterGeneroDrama);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 2:
            listaGenero = ll_filter(listaMovies, filterGeneroAdventure);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 3:
            listaGenero = ll_filter(listaMovies, filterGeneroRomance);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 4:
            listaGenero = ll_filter(listaMovies, filterGeneroHorror);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 5:
            listaGenero = ll_filter(listaMovies, filterGeneroMusical);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 6:
            listaGenero = ll_filter(listaMovies, filterGeneroAction);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 7:
            listaGenero = ll_filter(listaMovies, filterGeneroComedy);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 8:
            listaGenero = ll_filter(listaMovies, filterGeneroDocumentary);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 9:
            listaGenero = ll_filter(listaMovies, filterGeneroThriller);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 10:
            listaGenero = ll_filter(listaMovies, filterGeneroAnimation);
            guardarGenero("genero.csv", listaGenero);
            break;
        case 11:
            listaGenero = ll_filter(listaMovies, filterGeneroWestern);
            guardarGenero("genero.csv", listaGenero);
        break;
        }
        ret = 1;
    }

    return ret;
}

int filterGeneroDrama(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Drama"))
    {
        ret = 1;
    }
    return ret;
}

int filterGeneroAdventure(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Adventure"))
    {
        ret = 1;
    }
    return ret;
}

int filterGeneroRomance(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Romance"))
    {
        ret = 1;
    }
    return ret;
}

int filterGeneroHorror(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Horror"))
    {
        ret = 1;
    }
    return ret;
}
int filterGeneroMusical(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Musical"))
    {
        ret = 1;
    }
    return ret;
}

int filterGeneroAction(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Action"))
    {
        ret = 1;
    }
    return ret;
}

int filterGeneroComedy(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Comedy"))
    {
        ret = 1;
    }
    return ret;
}

int filterGeneroDocumentary(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Documentary"))
    {
        ret = 1;
    }
    return ret;
}
int filterGeneroThriller(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Thriller"))
    {
        ret = 1;
    }
    return ret;
}

int filterGeneroAnimation(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Animation"))
    {
        ret = 1;
    }
    return ret;
}
int filterGeneroWestern(void* pElement)
{
    int ret = 0;
    if(!strcmp(((eMovie*) pElement)->genero, "Western"))
    {
        ret = 1;
    }
    return ret;
}

int guardarGenero(char* path, LinkedList* listaGenero)
{
    int ret = 0;
    int leng;
    int cant;
    int flag = 0;
    FILE* f = NULL;
    eMovie* aux = NULL;
    if(path != NULL && listaGenero != NULL)
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            printf("no se pudo abrir el archivo\n");
        }
        else
        {
            leng = ll_len(listaGenero);
            fprintf(f, "id,titulo,genero,rating\n");

            for(int i = 0; i < leng; i++)
            {
                aux = (eMovie*) ll_get(listaGenero, i);
                if(aux != NULL)
                {
                    cant = fprintf(f, "%d,%s,%s,%d\n", aux->id, aux->titulo, aux->genero, aux->duracion);
                    if(cant < 4)
                    {
                        flag =1;
                        break;
                    }
                    ret = 1;
                }
                else
                {
                     printf("hola\n");
                }
            }
            if(flag)
            {
                printf("hubo un problema al guardar las personas\n");
            }
            else
            {
                printf("movies guardadas con exito\n");
            }
        }
    }
    fclose(f);
    return ret;
}

int compareGenero(void* p, void* q)
{
    int rta = 0;
	eMovie* m1;
	eMovie* m2;

	if(p != NULL && q != NULL)
	{
		m1 = (eMovie*) p;
		m2 = (eMovie*) q;
		rta = strcmp(m1->genero, m2->genero);
	}
	return rta;
}




int ordenar(LinkedList* listaMovies)
{
    int ret = 0;
    eMovie* auxI = NULL;
    eMovie* auxJ = NULL;
    eMovie* aux = NULL;
    int leng;
    if(listaMovies != NULL)
    {
        ll_sort(listaMovies, compareGenero, 1);
        leng = ll_len(listaMovies);
        for(int i = 0; i < leng - 1; i++)
        {
            auxI = (eMovie*) ll_get(listaMovies, i);
            for(int j = i + 1; j < leng; j++)
            {
                auxJ = (eMovie*) ll_get(listaMovies, j);
                if(!strcmp(auxI->genero, auxJ->genero)
                   && auxI->duracion < auxJ->duracion)
                {
                    aux = auxI;
					ll_set(listaMovies, i, auxJ);
					ll_set(listaMovies, j, aux);
                }
            }
        }
        ret = 1;
    }
    return ret;
}

int guardarListaOrdenada(char* path, LinkedList* listaOrdenada)
{
    int ret = 0;
    int leng;
    int cant;
    int flag = 0;
    FILE* f = NULL;
    eMovie* aux = NULL;
    if(path != NULL && listaOrdenada != NULL)
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            printf("no se pudo abrir el archivo\n");
        }
        else
        {
            leng = ll_len(listaOrdenada);
            fprintf(f, "id,titulo,genero,rating\n");

            for(int i = 0; i < leng; i++)
            {
                aux = (eMovie*) ll_get(listaOrdenada, i);
                if(aux != NULL)
                {
                    cant = fprintf(f, "%d,%s,%s,%d\n", aux->id, aux->titulo, aux->genero, aux->duracion);
                    if(cant < 4)
                    {
                        flag =1;
                        break;
                    }
                    ret = 1;
                }
                else
                {
                     printf("hola\n");
                }
            }
            if(flag)
            {
                printf("hubo un problema al guardar las personas\n");
            }
            else
            {
                printf("personas guardadas con exito\n");
            }
        }
    }
    fclose(f);
    return ret;
}






