#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void esetroquemayor(char txt[]);

int main() {

    const int dim=100;
    char texto[dim];

    printf("Ingrese un texto y le diremos cuantas letras tiene cada palabra -max 100 caracteres-\ntexto : ");
    fflush(stdin);
    gets(texto);

    esetroquemayor(texto);




    system ("pause");

    return 0;

}


void esetroquemayor(char txt[])
{
    char cad_1[20];
    char *ptkn;
    int i=0,j=0,num,cont=0;

    ptkn=strtok(txt," ");

    while(ptkn!=NULL)
    {
        printf("%s",ptkn);
        strcpy(cad_1,ptkn);

        while(cad_1[j]!='\0')
        {
            cont++;
            j++;
        }

        printf("  %d\n",cont);

        num=strlen(cad_1);

        cont=0;
        j=0;


        ptkn=strtok(NULL," ");
    }

    return;
}
