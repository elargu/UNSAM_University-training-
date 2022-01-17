#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define n_notas 3

struct alumnos{

char nombre[11];
char curso;
float nota[n_notas];
float promedio;

};

void carga(struct alumnos v[],int d,float *promcurso,char ncur);
void emite(struct alumnos v[],int d,float prom, char curs);



void carga(struct alumnos v[],int d,float *promcurso,char ncur){

    int i,j;
    float promalum;

    printf("========================================\n");
    printf("           Curso %c\n",ncur);
    printf("========================================\n\n");

    for(i=0;i<d;i++)
    {
        promalum=0;

        printf("****************************************\nAlumno: %d\n****************************************\n",i+1);
        printf("Ingrese nombre : ");
        fflush(stdin);
        gets(v[i].nombre);

        v[i].curso=ncur;

        printf("-------------------------------------------\n");
        printf("Ingerese las notas del alumno %s\n\n",v[i].nombre);
        printf("-------------------------------------------\n");

        for(j=0;j<n_notas;j++)
        {
                printf("Ingrese nota %d : ",j+1);
                fflush(stdin);
                scanf("%f",&v[i].nota[j]);
                promalum+=v[i].nota[j];
        }

        (v[i].promedio)=promalum/n_notas;
        printf("Promedio = %.2f\n\n",v[i].promedio);
        *promcurso=*promcurso+v[i].promedio;


    }
    fflush(stdin);



    return;
}

void emite(struct alumnos v[],int d,float prom, char curs){

    int i;

    printf("************************************************\n");
    printf("             CURSO %c\n",curs);
    printf("************************************************\n\n");
    for(i=0;i<d;i++)
    {
        printf("______________________________________________\n");
        printf("%d | Nombre : %s  | Promedio %.2f\n",i+1,v[i].nombre,v[i].promedio);
    }

    printf("\n................................................\n");
    printf("El promedio del curso %c es = %.2f\n",curs,prom);
    printf("................................................\n\n");
    return;
}


int main() {

    const int dim=3;
    struct alumnos claseA[dim];
    struct alumnos claseB[dim];
    float promcursoA=0,promcursoB=0;
    char letraa='A',letrab='B';


    carga(claseA,dim,&promcursoA,letraa);
    carga(claseB,dim,&promcursoB,letrab);

    promcursoA=promcursoA/dim;
    promcursoB=promcursoB/dim;

    emite(claseA,dim,promcursoA,letraa);
    emite(claseB,dim,promcursoB,letrab);

    system ("pause");

    return 0;

}
