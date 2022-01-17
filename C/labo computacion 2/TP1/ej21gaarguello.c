#include <stdio.h>

//declaro la funcion, ingreso un puntero como dato para que luego me devuelva la ganancia
void venta(int id,float pventa,float pcosto,int cvendida,float *ganancia);

int main()
{
    //declaro variables del main
    int id_prod,c_vendida,contprod=0;
	float p_venta,p_costo,totalg=0,gana;

	do
	{
		do
		{
		    //ingreso id
			printf("ingrese id de producto -se sale con 0- : ");
			scanf("%d",&id_prod);
			printf("\n");

            //para validar el dato, si el id esta fuera de rango lanza un cartel y no sale de este while
			if((id_prod<0)||(id_prod>1000))
			{
				printf("id no valido, el rango debe ser mayor a 0 y menor a 1000");
				printf("\n\n");
			}

		}
		while((id_prod<0)||(id_prod>1000));

		//si id es cero salteo el ingreso del resto de datos y su respectivo proceso
		if(id_prod>0)
		{
            //sigo ingresando datos
			printf("ingrese precio de venta: $ ");
			scanf("%f",&p_venta);

			printf("ingrese precio de costo: $ ");
			scanf("%f",&p_costo);

			printf("ingrese cantidad vendida: ");
			scanf("%d",&c_vendida);

            //llamo a la funcion venta, le envio id, el precio de venta, costo de venta y cantidad vendida. Luego asigno una variable llamada "gana" con la cual el puntero "ganancia" (de la funcion) va a direccionarse para que me traiga el resultado.
			venta(id_prod,p_venta,p_costo,c_vendida,&gana);

			//acumulo lo que me trajo el puntero y lo voy sumando en un total
			totalg+=gana;
			//voy contando la cantidad de productos ingresados
			contprod++;

		}

	}
	while(id_prod!=0);

    //imprimo lo que se pide en el punto B del ejercicio, el total acumulado de la ganancias y la cantidad de productos ingresados
    printf("\n\n********************************************\n");
	printf("La cantidad de productos procesados: %d",contprod);
	printf("\nEl total de la ganancia es : $ %.2f",totalg);
	printf("\n********************************************\n");



    system ("pause");

    return 0;

}

//el puntero "ganancia" esta apuntando a la variable "gana", asi que no hay que inicializarlo (poner en null)
void venta(int id,float pventa,float pcosto,int cvendida,float *ganancia)
{
    //declaro como float una variable auxiliar que llamare "resultado"
	float resultado;

	//realizo la operacion
	resultado=(pventa-pcosto)*cvendida;
	//asigno el resultado al puntero para que se lo lleve a la variable "gana" de la funcion main
	*ganancia=resultado;

	//imprimo lo que se pide en el punto A del ejercicio
    printf("\n********************************************");
	printf("\nla ganancia del producto %d = $ %.2f",id,resultado);
	printf("\n********************************************");
	printf("\n\n");

	return;
}

