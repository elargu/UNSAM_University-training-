#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

struct articulo{

int codigo;
int unidades;

};

void carga(struct articulo v[], int d,int *sum);
void emite(struct articulo v[], int d,int sm);


void carga(struct articulo v[], int d,int *sum){

    int i;

    printf("**************************************\n");

    for(i=0;i<d;i++){

        printf("               %d               \n",i+1);
        printf("================================\n");
        printf("Ingrese codigo del articulo : ");
        scanf("%d",&v[i].codigo);

        printf("\n");

        printf("Ingrese Stock del articulo : ");
        scanf("%d",&v[i].unidades);
        printf("================================\n");

        (*sum)=(*sum)+v[i].unidades;
    }

return;
}

void emite(struct articulo v[], int d,int sm){

    int i;

     printf("**************************************\n");

    for(i=0;i<d;i++){

        printf("%d| Codigo de art: %d || Stock : %d\n",i+1,v[i].codigo,v[i].unidades);


}

      printf("**************************************\n");

      printf("El total de articulos es: %d\n",sm);

return;
}

int main() {

    const int dim = 10;
    struct articulo lista[dim];
    int suma=0;

    printf("#################################\n");
    printf("#####     CONTROL STOCK     #####\n");
    printf("#################################\n");

    carga(lista,dim,&suma);
    emite(lista,dim,suma);

    printf("#################################\n");
    printf("#####      FIN PROGRAM      #####\n");
    printf("#################################\n");

    system ("pause");
    return 0;

}
