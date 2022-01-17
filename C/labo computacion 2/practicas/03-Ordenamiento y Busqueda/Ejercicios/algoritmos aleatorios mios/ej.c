#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
//incluir libreria time!!!
#include <time.h>  //ESTA LIBRERIA!!!!!!  <<<<<--------------
#define rangoIA 0   //defino un rango para el aleatorio-desde rangoA y hasta rangoB- (aca porque lo hago general, se puede pedir o colocar en main para pasar a funcion
#define rangoIB 100
#define rangoFA 0
#define rangoFB 1000


int funrandom_int_one();
void printar_un_entero(int num);
void funrandom_int_vec(int v[],int d);
void printar_vector_entero(int v[],int d);
float funrandom_float_one();
void printar_un_flotante(float num);
void funrandom_float_vec(float v[],float d);
void printar_vector_flotante(float v[],float d);



int main() {

    const int dim=10;

    int vec_int[dim];
    float vec_float[dim];

    int num_int;
    float num_float;

    //LLAMO A FUNCIONES ALEATORIO ENTEROS
    num_int=funrandom_int_one();   //Me entrega un solo numero aleatorio entero
    printar_un_entero(num_int);    //imprimo

    printf("\n");

    funrandom_int_vec(vec_int,dim);           //llena un vector con numeros aleatorios entero
    printar_vector_entero(vec_int,dim);       //imprimo

    printf("\n");



    //LLAMO A FUNCIONES ALEATORIO FLOTANTES
    num_float=funrandom_float_one();    //Me entrega un solo numero aleatorio flotante
    printar_un_flotante(num_float);     //imprimo

    printf("\n");

    funrandom_float_vec(vec_float,dim);              //llena un vector con numeros aleatorios flotante
    printar_vector_flotante(vec_float,dim);          //imprimo

    printf("\n");



    system ("pause");

    return 0;

}
//////////////////////////////////////////////////////////////////
/////////  Entrega Un solo Numero Entero Aleatorio   /////////////
//////////////////////////////////////////////////////////////////
int funrandom_int_one()
{
    int num;

    srand(time(NULL));
    num=rangoIA+(rand()%rangoIB);

    return num;
}


void printar_un_entero(int num)
{

    printf("El numero aleatorio es: %d\n",num);

    return;
}
//////////////////////////////////////////////////////////////////
///////  Entrega Vector con Numeros Enteros Aleatorios   ////////
/////////////////////////////////////////////////////////////////
void funrandom_int_vec(int v[],int d)
{
    int i,num;

    srand(time(NULL));

    for(i=0;i<d;i++)
    {
        v[i]=(rangoIA)+(rand()%rangoIB);
    }

    return;

}


void printar_vector_entero(int v[],int d)
{
    int i;

    printf("La secuencia de numeros aleatorios enteros es:\n");

    for(i=0;i<d;i++)
    {
        printf("%d\n",v[i]);
    }

    return;
}
//////////////////////////////////////////////////////////////////
////////  Entrega Un solo Numero flotante Aleatorio   ////////////
//////////////////////////////////////////////////////////////////
float funrandom_float_one()
{
    float num;

    srand(time(NULL));
    num=rangoFA+(rand()%rangoFB);
    num=(num/11);

    return num;
}


void printar_un_flotante(float num)
{

    printf("El numero aleatorio es: %.2f\n",num);

    return;
}
//////////////////////////////////////////////////////////////////
/////// Entrega Vector con Numeros Flotantes Aleatorios   ///////
/////////////////////////////////////////////////////////////////
void funrandom_float_vec(float v[],float d)
{
    int i;
    float num;

    srand(time(NULL));

    for(i=0;i<d;i++)
    {
        num=rangoFA+(rand()%rangoFB);
        v[i]=(num/11);
    }

    return;

}


void printar_vector_flotante(float v[],float d)
{
    int i;

    printf("La secuencia de numeros aleatorios flotantes es:\n");

    for(i=0;i<d;i++)
    {
        printf("%.2f\n",v[i]);
    }

    return;
}

