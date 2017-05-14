#include <stdio.h>
/* Pragmatopoiountai aples mathimatikes prakseis ara tin akribeia 2 dekadikwn tin thewrw arketi, to platos epilegw na min me apasxolei*/

float a,b;
char c,e;


main()
{
    printf("Eisagete arithmo praksi arithmo:\n\n");
    scanf("%f %c %f", &a, &c, &b);


// 1. Praksi prosthesis

    if (c=='+')
    {
 		printf("\n\napotelesma = %.2f\n\n",(a+b));

    }
// 2. Praksi afairesis
    else if (c=='-')
    {
 		printf("\n\napotelesma = %.2f\n\n",(a-b));

    }
//3. Praksi pollaplasiasmou
   else if (c=='*')
    {
 		printf("\n\napotelesma = %.2f\n\n",(a*b));
 	}

// 4. Praksi diairesis
	//4.1 Diairesi me 0

 	else if (c=='/')
 	{
	 	if(b==0)
	 	{
 			printf("\n\n Prosoxi !\nAdunati i diairesi me 0!!\n\n");
 		}
    	 else
    	 {

            printf("\n\napotelesma = %.2f\n\n",(a/b));
          }
    }
    //5. Se periptwsi lathous eisagwgis stoixeiwn
    else
    {
        printf("\n\nEisagate mi epitrepomeni praksi!\n\n");

    }




}
