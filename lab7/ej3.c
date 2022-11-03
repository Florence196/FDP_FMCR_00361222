//Librerias
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) //función principal
{
    FILE *vocales; //variable file, vocal almacena el número de vocales en la palabra

    /*variable enteros
    word_length = almacena el número de letras que tiene
    cont_a, cont_e, con_i, cont_o, cont_u = almacenan la cantidad vocales que tiene la palabra
    fn = indica si es la primera palabra o si no lo es*/
    int word_length=0, cont_a, cont_e, cont_i, cont_o, cont_u, fn; 

    /*variable caracter
    respuesta = almacena la respuesta (si o no), ingresada por el usuario
    word = almacena la palabra ingresada*/
    char respuesta[3], word[50];

    fn = 0; //indica que es la primera palabra ingresada

    do //inicio de procesos del bucle do while
    {
        //asignación del 0 a los contadores para que al repetir el bucle se reinicien
        cont_a = 0, cont_e=0, cont_i=0, cont_o=0, cont_u=0;

        //ingreso y lectura de la palabra
        printf("Ingrese una palabra: ");
        scanf("%s", &word);

        if (!fn) //en caso de ser la primera palabra
        {
            /*asignación del fichero palabra.txt a la variable vocales,
            además se indica que se debe sobreescribir al poner la 'w', en caso de no existir el fichero se crea*/
            vocales = fopen("palabra.txt", "w"); 

            word_length = strlen(word); //se almacena el número de letras de word en word_length

            //bucle for, este se repite hasta analizar todas las letras de word
            for (int i = 0; i < word_length; i++) 
            {
                switch (word[i]) //analiza cada letra de word
                {
                case 'a': //en caso de tener una a
                    cont_a++; //aumenta el contador de a's
                    break;

                case 'e': //en caso de tener una e
                    cont_e++; //aumenta el contador de e's
                    break;

                case 'i': //en caso de tener una i
                    cont_i++; //aumenta el contador de i's
                    break;

                case 'o': //en caso de tener una o
                    cont_o++; //aumenta el contador de o's
                    break;

                case 'u': //en caso de tener una u
                    cont_u++; //aumenta el contador de u's
                    break;             
                }
            }
            
            //impresiones en el fichero "palabra.txt"
            fprintf(vocales, "La palabra %s tiene:\n", word);
            fprintf(vocales, "\t%i a en la palabra\n", cont_a);
            fprintf(vocales, "\t%i e en la palabra\n", cont_e);
            fprintf(vocales, "\t%i i en la palabra\n", cont_i);
            fprintf(vocales, "\t%i o en la palabra\n", cont_o);
            fprintf(vocales, "\t%i u en la palabra\n\n\n", cont_u);

            fclose(vocales); //cierra el fichero

            fn = 1; //se indica que si se ingresa otra palabra no será la primera
        }


        else if (fn) //en caso de no ser la primera palabra
        {
            /*asignación del fichero palabra.txt a la variable vocales,
            además se indica que se debe escribir al final al poner la 'a', en caso de no existir el fichero se crea*/
            vocales = fopen("palabra.txt", "a"); 

            word_length = strlen(word); //se almacena el número de letras de word en word_length

            //bucle for, este se repite hasta analizar todas las letras de word
            for (int i = 0; i < word_length; i++)
            {
                switch (word[i]) //analiza cada letra de word
                {
                case 'a': //en caso de tener una a
                    cont_a++; //aumenta el contador de a's
                    break;

                case 'e': //en caso de tener una e
                    cont_e++; //aumenta el contador de e's
                    break;

                case 'i': //en caso de tener una i
                    cont_i++; //aumenta el contador de i's
                    break;

                case 'o': //en caso de tener una o
                    cont_o++; //aumenta el contador de o's
                    break;

                case 'u': //en caso de tener una u
                    cont_u++; //aumenta el contador de u's
                    break;             
                }
            }
            
            //impresiones en el fichero "palabra.txt"
            fprintf(vocales, "La palabra %s tiene:\n", word);
            fprintf(vocales, "\t%i a en la palabra\n", cont_a);
            fprintf(vocales, "\t%i e en la palabra\n", cont_e);
            fprintf(vocales, "\t%i i en la palabra\n", cont_i);
            fprintf(vocales, "\t%i o en la palabra\n", cont_o);
            fprintf(vocales, "\t%i u en la palabra\n\n\n", cont_u);

            fclose(vocales); //cierra el fichero

            fn = 1; 
        }


        do //inicio de los procesos del bucle
        {
            //ingreso y lectura de un "si" o "no", estos indican si se desea ingresas otro numero o no
            printf("Desea ingresar otra palabra?: ");
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
