//Librerias
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) //función principal
{
    FILE *palabra = fopen("palabras.txt", "r"); //variable tipo file donde están las palabras
    char word[10]; //variable tipo char donde se almacena la palabra del fichero
    int word_length, a = 0, e = 0, i = 0, o = 0, u = 0, contador = 0; //variable entero, para ver la cantidad de letras de la palabra y algunos contadores


    while (fgets(word, 10, palabra) != NULL) //repeticion hasta leer todas las palabras 
    {

        if (strstr(word, "\n")) //en caso de leer un enter se quita del largo de la palabra
        {
            word_length = strlen(word);
            word_length--;
        }
        else //en caso de no leer enter
        {
            word_length = strlen(word);
        }

       

        for (int n = 0; n < word_length; n++) //analisis de cada palabra
        {
            if (word[n] == 'a' && contador == 0) //en caso de ser la primera palabra se buscan a en ella
            {
                a++; //aumento de  contador de a's
            }
            else if (word[n] == 'e' && contador == 1) //en caso de ser la segunda palabra se buscan e en ella
            {
                e++; //aumento de  contador de e's
            }
            else if (word[n] == 'i' && contador == 2) //en caso de ser la tercera palabra se buscan i en ella
            {
                i++; //aumento de  contador de i's
            }
            else if (word[n] == 'o' && contador == 3) //en caso de ser la cuarta palabra se buscan o en ella
            {
                o++; //aumento de  contador de o's
            }
            else if (word[n] == 'u' && contador == 4) //en caso de ser la quinta palabra se buscan u en ella
            {
                u++; //aumento de  contador de u's
            }
        }

        if (contador == 0) //en caso de la primera palabra, impresion de las a contadas
            {
                printf("\n%stiene %i a\n", word, a);
            }
            else if (contador == 1) //en caso de la segunda palabra, impresion de las e contadas
            {
                printf("\n%stiene %i e\n", word, e);
            }
            else if (contador == 2) //en caso de la tercera palabra, impresion de las i contadas
            {
                printf("\n%stiene %i i\n", word, i);
            }
            else if (contador == 3) //en caso de la cuarta palabra, impresion de las o contadas
            {
                printf("\n%stiene %i o\n", word, o);
            }
            else if (contador == 4) //en caso de la quinta palabra, impresion de las u contadas
            {
                printf("\n%s\ntiene %i u\n", word, u);
            }

        contador++; //aumento del contador, indica que palabra se analiza

        
    }

    fclose(palabra); //cierre del fichero

    return 0;
}