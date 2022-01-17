#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main() {

    const int dim=11;
    int i=0,pos=-1;
    char cadena[dim];
    char letra;


    printf("Ingrese una cadena de texto\n");
    fflush(stdin);
    gets(cadena);

    printf("Ingrese una letra a buscar\n");
    fflush(stdin);
    scanf("%c",&letra);
    fflush(stdin);

    while((cadena[i])!= '\0')
    {

        if(cadena[i]==letra)
        {
            printf("Posicion = %d\n",i);
            pos=i;
        }

        i++;

    }

    if(pos==-1)
    {
       printf("Posicion = %d",pos);
    }

    //printf("%s\n",cadena);



    system ("pause");

    return 0;

}
