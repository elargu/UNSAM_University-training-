#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void escribir(char cade[]);
void inversa(char vc[],int d);


int main() {

    const int dimen=50;
    char cadena[50];
    //char cadena[]="la pelopincho pinchada";
    int dim;

    escribir(cadena);

    dim=strlen(cadena);

    printf("Cadena es:\n%s\n",cadena);

    inversa(cadena,dim);




    system ("pause");

    return 0;

}

void escribir(char cade[])
{
    printf("Ingrese un texto: ");
    fflush(stdin);
    gets(cade);

    return;
}

void inversa(char vc[],int d)
{
    int i=d;

    while(i>=0)
    {
        printf("%c",vc[i]);

        i--;
    }

    printf("\n");

    return;

}
