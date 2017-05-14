#include <stdio.h>

 	 int a,b,c,d,e; //O arithmos poy diavazei

	const int i=2;//ziteitai apo tin ekfwnisi

  main()
{
    puts("--Metatropi dekadikou arithmou se duadiko--\n");

	do
	{
	//	e=0;
/* 1.Eisagwgi dekadikou*/
		printf("\nEisagetai dekadiko arithmo:");
		scanf("%d",&a);//eisagwgi arithmou

/*2. Elegxos o arithmos na einai thetikos*/
        (a<0)?(puts("\nMi egkuri epilogi arithmou"),(e=1)) :(puts("H diadiki ekfrasi tou arithmou einai:"),(e=0));



/* 3.Diadikasia loop gia upologismo duadikou*/

		while( a>=0 )
		{
			c=a/i;
			b=a%i;
/*An to upoloipo b einai 1 ektupwnei 1 an einai 0 ektupwnei 0*/
			b==1? putchar('1'): putchar('0');
			d=c;
/*An o trexwn aritmos einai 0 termatizetai an oxi sunexizei*/
            (c==0)?a=-2:a=d;

		}



} while(e!=0);









}

