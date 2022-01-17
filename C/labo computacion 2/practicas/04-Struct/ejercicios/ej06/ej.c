#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

struct alumnos{

char nombre[11];
float notas[5];
float media;
char evaluado;

};

void carga(struct alumnos v[],int d);
void calcula(struct alumnos v[],int d,int *cont_ap,int *cont_och);
void emite(struct alumnos v[],int d,int apro, int ocho);

void carga(struct alumnos v[],int d){

    int i,j;

    for(i=0;i<d;i++)
    {
        printf("\n**********  %d  ************\n",i+1);
        printf("Ingrese nombre del alumno: ");
        fflush(stdin);
        gets(v[i].nombre);

        for(j=0;j<5;j++)
        {
            printf("\nIngrese nota Materia %d : ",j+1);
            fflush(stdin);
            scanf("%f",&v[i].notas[j]);
        }

    }

    return;
}

void calcula(struct alumnos v[],int d,int *cont_ap,int *cont_och){

    int i,j;
    float prom;

    for(i=0;i<d;i++)
    {
        prom=0;

        for(j=0;j<5;j++)
        {
            prom = prom + v[i].notas[j];
        }

        v[i].media=prom/5;

        if((v[i].notas[4]>=6)&&(v[i].media>=6))
        {
            v[i].evaluado='A';
            *cont_ap=*cont_ap+1;
        }
        else
        {
            v[i].evaluado='D';
        }

        if(v[i].media>=8)
        {
            *cont_och=*cont_och+1;
        }

    }

    return;
}

void emite(struct alumnos v[],int d,int apro, int ocho){

    int i;

    printf("Promedio Alumnos: \n");
    printf("NOMBRE  ||  PROMEDIO  ||  ESTADO   \n");
    for(i=0;i<d;i++)
    {
        printf("%d) %s  ||  %.2f   ||   %c\n",i+1,v[i].nombre,v[i].media,v[i].evaluado);
    }

    printf("____________________________________________\n");
    printf("Aprobados = %d  ||  Promedio mayor a 8 = %d\n",apro,ocho);

    return;
}

int main() {

    const int dim=10;
    struct alumnos calificaciones[dim];
    int conta_apro=0,conta_ocho=0;

    carga(calificaciones,dim);
    calcula(calificaciones,dim,&conta_apro,&conta_ocho);
    emite(calificaciones,dim,conta_apro,conta_ocho);

    system ("pause");

    return 0;

}
