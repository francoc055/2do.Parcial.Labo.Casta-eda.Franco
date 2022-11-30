#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "movies.h"
#include "controller.h"


int main()
{

    LinkedList* listaMovies = ll_newLinkedList();
    LinkedList* listaGenero = ll_newLinkedList();
    char salir = 'n';
    char nombreArchivo[30];
    char nombreArchivoOrdenado[30];
    int flag = 0;
    int flagDuracion = 0;
    int flagOrdenar = 0;
    if(listaMovies == NULL && listaGenero != NULL)
    {
        printf("no se pudo crear el linkedList");
    	exit(1);
    }

    do
    {
        switch(menu())
        {
        case 1:
            pedirArchivo(nombreArchivo);
            if(!strcmp(nombreArchivo, "movies.csv"))
            {
                if(cargarDatosMovieText("movies.csv", listaMovies))
                {
                    printf("archivos leidos con exito\n");
                    flag = 1;
                }
                else
                {
                    printf("no se pudo abrir el archivo\n");
                }
            }
            else
            {
                printf("nombre incorrecto\n");
            }

            break;
        case  2:
            if(flag)
            {
                if(!listarMovies(listaMovies))
                {
                    printf("hubo un error al mostrar\n");
                }
            }
            else
            {
                printf("primero tenes que cargar los archivos\n");
            }
            break;
        case 3:
            if(flag)
            {
                listMap(listaMovies);
                flagDuracion =1;
            }
            else
            {
                printf("primero tenes que cargar los archivos\n");
            }
            break;
        case 4:
            if(flag)
            {
                filtrarGenero(listaMovies, listaGenero);
            }
            else
            {
                printf("primero tenes que cargar los archivos\n");
            }
            break;
        case 5:
            if(flagDuracion)
            {
               if(!ordenar(listaMovies))
                {
                    printf("ocurrio un error al ordenar\n");
                }
                else{
                    printf("ordenamiento exitoso\n");
                    flagOrdenar = 1;
                }
            }
            else
            {
                printf("primero tenes que asignar la duracion\n");
            }

            break;
        case 6:
            if(flagOrdenar)
            {
                if(pedirArchivo(nombreArchivoOrdenado))
                {
                    guardarListaOrdenada(nombreArchivoOrdenado, listaMovies);
                }
            }
            else
            {
                printf("primero tenes que ordenar la lista\n");
            }

            break;
        case 7:
            confirmarSalida(&salir, 's', 'n');
            break;
        default:
            printf("no existe esa opcion\n");
        }
        fflush(stdin);
    }while(salir != 's');


    return 0;
}


