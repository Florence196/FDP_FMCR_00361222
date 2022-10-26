//Florence Marcela Cruz Ventura 00361222

// Librerias
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) // funcion main
{
    int longitud; // variable entero donde se almacena la longitud de la palabra ingresada

    /*Varaibles caracter, palabra = donde se almacenará la palabra ingresada
    letra1 = donde se almacenará la primera letra de la palabra
    i = i con tilde*/
    char palabra[50], letra1, i = 161;

    // ingreso y lectura de la palabra que se analizará
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    /* Se almacena la longitud de la palabra -1
    El -1 hace que la longitud de la palabra se adapte a las casillas utilizadas en el arreglo, es decir que empiece en 0 */
    longitud = strlen(palabra) - 1;

    letra1 = palabra[0]; // almacena la primera letra de la palabra en la variable letra1

    if (palabra[longitud] == letra1) // en caso de que la ultima letra de la palabra sea la misma que la primera letra
    {
        printf("La palabra '%s' es un pal%cndromo", palabra, i);
    }
    else // en caso de que la ultima letra de la palabra no sea la misma que la primera letra
    {
        printf("La palabra '%s' no es un pal%cndromo", palabra, i);
    }

    return 0;
}