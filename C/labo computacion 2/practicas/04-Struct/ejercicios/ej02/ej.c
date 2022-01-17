#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

struct calificacion{

char nombre[11];
float nota;
float ajustada;

};

void carga(struct calificacion v[],int d,int *cont);
void emite(struct calificacion v[],int d);
void ajustanota(struct calificacion v[],int d,int cont);



void carga(struct calificacion v[],int d,int *cont){

    int i;

    printf("********************************************\n");
    printf("              Ingrese Datos                 \n");
    printf("********************************************\n");
    for(i=0;i<d;i++){

        printf("                       %d                   \n",i+1);
        printf("********************************************\n");
        printf("ingrese nombre: ");
        fflush(stdin);
        gets(v[i].nombre);

        printf("Ingrese nota: ");
        fflush(stdin);
        scanf("%f",&v[i].nota);

        printf("+++++++++++++++++++++++++++++++++++++++++++\n");

        if((v[i].nota)>=9)
        {
            (*cont)=(*cont)+1;
        }

        printf("cont = %d\n",*cont);

    }

    return;
}

void emite(struct calificacion v[],int d){

    int i;

    printf("********************************************\n");
    printf("                Nueva notas                 \n");
    printf("********************************************\n");

    for(i=0;i<d;i++)
    {
        printf("%d | Nombre : %s | Nota : %.2f | Ajustada : %.2f \n",i+1,v[i].nombre,v[i].nota,v[i].ajustada);
    }

    return;
}

void ajustanota(struct calificacion v[],int d,int cont){

    int i;

    if(cont<5)
    {

        for(i=0;i<d;i++)
        {

            if(v[i].nota<=9)
            {
                v[i].ajustada=(v[i].nota)+1;
            }
            else
            {
                v[i].ajustada=10;
            }

        }

    }
    else
    {

        for(i=0;i<d;i++)
        {
            if(v[i].nota<=9.5)
            {
                v[i].ajustada=(v[i].nota)+0.5;
            }
            else
            {
                v[i].ajustada=10;
            }

        }

    }


    return;
}

int main() {

    const int dim=10;
    struct calificacion alumnos[dim];
    int contador=0;

    printf("##########################################\n");
    printf("###     Programa Notas de Cursada      ###\n");
    printf("##########################################\n");

    carga(alumnos,dim,&contador);
    ajustanota(alumnos,dim,contador);
    emite(alumnos,dim);





    system ("pause");

    return 0;

}
