#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void funcion1(int *total_legajo,float *mayorpro,int *mayoranio,char *mayordivi);
void funcion2(char division,float nota,float*notaA,int*contA,float*notaB,int*contB);

int main() {

	int tlegajos, maxanio;
	float maxipromedio;
	char maxidivision;

	funcion1(&tlegajos,&maxipromedio,&maxanio,&maxidivision);

	printf("\n================================================\n");
	printf("\nCantidad de legajos: %d",tlegajos);
	printf("\nPromedio Maximo: %.2f",maxipromedio);
	printf("\nAnio de maximo: %d",maxanio);
	printf("\ndivision de maximo: %c",maxidivision);
	printf("\n================================================\n");

	printf("\n\n");

    system ("pause");

    return 0;

}


void funcion2(char division,float nota,float*notaA,int*contA,float*notaB,int*contB)
{
	if (division=='A')
	{
		*notaA=*notaA+nota;
		(*contA)++;
	}

	if (division=='B')
	{
		*notaB=*notaB+nota;
		(*contB)++;
	}

}


void funcion1(int *total_legajo,float *mayorpro,int *mayoranio,char *mayordivi)
{
	int nlegajo, i, contA, contB;
	float nota,notasA,notasB,promA,promB;
	char division;

	*mayorpro=(-1);

	for(i=0;i<5;i++)
	{
		notasA=0;
		notasB=0;
		contA=0;
		contB=0;
		promA=0;
		promB=0;

        printf("\n______________________________________________________");
        printf("\n                     Anio %d",i+1);
        printf("\n______________________________________________________");
		do
		{
			do
			{
				printf("\n*****Los legajos tienen que tener ser mayores a cero******");
				printf("\nIngrese numero legajo (salir con 0): ");
				fflush(stdin);
				scanf("%d",&nlegajo);
			}
			while(nlegajo<0);

			if(nlegajo!=0)
			{
				printf("\n___________________________________________________");
                printf("\n                  Legajo %d",i+1);
                printf("\n___________________________________________________");
				do
				{
                    printf("\n*****Solo se acepta el ingreso de las letras A o B mayusculas*****: ");
					printf("\ningrese division (A o B): ");
                    fflush(stdin);
					scanf("%c",&division);
					printf("division: \n%c",division);
				}
				while((division!='A')&&(division!='B'));

				printf("\n___________________________________________");

				do
                {
                    printf("\ningrese nota (1 a 10): ");
                    fflush(stdin);
                    scanf("%f",&nota);
                }
                while((nota<1)||(nota>10));


				funcion2(division,nota,&notasA,&contA,&notasB,&contB);
				printf("notaA= %f\n",notasA);
				printf("notaB= %f\n",notasB);
				printf("contA= %d\n",contA);
				printf("contB= %d\n",contB);
		    }

			if(nlegajo==0)
			{




				printf("\n***********************************************");
				printf("\nAnio %d",i+1);
				printf("\n***********************************************");

				if(contA>0)
                {
                    promA=notasA/(float)contA;
                    printf("\nDivision A = %.2f",promA);
                }
                if(contB>0)
                {
                    promB=notasB/(float)contB;
                    printf("\nDivision B = %.2f",promB);
                }

				printf("\n***********************************************\n");


				*total_legajo=*total_legajo+contA+contB;

				if(promA>promB)
				{
					if(promA>*mayorpro)
				    {
						*mayorpro=promA;
						*mayoranio=i+1;
						*mayordivi='A';
					}
			    }
				else
				{
					if(promB>*mayorpro)
				    {
						*mayorpro=promB;
						*mayoranio=i+1;
						*mayordivi='B';
					}
			    }


		    }


		}
		while(nlegajo!=0);


	}
}

