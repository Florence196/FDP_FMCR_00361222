//Librerias
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) //función principal
{

    /*variable tipo file
    num_positivo = almacena los números positivos
    num_negativo = almacena los números negativos*/
    FILE *num_positivo, *num_negativo; 

    /*variable tipo entero
    num = almacena el numero que ingresará el usuario
    s_po = indica si es el primer numero positivo que se ingresa, o si no es el primero
    s_ne = indica si es el primer numero negativo que se ingresa, o si no es el primero*/
    int num, s_po, s_ne; 

    /*variable tipo caracter
    u = u con tilde
    respuesta = almacena la respuesta que ingresará el usuario, solo debe ser 'si' o 'no' */
    char u = 163, respuesta[3];

    /*constante tipo entero
    siguiente = indica si no es la primera vez que se ingresa ese tipo de número
    first = indica si es la primera vez que se ingresa ese tipo de número*/
    const int siguiente = 1, first = 0;

    /*se almacena first en s_po y s_ne para indicar que sería la primera vez que se 
    ingresa un número positivo o negativo*/
    s_po = first;
    s_ne = first;

    do //inicio de procesos del bucle do while
    {
        //ingreso y lectura de num
        printf("Ingrese un n%cmero: ", u);
        scanf("%i", &num);

        if ((num > 0) && (s_po == first)) //en caso de ser positivo y que sea el primer positivo ingresado
        {
            /*se asigna el fichero "numeros_positivos a la variable file num_positivo"
            además se indica que se sobreescribirá el documento al poner la "w"*/
            num_positivo = fopen("numeros_positivos.txt", "w"); 

            fprintf(num_positivo, "%i", num); //imprime num en el fichero "numeros_positivos"

            fclose(num_positivo); //cierra el fichero

            s_po = siguiente; //se asigna siguiente a s_po
        }


        else if ((num > 0) && (s_po == siguiente)) //en caso de ser un número y que no sea el primero
        {
            /*se asigna el fichero "numeros_positivos a la variable file num_positivo"
            además se indica que se debe escribir al final del documento al poner la "a"*/
            num_positivo = fopen("numeros_positivos.txt", "a"); 

            fprintf(num_positivo, "\n%i", num); //imprime num en el fichero

            fclose(num_positivo); //cierra el fichero
        }


        else if ((num < 0) && (s_ne == first)) //en caso de ser negativo y que sea el primer negativo ingresado
        {
            /*se asigna el fichero "numeros_negativos a la variable file num_negativo"
            además se indica que se debe sobreescribir el documento al poner la "w"*/
            num_negativo = fopen("numeros_negativos.txt", "w"); 

            fprintf(num_negativo, "%i", num); //imprime num en el fichero "numeros_negativos"

            fclose(num_negativo); //cierra el fichero

            s_ne = siguiente; //se asigna siguiente a la variable s_ne
        }


        else if ((num < 0) && (s_ne == siguiente)) //en caso de ser negativo y que no sea el primero
        {
            /*se asigna el fichero "numeros_negativos a la variable file num_negativo"
            además se indica que se debe escribir al final del documento al poner la "w"*/
            num_negativo = fopen("numeros_negativos.txt", "a");

            fprintf(num_negativo, "\n%i", num); //imprime num en el fichero

            fclose(num_negativo); //cierra el fichero
        }


        do //inicio de los procesos del bucle
        {
            //ingreso y lectura de un "si" o "no", estos indican si se desea ingresas otro numero o no
            printf("Desea ingresar otro n%cmero?: ", u);
            scanf("%s", &respuesta);

            if ((strcmp(respuesta, "si") != 0) && (strcmp(respuesta, "no") != 0)) //en caso de respuesta erronea
            {
                printf("\nRespuesta incorrecta\n\n"); //mensaje de error
            }

        } while ((strcmp(respuesta, "si") != 0) && (strcmp(respuesta, "no") != 0)); /*se repite en caso de ingresar una 
        respuesta distinta a si o no, es decir, en caso de respuesta erronea*/

    } while (strcmp(respuesta, "si") == 0); //repetición en caso de que la respuesta sea si

    return 0;
}