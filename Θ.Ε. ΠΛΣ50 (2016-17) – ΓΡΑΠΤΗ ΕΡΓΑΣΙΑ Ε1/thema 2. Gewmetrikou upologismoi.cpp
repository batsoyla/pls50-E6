#include <stdio.h>
#include <math.h>
/*OI sunartiseis pou xrisimopoiithikan*/
float perimeter_square(float length1);
float perimeter_parallelogram(float length1,float length2);
float perimeter_right_triangle(float length1,float length2);
float perimeter_cycle(float length1);

main()
{
/* 1. orismos metavlitwn*/

	int choice;
	float a,b,perimeter;


/* 2.Orismos epilogwn.To programma epanalambanetai mexri o xristis na epileksei eksodo apo to programma =0*/
	do{

        printf("\n\nEisagetai poianou sximatos tin perimetro \nthelete na upologisete:\n");
		printf("\n-Kanenos:             0 ");
		printf("\n-Tetragwnou:          1 ");
		printf("\n-Parallilogrammou:    2 ");
		printf("\n-Orthogwniou trigwnou:3 ");
		printf("\n-Kyklou:              4");
		printf("\n\n <Epilogi>:");
		scanf("%d", &choice);
/*3.Eksodos apo to programma:Typwnetai minuma me tin epilogi tou xristi kai meta termatizetai*/
		if(choice==0)
		{
		printf("\nEpileksate eksodo apo to programma\n\n");
		}

/* 4. Ypologismos perimetrou tetragwnou*/
		else  if(choice==1)
		{
		printf("\n\n Ypologismos perimetrou tetragwnou (cm):");
			do
			{
                a=0;//arxikopoiisi a
                printf("\n -Dwste mikos pleuras tetragwnou(cm): ");
				scanf("%f", &a);

				if(a>0 )
				{
                    perimeter=perimeter_square(a);
                    printf("\n   H perimetros tou tetragwnou einai=%.3fcm \n\n",perimeter);
                    a=-5;//gia na termatizei to loop
				}

	/* Se periptwsi pou o xrhsths den valei egkuri timi mikous to programma den termatizei alla tou zitaei na ksanavalei mikos */

				else

				{
                    printf("\n   Eisagwgi mi egkurou mikous pleuras\n");
                    a=1;

				}


		  }while(a>0);



		}
	/* 5. Ypologismos perimetrou parallilogrammou*/
		else if(choice==2)

		{
            a=0;//arxikopoiisi a
            b=0;//arxikopoiisi b
			printf("\n\n Ypologismos perimetrou Parallilogrammou(cm)");
			do
			{

				printf("\n -Dwste mikos pleuras a(cm): ");
				scanf("%f", &a);
				printf("\n -Dwste platos pleuras b(cm): ");
				scanf("%f", &b);
/*Den eksetazw an to mikos einai megalutero apo platos giati den odhgei se lathos apotelesma*/

				if(a>0 && b>0)
				{
                    perimeter=perimeter_parallelogram(a,b);
                    printf("\n   H perimetros tou parallilogrammou einai=%.3fcm \n\n",perimeter);
                    a=-1;//gia na termatizei to loop
                    b=-1;//gia na termatizei to loop
				}
	/* Se periptwsi pou o xrhsths den valei egkuri timi mikous to programma den termatizei alla tou zitaei na ksanavalei mikos */
				else
				{
                    printf("\n   Eisagwgi mikous pleurwn mi egkuro\n");
                    a=1;
                    b=1;
				}

			}while(a>0 && b>0);


        }
	/*6. Ypologismos perimetroy orthogwniou trigwnou*/

		else if(choice==3)
		{
            a=0;//arxikopoiisi a
            b=0;//arxikopoiisi b
			printf("\n\n Ypologismos perimetrou orthogwniou trigwnou");

			do
			{

				printf("\n -Dwste mikos pleuras a(cm): ");
				scanf("%f", &a);
				printf("\n -Dwste mikos pleuras b(cm): ");
				scanf("%f", &b);

				if(a>0 && b>0)
				{

                    perimeter=perimeter_right_triangle(a,b);
                    printf("\n   H perimetros tou trigwnou einai=%.3fcm \n\n",perimeter);
                    a=b=-1;//gia na termatizei to loop
				}
	/* Se periptwsi pou o xrhsths den valei egkuri timi mikous to programma den termatizei alla tou zitaei na ksanavalei mikos */

				else
				{
                    printf("\n   Eisagwgi mi egkurou mikous pleuras\n");
                    a=1;
                    b=1;
				}
            }while(a>0 && b>0);
        }
	/* 7. upologismos perimetrou kuklou*/
		else if(choice==4.0)
		{
            a=0;//arxikopoiisi a
			printf("\n\n Ypologismos perimetrou kuklou");

			do
			{

				printf("\n -Dwste mikos aktinas kuklou(cm): ");
				scanf("%f", &a);

				if(a>0)
				{
                    perimeter=perimeter_cycle(a);
                    printf("\n   H perimetros tou kuklou einai=%.3fcm \n\n",perimeter);
                    a=-1;//gia na termatizei to loop
				}
	/* Se periptwsi pou o xrhsths den valei egkuri timi mikous to programma den termatizei alla tou zitaei na ksanavalei mikos */
				else
				{
                    printf("\n   Eisagwgi mi egkurou mikous pleuras\n");
                    a=1;

				}
			}while(a>0);

        }
    /*6.Gia alli eisagwgi arithmou*/
		     else
             {
                 printf("\nlathos eisagwgi stoixeiwn\n\n\n");
             }

			} while(choice!=0);





}
float perimeter_square(float length1)
{
    float res;
    res=(4*length1);
    return res;

}

float perimeter_parallelogram(float length1,float length2)
{
    float res;
    res=((2*length1)+(2*length2));
    return res;

}

float perimeter_right_triangle(float length1,float length2)
{
     float res;
    float hypotenuse;
    hypotenuse=sqrt((length1*length1)+(length2*length2));//upologismos tetragwnikis rizas

    res=(length1+length2+hypotenuse);
    return res;

}

float perimeter_cycle(float length1)
{
    const float pi=3.1415;//to p den theloume na allazei pote
     float res;
    res=(2*pi*length1);
    return res;


}
