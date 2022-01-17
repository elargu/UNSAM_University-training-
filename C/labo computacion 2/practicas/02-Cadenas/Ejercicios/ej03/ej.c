////FUNCIONAN TODO EL CODIGO Y LAS FUNCIONES!!! : Desofuscar los ejercicios que se quieren ejecutar , a,b,c,d,e,f


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int carga_txtlxl(char txt[], int d);
void printxt(char txt[]);
void cargatxt(char txt[]);
char cargaletra();
int esetroque(char txt[]);
int cuentavocal(char txt[], char voc[]);
char cuentavocalmas(char txt[], char voc[]);
int cuentaletrauna(char txt[], char let);
int esetroquemayor(char txt[]);
int distancialxl(char txt[], char let1, char let2);

int main()
{
    const int dim=10;
    //char texto[dim];
    int contador,i=0;
    char texto[16]="Mundo Simpsons."; //debuger
    char vocal[6]="aeiou";
    char letra,letra2;

    //a)
    //contador=carga_txtlxl(texto,dim);
    //printxt(texto);
    //printf("\nA- El contador de letras dio = %d\n",contador);


    //b)
    //contador=0;
    //cargatxt(texto);
    //contador=esetroque(texto);
    //printf("\nB- El contador dio = %d palabras\n",contador);

    //c)
    //contador=0;
    //cargatxt(texto);
    //letra=cuentavocalmas(texto,vocal);
    //printxt(texto);
    //printf("\nC- La vocal que mas aparece es = %c\n",letra);

    //d)
    //contador=0;
    //cargatxt(texto);
    //letra=cargaletra();
    //contador=cuentaletrauna(texto,letra);
    //printxt(texto);
    //printf("\nD- El contador dio = %d\n",contador);

    //e)
    //contador=0;
    cargatxt(texto);
    contador=esetroquemayor(texto);
    printf("\nB- La cantidad de letras que tiene la palabra mas larga es= %d\n",contador);

    //f)
    //contador=0;
    //cargatxt(texto);
    //printf("\nIngrese letra: ");
    //letra=cargaletra();
    //printf("\nIngrese letra de referencia para medir la distancia respecto a la anterior: ");
    //letra2=cargaletra();
    //contador=distancialxl(texto,letra,letra2);
    //printf("La distancia entre la primera letra y la segunda es de = %d letras\n",contador);




    fflush(stdin);  //descargo el bufer del teclado al salir del programa
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

char cargaletra()
{
    char unaletra;

    printf("Ingrese una letra = ");
    fflush(stdin);
    scanf("%c",&unaletra);

    return unaletra;
}

int carga_txtlxl(char txt[], int d)
{
    int i=0,cont=0;
    char *p;
    p=txt;

    printf("Ingrese un texto letra por letra y termine con un punto '.', maximo 99 caracteres\n");
    while(txt[i-1]!='.')
    {
        printf("Ingrese una letra = ");
        fflush(stdin);
        scanf("%c",p+i);
        printf("\n");

        if (isalpha(txt[i])!=0)
        {cont++;}

        i++;
    }

    return cont;
}


int esetroque(char txt[])
{
    char *ptkn;
    int cont=0;

    ptkn=strtok(txt," ");

    while(ptkn!=NULL)
    {
        printf("%s\n",ptkn);
        cont++;
        ptkn=strtok(NULL," ");
    }

    return cont;
}

int esetroquemayor(char txt[])
{
    char cad_1[20];
    char *ptkn;
    int i=0,mayor=0,j=0,num,pmayor,cont=0,pcont;

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

        if (num>mayor)
        {
            mayor=num;
            pmayor=i;
            pcont=cont;
        }

        cont=0;
        j=0;

        i++;

        ptkn=strtok(NULL," ");
    }

    return pcont;
}

int cuentavocal(char txt[], char voc[])
{
    int i=0, j, conta=0;

    while(txt[i]!='\0')
    {
        for(j=0;j<5;j++)
        {
            if(txt[i]==voc[j])
            {conta++;}
        }
        i++;
    }

    return conta;

}


char cuentavocalmas(char txt[], char voc[])
{
    int i=0, j, max=0,pmax=0;
    char voca;

    int vector[5]={0,0,0,0,0};


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


    for(i=0;i<5;i++)
    {
        if((vector[i])>max)
        {
            max=vector[i];
            pmax=i;
        }

    }

    voca=voc[pmax];


    return voca;

}

int cuentaletrauna(char txt[], char let)
{
    int i=0,cont=0;


    while(txt[i]!='\0')
    {

        if(txt[i]==let)
        {
            cont++;
        }

        i++;
    }

    return cont;
}

int distancialxl(char txt[], char let1, char let2)
{
    int i=0,j=0,flag=0,flag2=0,conti;

    while((txt[i]!='\0')||(flag=0))
    {
        if(txt[i]==let1)
        {
            flag=1;

            while((txt[i]!='\0')||(flag2=0))
            {
                if(txt[i]!=let2)
                {j++;}
                else
                {flag2=1;}

                i++;
            }

        }
        i++;
    }

    if(flag2==0)
    {
        conti=j;
    }
    else
    {
        conti=0;
    }

    return conti;
}


void printxt(char txt[])
{
    printf("La cadena es:\n%s\n",txt);

    return;
}

