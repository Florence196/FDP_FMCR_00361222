//Florence Marcela Cruz Ventura 00361222

// Librerias
#include <stdio.h>
#include <string.h> //permite usar strstr

int main(int argc, char *argv[]) // función principal
{

    /*variables string y caracter, texto es un arreglo donde se almacena la frase "Hola mundo etcetera
    e y o son letras con tildes
    palabra = la palabra o combinación de letras que se buscará en texto"*/
    char texto[100] = "Hola mundo etcetera", e = 130, palabra[50], o = 162;

    printf("El texto es: %s", texto); // imprime la frase de texto

    // Ingreso de la palabra o combinación de letras que se buscará
    printf("\n\nQu%c palabra o combinaci%cn de letras desea buscar?: ", e, o);
    scanf("%s", palabra);

    if (strstr(texto, palabra)) // en caso de encontrar la palabra o combinacion de letras en texto
    {
        printf("La palabra o combinaci%cn de letras que busca se encuentra en el texto", o);
    }
    else // en caso de no encontrar la palabra o combinacion de letras en texto
    {
        printf("No se encuentr%c lo que buscaba en el texto", o);
    }

    return 0;
}