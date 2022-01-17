//Resuelto B y C, falta el A

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int main() {
    const int dim=10;
    //char texto[dim];
    int contador,i=0;
    char texto[100]="Hala cama astas  ppppppppaaaai yyyyyyyyaaaapp ppppppppppppppppaaaaaii."; //debuger
    char vocal[6]="aeiou";
    char letra,letra2;

    //A falta desarrollar el A
    //B
    //contador=strlen(texto);
    //printf("Longitud del texto: %d\n",contador);

    //C
    contador=0;
    contador=esetroquemayor(texto);
    printf("Cantidad de Palabras con mas de 3 letras a y entre 8 y 16 caracteres = %d\n",contador);

    system ("pause");

    return 0;

}

int esetroquemayor(char txt[])
{
    char cad_1[20];
    char *ptkn;
    int i=0,j=0,num,cont=0,pcont=0,conta=0;

    ptkn=strtok(txt," ");

    while(ptkn!=NULL)
    {
        printf("%s\n",ptkn);
        strcpy(cad_1,ptkn);

        while(cad_1[j]!='\0')
        {
            if(cad_1[j]=='a')
            {
                conta++;
            }

            cont++;
            j++;
        }

        num=strlen(cad_1);

        if ((8<=num)&&(num<=16)&&(conta>3))
        {
            pcont++;
        }

        conta=0;
        cont=0;
        j=0;


        ptkn=strtok(NULL," ");
    }

    return pcont;
}

