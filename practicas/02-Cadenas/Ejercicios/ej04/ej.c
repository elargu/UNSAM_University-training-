#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void cargatxt(char txt[]);
void printxt(char txt[]);
int esetroquemayor(char txt[]);
void cuentacvocal(char txt[], char voc[],int vector[]);
void printarenterov(char voc[],int v[]);
void letrayespacio(char txt[], int *letras, int *espacios);


int main() {
    const int dim=10;
    //char texto[dim];
    int contador=0,contador2=0,i=0;
    char texto[100]="hola   como  estas."; //debuger
    char vocal[6]="aeiou";
    char letra,letra2;
    int contadorvocal[5]={0,0,0,0,0};

    //A)
    //contador=0;
    //cargatxt(texto);
    //contador=esetroquemayor(texto);
    //printf("Cantidad de palabras mayores a 10=  %d palabras\n",contador);

    //B)
    //contador=0;
    //cargatxt(texto);
   // cuentacvocal(texto,vocal,contadorvocal);
    //printxt(texto);
    //printf("La cantidad de vocales son\n");
    //printarenterov(vocal,contadorvocal);

    //D)
    //contador=0;
    //contador2=0;
    //cargatxt(texto);

    letrayespacio(texto,&contador,&contador2);
    printxt(texto);
    printf("Cantidad de letras = %d || cantidad de espacios = %d\n",contador,contador2);



    system ("pause");

    return 0;

}


void cargatxt(char txt[])
{
    printf("Ingrese un texto de hasta 100 caracteres y pongale un punto al final: \n");
    fflush(stdin);
    gets(txt);

    return;
}


int esetroquemayor(char txt[])
{
    char cad_1[20];
    char *ptkn;
    int i=0,j=0,num,cont=0,pcont=0;

    ptkn=strtok(txt," ");

    while(ptkn!=NULL)
    {
        printf("%s\n",ptkn);
        strcpy(cad_1,ptkn);

        while(cad_1[j]!='\0')
        {
            cont++;
            j++;
        }

        num=strlen(cad_1);

        if (num>10)
        {
            pcont++;
        }

        cont=0;
        j=0;


        ptkn=strtok(NULL," ");
    }

    return pcont;
}

void cuentacvocal(char txt[], char voc[],int vector[])
{
    int i=0, j, max=0,pmax=0;
    char voca;

    while(txt[i]!='.')
    {

        if(txt[i]=='a')
        {(vector[0])++;}

        if(txt[i]=='e')
        {(vector[1])++;}

        if(txt[i]=='i')
        {(vector[2])++;}

        if(txt[i]=='o')
        {(vector[3])++;}

        if(txt[i]=='u')
        {(vector[4])++;}

        i++;
    }


    return;

}

void letrayespacio(char txt[], int *letras, int *espacios)
{
    int i=0,c1=0,c2=0;

    while(txt[i]!='\0')
    {
        if((isalpha(txt[i]))!=0)
        {c1++;}

        if(txt[i]==' ')
        {c2++;}

        i++;
    }

    printf("letras %d\n",c1);
    printf("Espacios %d\n",c2);

    *letras=c1;
    *espacios=c2;


    return;

}

void printarenterov(char voc[],int v[])
{
    int i;

    for(i=0;i<5;i++)
    {
        printf("vocal %c = %d\n",voc[i],v[i]);
    }

}

void printxt(char txt[])
{
    printf("La cadena es:\n%s\n",txt);

    return;
}
