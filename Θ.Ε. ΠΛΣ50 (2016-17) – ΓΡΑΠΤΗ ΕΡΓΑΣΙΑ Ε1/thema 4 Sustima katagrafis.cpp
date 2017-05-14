#include <stdio.h>
#define X 53





 main()
{
int thesi_lewforeiou[X];
int j,i,a,y;

//int thesi_lewforeiou[X] = {1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
//Boithitikos pinakas poy xrisimopoiithike gia dokimes

/*1.Anoigma arxeiwn gia apothikeusi kai gia anagnwsi apo arxeio bus.txt kai ektupwsi stin othoni */

FILE *pFile;


pFile = fopen("bus.txt","r");//read to arxeio mas

if (pFile !=NULL )
{
	char arithmos_pinakidas[8];
	int arithmos_thesewn;
	fscanf(pFile,"%s %d",arithmos_pinakidas, &arithmos_thesewn);

	printf ("O arithmos pinakidas einai:%s ",arithmos_pinakidas);
	printf ("\nO arithmos thesewn sto lewforeio  einai:%d \n",arithmos_thesewn);


	i=1;
	do
	{

/*2. 1os elegxos theseis>53 */

        if (arithmos_thesewn>53)
        {
            printf("O arithmos thesewn uperbainei ta epitrepta oria\n");
            return 0;
        }
/*3. Elegxos an oi theseis sumbadizoun me tin katanomi 4N+5, e.g 45=4*10+5*/
		else
		{
		    int b;
            y=arithmos_thesewn-5;
            b=y%4;


			if(b==0)
			{
/*Arxikopoiisi pinaka gia arithmo thesewn pou dothikan apo to arxeio*/
			 for(i=0; i<arithmos_thesewn; i++)
                 {
                     thesi_lewforeiou[i]=0;
                }
				printf ("\n\n\n Emfanisi tou sunolikou plithous kenwn thesewn kai tou arithmou tous :1");
				printf("\n Kratisi thesis me sugkekrimeno arithmo :2");
				printf("\n Kratisi prwtis kenis thesis se parathuro :3");
				printf("\n Akurwsi kratisis thesis :4");
				printf("\n Anazitisi kratimenis thesis me sugkekrimeno arithmo :5");
				printf("\n Emfanisi listas kratimenwn thesewn kata arithmo thesis :6");
				printf("\n Emfanisi pinakidas kukloforias kai diagrammatos lewforeiou :7");
				printf("\n Apothikeusi pinakidas kukloforias kai diagrammatos lewforeiou :8");
				printf("\n Termatismos programmatos :0");
				printf("\n Epilekste poia energeia epithumeite:");
				scanf("%d", &i);
			}
				else

	{

				printf("\n O aritmos thesewn den sumbadizei me tin katanomi thesewn ");

				return 0;
	}
			switch (i)
			{
/*4. Termatismos programmatos*/
                case 0://To programma tha termatize outws i allws giati i do ..while einai gia !=0
				{
                    break;
                }
/*5.Emfanisi kenwn thesewn kai arithmwn tous*/
				case 1:

					{
					y=0;
                    printf("\noi theseis:");
					for (i=0; i<arithmos_thesewn; i++)
						{
							if(thesi_lewforeiou[i]==0)
							{
							 	y+=1; //krataei to plithos twn kenwn thesewn
							 	printf("%d,",y);
						    }
						}
							printf("einai kenes\n");

							if(y==0)//Se periptwsi pou oles oi theseis einai kateilimenes

							{
								printf("\nOles oi theseis einai kateilimenes");
							}
							else
							{

						   	 printf("\nO sunolikos arithmos kenwn thesewn einai %d ",y);
							}
					break;
					}
/*6.Kratisi thesis*/
				case 2://H praksi den einai epanalambanomeni

					{
						y=0;
						printf("\nEpilekste thesi kratisis: ");
						scanf("\n %d", &y);
						y-=1;//an thelw na kratithei i 6 ston pinaka einai sti thesi6-1=5

	/* Epeidi allilepidra me ton xristi to programma prosexoume gia tis times pou eisagontai na einai >0 kai mesa sta plaisia*/
	/*Epeleksa ton elegxo an i thesi einai eleutheri na ton diaforopoiisw apo tin eisagwgi lathos stoixeiwn giati thewrw ta
 duo lathi diaforetikis fusis ara prepei na dinoun kai alla minumata lathous*/
						if(y<arithmos_thesewn && y>0)
						{
							if (thesi_lewforeiou[y]==0)
							{
								thesi_lewforeiou[y]=1;//an thelw na kratithei i 6 ston pinaka einai sti thesi6-1=5
								printf("\nH kratisi sas exei kataxwrithei");
							}

							else
							{
								printf("\nH thesi einai kateilimeni");
							}
				 	   }
						else
						{
							printf("\nMi egkuri epilogi thesis");
						}

					  break;
					}
/*7.Kratisis prwtis thesis se parathuro*/

					case 3:
/*Ksekinaw ton elegxo apo tin thesi 0 pou einai parathuro kai meta allazw to vima gia na ksanavrethw se parathuro*/
					{
					    y=0;//voithitikos metritis
						for(i=0; i <arithmos_thesewn;i++)
						{
							if (thesi_lewforeiou[i]==0)
							{
							    y+=1;
								thesi_lewforeiou[i]=1;
								printf("\n\nH thesi %d exei kratithei\n\n",i+1);
								return 0;

							}
							  if ((i%2==0) && (i!=arithmos_thesewn-4)) //an einai zigos allazei to vima gia na pame apo tin p.x 0 stin 3
							{
								i+=2;
							}
							 if(i==arithmos_thesewn-4)//allazei to vima pali an einai stin teleutaia seira
							{
								i+=3;
							}

                        }
                        /*H periptwsi pou den vrethike kamia keni se parathuro*/
                        if(y==0)
                            {
                                printf("\nKamia thesi diathesimi se parathuro\n");
                            }

						break;

					}
/*8.Akurwsi thesis */
					case 4:

					{
						y=0;
						printf("\nEpilekste thesi pros akurwsi: ");
						scanf("\n %d", &y);
						y-=1;//an thelw na akurwthei i 6 ston pinaka einai sti thesi6-1=5
/*Elegxos eisagwgis swstwn stoixeiwn*/
/*Idia logiki me 2o erwtima se sxesi me ta lathi*/
						if(y<arithmos_thesewn && y>0)
							{

							if (thesi_lewforeiou[y]==1)
								{
									thesi_lewforeiou[y]=0;
									printf("\nH akurwsi sas exei kataxwrithei");
								}
							else
								{
									printf("\nH thesi auti den einai kratimeni");
								}
				   			 }
						else

							printf("\nMi egkuri epilogi thesis\n\n");

					  break;}


/* 9.αναζήτηση για το αν είναι κρατημένη θέση με συγκεκριμένο αριθμό (πρέπει να προηγείται έλεγχος ότι ο αριθμός αυτός είναι εντός ορίων),*/

					case 5:
					{
						y=0;
						printf("\nEpilekste thesi kratisis: ");
						scanf("\n %d", &y);
						y-=1;//enw o xristis vazei y emeis ston pinaka elegxoume y-1

					if(y<arithmos_thesewn && y>0)///na kanw dokimastikes ektupwseis
					{
						if (thesi_lewforeiou[y]==1)
						{

							printf("\nH thesi %d  einai kratimeni",y+1);//gia na ektupwthei swsta
						}
						else
						{
							printf("\nH thesi %d den einai kratimeni",y+1);
						}
				    }
						else


						printf("\nMi egkuri epilogi thesis");

					  break;
					}


/*10.Emfanisi taksinomimenis lista kratimenwn thesewn*/
				  case 6:
				  	{

				  		printf("\nEmfanisi taksinomimenis listas kratimenwn thesewn:");
				 		printf("\n______________________________________________________________________\n");
                            y=0;
					  		for(i=0; i<arithmos_thesewn; i++)
					  		{
					  			if(thesi_lewforeiou[i]==1)
					  			{
					  			    y+=1;
					  				printf("\t\t%d)thesi %d\n",y,i+1);
								 }

							 }
							  break;
					}
/*11.Emfanisi pinakidas kukloforias kai diagrammatos lewforeiou*/
					case 7:
					{

						printf("\nH pinakida kukloforias einai \%s\n\n",arithmos_pinakidas  );//ektupwsi pinakidas kukloforias
				//		printf("arithmos_thesewn %d\n", arithmos_thesewn);

						j=0;
							for(i=0; i<arithmos_thesewn-5  ; i++)
							{
								if(thesi_lewforeiou[i]==1 && i==j+1)
								{
									printf("* ");

								}
									if(thesi_lewforeiou[i]==0 && i==j+1)
									{
										printf("_ ");

									}
									if(thesi_lewforeiou[i]==1 && i==j+3)
									{
										printf("*\n");
										j=i+1;

									}
									if(thesi_lewforeiou[i]==0 && i==j+3)
									{
										printf("_\n");
										j=i+1;

									}
									if(thesi_lewforeiou[i]==1 && ((i==j) || (i==j+2)))
									{
										printf("*");
									}
										if(thesi_lewforeiou[i]==0 && ((i==j) || (i==j+2)))
									{
										printf("_");
									}

							}
								for(i=arithmos_thesewn-5;i<arithmos_thesewn;i++)
								{
									if(thesi_lewforeiou[i]==1)
									{
										printf("*");
									}
										if(thesi_lewforeiou[i]==0)
									{
										printf("_");
									}

								}






	/* Enallaktikos tropos epilusis
	for(i=0 ; i<arithmos_thesewn-4 ; i++)
		{
			if(thesi_lewforeiou[i]==1  && float(i%2==0) && float(i%4==0))
			{

				printf("\n*");
        	}
			if(thesi_lewforeiou[i]==0  && float(i%2==0) && float(i%4==0))
	 		{

				printf("\n_");
			}
			if(thesi_lewforeiou[i]==1 && float(i%2==0) && float(i%4!=0))
			{

				printf(" *");
			}
			if(thesi_lewforeiou[i]==0  && float(i%2==0) && float(i%4!=0))
			{

				printf(" _");
			}
			if(thesi_lewforeiou[i]==1 && float(i%2!=0) )
			{

				printf("*");
			}
			if(thesi_lewforeiou[i]==0 && float(i%2!=0))
			{
				printf("_");
			}

		}

		for(i=arithmos_thesewn-4 ; i<arithmos_thesewn; i++)
			{
				if(thesi_lewforeiou[i]==1 )
				{

						printf("*");
				}
				if(thesi_lewforeiou[i]==0)
				{
					printf("_");
				}
			}
										*/

					break;
					}
/*12.Apothikeusi se arxeio*/
					case 8:
						{
						    printf("\nTo arxeio layout.txt exei apothikeutei");

						FILE *pFileout;
                        pFileout = fopen("layout.txt","w");

					if (pFileout !=NULL )
                        {

							fprintf(pFileout,"\n%s\n",arithmos_pinakidas);
							fprintf(pFileout,"\nDiagramma Lewforeiou\n\n" );

							j=0;
							for(i=0; i<arithmos_thesewn-5  ; i++)
							{
								if(thesi_lewforeiou[i]==1 && i==j+1)
								{
									fprintf(pFileout,"* ");

								}
									if(thesi_lewforeiou[i]==0 && i==j+1)
									{
										fprintf(pFileout,"_ ");

									}
									if(thesi_lewforeiou[i]==1 && i==j+3)
									{
										fprintf(pFileout,"*\n");
										j=i+1;

									}
									if(thesi_lewforeiou[i]==0 && i==j+3)
									{
										fprintf(pFileout,"_\n");
										j=i+1;

									}
									if(thesi_lewforeiou[i]==1 && ((i==j) || (i==j+2)))
									{
										fprintf(pFileout,"*");
									}
										if(thesi_lewforeiou[i]==0 && ((i==j) || (i==j+2)))
									{
										fprintf(pFileout,"_");
									}

							}
								for(i=arithmos_thesewn-5;i<arithmos_thesewn;i++)
								{
									if(thesi_lewforeiou[i]==1)
									{
										fprintf(pFileout,"*");
									}
										if(thesi_lewforeiou[i]==0)
									{
										fprintf(pFileout,"_");
									}
								}


							 	fclose (pFileout);//kleisimo fakelou
							 }
							break;
						}
			}

		}
	}
	while(i!=0);



//kleisimo fakelou
	fclose (pFile);
}

else
printf("Den uparxei fakelos me to onoma auto!\n");




}








