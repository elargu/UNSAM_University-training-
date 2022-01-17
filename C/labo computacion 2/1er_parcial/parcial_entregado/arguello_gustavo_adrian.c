#include <stdio.h>
#include <stdlib.h>

//Declaro las variables auxiliares
void auxiliar(char medio,float importe,float *sumaR,float *sumaT,float *sumaG,int *conR,int *conT,int *conG);
void funcion1(int *total_prestadores,float *Maxgasto,char *Maxmedio,float *importe_total);

int main() {

	int totalPres;
	float gastoMax,importe_total;
	char medioMax;
	printf("\n===============================================================");
    printf("\n              Control de Medios EL PIRULO.COM");
	printf("\n===============================================================");
	funcion1(&totalPres,&gastoMax,&medioMax,&importe_total);

	printf("\n===============================================================");
	printf("\nCantidad Total de Prestadores Procesados:                 %d",totalPres);
	printf("\nImporte Total que Gastaron las Empresas en Publicidad:    %.2f",importe_total);
	printf("\n----------------------------------------------------------------");
	printf("\nEn que medio se gasto mas:      %c",medioMax);
	printf("\nCuanto fue ese gasto:           %.2f",gastoMax);
	printf("\n------------------------------------------------------------");

	printf("\n\n");


    system ("pause");

    return 0;

}

//en esta variable auxiliar chekeo con un if si el medio ingresado es radio, tv o grafico, se aceptan mayusculas y minusculas
void auxiliar(char medio,float importe,float *sumaR,float *sumaT,float *sumaG,int *conR,int *conT,int *conG)
{
	//para el medio correspondiente se acumula en suma y se incrementa el contador. Notse que estoy usando punteros que apuntan a variables de la funcion1
	if((medio=='R')||(medio=='r'))
	{
		*sumaR+=importe;
		(*conR)++;
	}

	if((medio=='T')||(medio=='t'))
	{
		*sumaT+=importe;
		(*conT)++;
	}

	if((medio=='G')||(medio=='g'))
	{
		*sumaG+=importe;
		(*conG)++;
	}


	return;

}

//en esta funcion ingreso los datos que el usuario quiere procesar.
void funcion1(int *total_prestadores,float *Maxgasto,char *Maxmedio,float *importe_total)
{
	int i,N,nprestador,contaR,contaT,contaG;
	float importe,sumaR,sumaT,sumaG;
	char medio;
	
	//inicializo Maxastos para poder realizar la comparacion mas adelante
	*Maxgasto=0;

	printf("\nIngrese Cantidad de Empresas a Procesar: ");
	fflush(stdin);
	scanf("%d",&N);

	//utilizo un for para que corra todas las empresas que el usuario ingreso en la anterior pregunta
	for(i=0;i<N;i++)
	{
		//inicializo en cero los contadores y sumadores, ya que para cada ciclo los tengo que tener vacios
		sumaR=0;
		sumaT=0;
		sumaG=0;
		contaR=0;
		contaT=0;
		contaG=0;

		printf("\n========================");
		printf("\nNumero de empresa %d",i+1);
		printf("\n========================");
		printf("\n");

		//utilizo un do while para que el usuario ingrese todos los prestadores que necesite, sale cuando pone 0
		do
		{
			printf("\n________________________________________________________");
			printf("\nIngrese numero de prestador (se sale de empresa con 0): ");
			fflush(stdin);
			scanf("%d",&nprestador);
			//en el caso de que el usuario quiera salir del ingreso de datos salteo este paso ya que no corresponde
			if(nprestador!=0)
            {
                printf("\nIngrese Medio(R=Radio,T=Television,G=Grafico): ");
                fflush(stdin);
                scanf("%c",&medio);

                printf("\nIngrese Importe : $ ");
                fflush(stdin);
                scanf("%f",&importe);
				
				//llamo a la funcion auxiliar asi me gestiona los datos
                auxiliar(medio,importe,&sumaR,&sumaT,&sumaG,&contaR,&contaT,&contaG);

            }

		}
		while(nprestador!=0);

		//imprimo los resultados parciales
		printf("\n**************************************************");
		printf("\n               Empresa Nr. %d",i+1);
		printf("\n**************************************************");
		printf("\n");
		printf("\nR(radio)      : %.2f         Prestadores : %d",sumaR,contaR);
		printf("\nT(television) : %.2f         Prestadores : %d",sumaT,contaT);
		printf("\nG(grafico)    : %.2f         Prestadores : %d",sumaG,contaG);
		printf("\n");

		//guardo en los punteros correspondientes los totales que quiero mostrar en main, se iran sumando a medida que ingresen el resto de empresas
		*total_prestadores+=contaR+contaT+contaG;
		*importe_total+=sumaR+sumaT+sumaG;

		//realizo esta comparacion para buscar el Maximo gasto y que medio fue, un doble if para cada medio
		if((sumaR>sumaT)&&(sumaR>sumaG))
		{
			if(sumaR>*Maxgasto)
			{
				*Maxmedio='R';
				*Maxgasto=sumaR;
			}
		}

		if((sumaT>sumaR)&&(sumaT>sumaG))
		{
			if (sumaT>*Maxgasto)
			{
				*Maxmedio='T';
				*Maxgasto=sumaT;
			}
		}

		if((sumaG>sumaT)&&(sumaG>sumaR))
		{
			if (sumaG>*Maxgasto)
			{
				*Maxmedio='G';
				*Maxgasto=sumaG;
			}
		}

	}






	return;
}
