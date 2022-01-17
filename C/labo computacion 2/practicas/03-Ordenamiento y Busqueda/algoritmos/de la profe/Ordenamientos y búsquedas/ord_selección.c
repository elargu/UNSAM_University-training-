/* ordenaci�n de un vector de n�meros enteros */
/* m�todo: seleccion */
/* ejemplo de paso de vectores como par�metros */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int posicion_maximo (int v[], int d){
/* devuelve la posici�n del elemento mayor del vector x */
/* entrada: vector x, de tama�o efectivo n */
/* salida : posici�n entre 1 y n-1 */
int mprov, pprov, i;
mprov = v[0];
pprov = 0;
for (i = 1; i < d; i++)
    if (v[i]> mprov){
	  mprov = v[i];
      pprov = i;
    }
return pprov;
}
void intercambia (int * px, int * py) {
int n;
n = *py;
*py = *px;
*px = n;
}

void coloca_el_ultimo (int v[], int d){
/* intercambia los elementos m�ximo de x y �ltimo de x
 colocando en �ltimo lugar el m�ximo elemento */
/* n es el tama�o efectivo de x */
int p;
p = posicion_maximo (v, d);
if (v[p] !=  v[d-1])
intercambia (&v[d-1], &v[p]);
}

void cargaelem(int v[], int d){
int i;
srand(time(NULL));
for (i = 0; i < d; i++) v[i] = 1 + rand() % 50;
}

void emiteelem(int v[], int d){
int i;
for (i = 0; i < d; i++)
printf ("%5d", v[i]);
printf("\n");
}

void ordenaelem(int v[], int d){
int cont;
/* Ordenamiento*/
for (cont = d; cont > 1; cont--){
/* tama�o desde el inicial hasta 2 */
coloca_el_ultimo (v, cont);
}
/* Fin ordenamiento*/
}

int main(){
const int dim=10;
int vec[dim];
cargaelem(vec,dim);
printf ("\nElementos ingresados: \n");
emiteelem(vec,dim);
ordenaelem(vec,dim);
printf ("\nResultado despu�s de ordenar: \n");
emiteelem(vec,dim);
getchar();
return 0;
}
