#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int main() {

    const int dim=40,dim2=5;
    char frase[dim];
    // char frase[40]="Informatica Basica";
    //char frase[40]="Fundamentos de Informatica";

    char anacronimo[5];
    int i=0,j=0;

    printf("Ingrese una frase y la transformamos en anacronimo: \n");
    fflush(stdin);
    gets(frase);
    fflush(stdin);

    while(frase[i]!='\0')
    {
        if(i==0)
        {
            anacronimo[j]=toupper(frase[i]);
            j++;
        }
        else
        {
            if(((isblank(frase[i]))!= 0)&&((isblank(frase[i+1]))== 0))
            {
                 anacronimo[j]=toupper(frase[i+1]);
                j++;
            }
        }

        i++;
    }





    printf("El anacronimo es: %s\n",anacronimo);




    system ("pause");

    return 0;

}
