//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 1                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//*** Fullname:Vasiliki Tsiapakidou  A.M=123621             ***
//*************************************************************
#include <stdio.h>/* logw printf(), fscanf(), fopen(), fclose() */
#include <stdlib.h>/* logw exit() */
#include<string.h> /*strcmp memcpy*/

#define N 53
#define X 40
#define Y 10
struct seat/*dimiourgeia struct me stoixeia thesis lewforeiou*/
{
    char full_name[X];
    unsigned short tel_num[Y];
    unsigned int seat_num;
};
/*Dimiourgeia sunwnumou gia eukoloteri diaxeirisi*/
typedef struct seat SEAT;
/*Sunartisi arxikopoiishs pinaka gia oles kenes theseis*/
void initialize(SEAT *p,int y);
/*Sunartisi anoigmatos arxeiou kai enimerwsi pinaka*/
void open_read_file(SEAT *p,int *x,char *z);
/*Sunartisi metrisis kenwn thesewn*/
int count_empty_seat(SEAT *p,int y);
/*Sunartisi ektupwsis listas kenwn thesewn*/
void print_empty_seat(SEAT *p,int x);
/*Sunartisi kratisis thesis*/
void make_reservation(SEAT *p,int x,int y);
/*Sunartisi gia pliroi stoixeia nomatos*/
void full_name(char *y);
/*Anazitisi kratisis by name*/
void search_reservation_by_name(SEAT *p,char y[X],int x);
/*Sunartisi anazitisis kratisis mesw tilefwnou*/
void search_reservation_by_number(SEAT *p,unsigned short y[Y],int x);
/*Sunartisi akurwsis thesis*/
void cancel_reservation(SEAT *p,int x,int y);
/*Sunartisi ektupwsis apotelesmatwn*/
void print_results(SEAT x, int *y);
/*Sunartisi apothikeusis se arxeio*/
void open_write_to_file(SEAT *p,int x,char y[8]);
int main()
{
    int i,j,x,choice,choice1; /* boithitikes metablites */
    char license[8];/* pinakida kykloforias, 7 grammata-arithmoi kai to '\0' */
    int seats; /* plithos thesewn */
    SEAT bus[N]; /* lewforeio me to polu 53 theseis */
    initialize(bus,N);/*Arxikopoiisi wste oles oi theseis na einai kenes*/
    open_read_file(bus,&seats,license);/*Anoigma arxeiou*/
    choice=1;/* arxiki timi gia eisodo sto loop */
    while (choice!=0) /* mexri na epilegei termatismos */
    {
        printf("\n\n1.Emfanisi sunolikou plithous kenwn thesewn\nkai taksinomimeni lista twn aritmwn tous");
        printf("\n2. Kratisi thesis me sugkekrimeno arithmo");
        printf("\n3. Anazitisi an einai kratimeni sugkekrimeni thesi me vasi\nstoixeia onomatepwnumou eite arithmo tilefwnou");
        printf("\n4. Akurwsi kratisis me sugkekrimeno arithmo");
        printf("\n5.Emfanisi listas kratimenwn thesewn kata arithmo thesis");
        printf("\n0.Termatismos programmatos");
        printf("\nEpilogi:");
        scanf("%d", &choice);//perimenei eisagwgi apo xristi
        switch (choice)
        {
        case 1:
        {
            j=0;/*Voithitikos metritis*/
            printf("\nEmfanisi synolikoy plithous kenwn thesewn kai taksinomimeni lista autwn:\n");
            j= count_empty_seat(bus,seats);/*Metraei tis kenes theseis*/
            if(j==0)
            {
                /*periptwsi pou den uparxoun kenes theseis*/
                printf("\n Oles oi theseis einai kateilimenes!");
            }
            else
            {
                /*Ektupwsi arithmou kai listas kenwn thesewn*/
                printf("\nArithmos kenwn thesewn:%d",j);
                print_empty_seat(bus,seats);//Ektupwsi kenwn thesewn
            }
            break;
        }
        case 2:
        {
            /*An oles oi theseis einai kratimenes proeidopoiei oti den einai dunati i energeia,an den einai
            proxwraei elegxei an i timi pou dothike einai egkuri kai kanei tin kratisi i oxi analoga me to
            an i thesi einai kratimeni i oxi*/
            if(count_empty_seat(bus,seats)==0)
            {
                /*Periptvsi ppou oles oi theseis einai kateilimenes den uparxei logos na sunexisei o xristis*/
                printf("\nOles oi theseis einai kateilimenes den mporei na ginei kapoia kratisi auti ti stigmi!");
            }
            else
            {
                printf("\nEpilekste thesi epithumitis kratisis:");
                scanf("%d",&i);
                make_reservation(&bus[i-1],i,seats);//Sunartisi kratisis}
            }
            break;
        }
        case 3:
        {
            unsigned short telnum[Y];/*voithitikes metavlites gia eisagwgi stoixeiwn pelati*/
            char fullname[X];/*voithitikes metavlites gia eisagwgi stoixeiwn pelati*/
            choice1=1;
            while(choice1!=0)
            {
                /*To loop einai se periptwsi pou o xristis den patisei apo lathos 1 eite 2 na ton epistrefei
                sto menou epilogis kai vgainei minuma lathous*/
                printf("\n Anazitisi kratisis me vasi:\nEpitheto kai onoma:1\nArithmo tilefwnou kratisis:2\nEksodos:0\nEpilogi:");
                scanf("%d",&choice1);//Eisagwgi apo xristi
                if(choice1==0)
                {
                    printf("\nEpileksate eksodo!");
                }
                else if(choice1==1)
                {
                    /*Sunartisi opou ziteitai apo ton xrhsth ma eisagei ksexwrista epitheto kai onoma gia apofugi lathwn*/
                    full_name(fullname);
                    search_reservation_by_name(bus,fullname,seats);//Anazhthsh me ta stoixeia pou dothikan apo xristi
                    choice1=0;/*termatismos loop*/
                }
                else if(choice1==2)
                {
                    printf("\nDwste arithmo tilefwnou:");
                    for(i=0; i<10; i++)
                    {
                        scanf("%1hu",&telnum[i]);
                    }
                    search_reservation_by_number(bus,telnum,seats);//Anazhthsh me ta stoixeia pou dothikan apo xristi
                    choice1=0;/*termatismos loop*/
                }
                else
                {
                    printf("\n Eisagwgi ektos epilogwn!");
                }
            }
            break;
        }
        case 4:
        {
            printf("\nDwste arithmo thesis pou thelete na akurwthei:");
            scanf("%d",&i);//Eisagwgi apo xristi
            cancel_reservation(&bus[i-1],i,seats);//akurwsi thesis
            break;
        }
        case 5:
        {
            printf("\nTaksinomimeni lista kratisewn kratisewn kata No thesis:");
            printf("\nA/A Epitheto/onoma\t\t\t Arithmos tilefwnou  No.thesis");
            j=0;/*Voithitikos metritis,metraei poses ektupwseis exoun ginei*/
            for(i=0; i<seats; i++)
            {
                print_results(bus[i],&j);
            }
            if(j==0)/*Periptvsi pou den exei ginei kapoia kratisi ara kai ektupwsi*/
            {
                printf("\n\n\t\t***Adeia lista***");
            }
            break;
        }
        case 0:  /* min kaneis tipote */
            break;
        default:
            printf("\nAkatallili epilogi!!\n");
        }
    }
    /*ksananoigoume arxeio arxeio eksodou kai apothikeuoume ek neou*/
    open_write_to_file(bus,seats,license);
    return 0;
}
void initialize(SEAT *p,int y)
/*arxikopoiisa kai ton arithmo thesis=0 kai to tilefwno[0]=0 giati me voithise se alla kommatia tis ergasias*/
{
    int i;
    for(i=0; i<y; i++)
    {
        p[i].full_name[0]='\0';
        p[i].tel_num[0]=0;
        p[i].seat_num=0;
    }
}
void open_read_file(SEAT *p,int *y,char *z)
{
    int i,j;
    FILE* f_in;/* metablites-deiktes se arxeio */
    f_in = fopen("bus.txt","r");
    char line[80];//orismos voithitikou string pou tha "diavazei" grammi-grammi to arxeio
    char *item;//Voithitikos pointer gia diavasma arxeiou
    int reccount = 0;/*voithitikos metriti*/
    char epitheto[20];/*voithitikes metavlites*/
    char onoma[20];/*voithitikes metavlites*/
    char fullname[X];/*voithitikes metavlites*/
    unsigned short telnum[Y];/*voithitikes metavlites*/
    unsigned int seatnum;/*voithitikes metavlites*/
    if(f_in==NULL)
    {
        printf("To arxeio bus.txt den mporese na anagnwstei\n");
        exit(1);/*eksodos apo programma*/
    }
    else
    {
        while(fgets(line,80,f_in))
        {
            if(reccount==0)/*Diavasma pinakidas k arithmou thesewn stin prwti seira tou arxeiou*/
            {
                item =strtok(line," ");
                strcpy(z,item);
                printf("\nH pinakida kukloforias einai:%s",z);
                item =strtok(NULL,"\n");
                *y=atoi(item);
                printf("\nO arithmos thesewn einai:%d\n",*y);
            }
            else/*Diavasma tou upoloipou arxeiou me tis kratiseis stamataei otan vrei keno eite \n
                antigrafei tis plirofories stis voithitikes metavlites*/
            {
                item =strtok(line," ");
                strcpy(epitheto,item);
                item = strtok(NULL," ");
                strcpy(onoma,item);
                strcpy(fullname,epitheto);
                strcat(fullname," ");
                strcat(fullname,onoma);
                item=strtok(NULL," ");
                seatnum=atoi(item);
                item=strtok(NULL,"\n");
                for(i=0; i<10; i++)
                {
                    sscanf(&item[i],"%1hu",&telnum[i]);
                }
                /*Ta stoixeia perniountai sti swsti thesi ston pinaka*/
                strcpy(p[seatnum-1].full_name,fullname);
                p[seatnum-1].seat_num=seatnum;
                memcpy( p[seatnum-1].tel_num, telnum, sizeof(p[seatnum-1].tel_num) );
            }
            reccount++;/*auksisi metriti gia na "parei"tin epomeni seira*/
        }
        fclose(f_in);//kleisimo arxeiou
        for(i=0; i<*y; i++)/*Ektupwsi kratisewn stin othoni*/
        {
            if(p[i].full_name[0]!='\0')
            {
                printf("\n%s ",p[i].full_name);
                printf ("%u ",p[i].seat_num);
                for(j=0; j<10; j++)
                {
                    printf("%hu",p[i].tel_num[j]);
                }
            }
        }
    }
}
int count_empty_seat(SEAT *p,int y)
{
    int i,z;
    z=0;
    for (i=0; i<y; i++)
    {
        if(p[i].full_name[0]=='\0')
            z+=1;/* an thesi eleutheri, aujise to metriti */
    }
    return z;/*epistrefw ton metriti stin main*/
}
void print_empty_seat(SEAT *p,int x)
{
    int i;
    printf("\nArithmoi thesis kenwn thesewn:[");
    for(i=0; i<x; i++)
    {
        if(p[i].full_name[0]=='\0')/*keni thesi*/
        {
            printf("%d,",i+1);
        }
    }
    printf("]");
}
void make_reservation(SEAT *p,int x,int y)
{
    char epitheto[20];/*voithitikes metavlites*/
    char onoma[20];/*voithitikes metavlites*/
    int j;/*voithitikes metavlites*/
    if(x<1 || x>y)
    {
        printf("\nEpilogi thesis ektos epitreptwn oriwn!");
    }
    else
    {
        if (p->full_name[0]=='\0')/*I thesi einai adeia ara mporei na ginei kratisi*/
        {
            printf("\nKataxwrisi stoixewn gia na oloklirwthei i kratisi tis thesis %d:",x);
            printf("\nEpitheto epivati:");
            scanf("%s",epitheto);
            printf("\nonoma epivati:");
            scanf("%s",onoma);
            strcpy(p->full_name,epitheto);
            strcat(p->full_name," ");
            strcat(p->full_name,onoma);
            printf("\nTilefwno kratisis:");
            for (j=0; j<10; j++)
                scanf("%1hu",&p->tel_num[j]);
            p->seat_num=x;
            printf("\nH kratisi sas gia tin thesi %d exei oloklirwthei!",x);
        }
        else
        {
            /*i thesi einai idi kratimeni*/
            printf("\nDen mporei na ginei kratisi gia idi kratimeni thesi!");
        }
    }
}
void full_name(char *y)
{/*Gia eukoloteri diaxeirisi kai apofugi lathwn ziteitai o xristis ksexwrista na eisagei epitheto kai onoma*/
    char epitheto[20];
    char onoma[19];
    printf("\nDwste epitheto:");
    scanf("%s",epitheto);
    printf("\nDwste onoma:");
    scanf("%s",onoma);
    strcpy(y,epitheto);
    strcat(y," ");
    strcat(y,onoma);
}
void search_reservation_by_name(SEAT *p,char y[X],int x)
{
    int i,s,z;
    s=1;
    z=0;//Voithitikos metritis
    for(i=0; i<x; i++)
    {
        s=strcmp(p[i].full_name,y) ;
        if(s==0)
        {
            z+=1;
        }
    }
    if(z!=0 && z!=1)/*Periptwsi pou exoun ginei panw apo mia kratiseis me ta idia stoixeia*/
    {
        printf("\nMe auta ta stoixeia exei ginei kratisi gia tis theseis:");
        printf("[");
        for(i=0; i<x; i++)
        {
            s=strcmp(p[i].full_name,y) ;
            if(s==0)
            {
                printf("%d,",i+1);
            }
        }
        printf("]");
    }
    else if(z==1)/*periptvsi pou exei ginei mono mia kratisi*/
    {
        printf("\nMe auta ta stoixeia exei ginei kratisi gia tin thesi:");
        for(i=0; i<x; i++)
        {
            s=strcmp(p[i].full_name,y) ;
            if(s==0)
            {
                printf("%d",i+1);
            }
        }
    }
    else
    {
        printf("\nMe auta ta stoixeia den exei ginei kapoia kratisi!");
    }
}
void search_reservation_by_number(SEAT *p,unsigned short y[Y],int x)
{
    int i,z,s;
    z=0;//Voithitikos metritis
    s=1;
    for(i=0; i<x; i++)
    {
        s=memcmp(p[i].tel_num, y, sizeof(p[i].tel_num));/*Sugkrinw dosmeno arithmo me arithmous apo pinaka*/
        if(s==0)
        {
            z+=1;/*Metritis poses fores emfanizetai o arithmos sto arxeio*/
        }
    }
    if(z!=0 && z!=1)/*Periptwsi pou exoun ginei panw apo mia kratiseis me ta idia stoixeia*/
    {
        printf("\nMe auta ta stoixeia exei ginei kratisi gia tis theseis:");
        printf("[");
        for(i=0; i<x; i++)
        {
            s=memcmp(p[i].tel_num, y, sizeof(p[i].tel_num));
            if(s==0)
            {
                printf("%d,",i+1);
            }
        }
        printf("]");
    }
    else if(z==1)/*periptvsi pou exei ginei mono mia kratisi*/
    {
        printf("\nMe auta ta stoixeia exei ginei kratisi gia tin thesi:");
        for(i=0; i<x; i++)
        {
            s=memcmp(p[i].tel_num, y, sizeof(p[i].tel_num));
            if(s==0)
            {
                printf("%d",i+1);
            }
        }
    }
    else
    {
        printf("\nMe auta ta stoixeia den exei ginei kapoia kratisi!");
    }
}
void cancel_reservation(SEAT *p,int x,int y)
{
    if(x<1 || x>y)
    {
        printf("\nEpilogi thesis ektos epitreptwn oriwn!\n");
    }
    else
    {
        if(p->full_name[0]!='\0')
        {
            p->full_name[0]='\0';
            p->tel_num[0]=0;
            p->seat_num=0;
            printf("\nH akyrwsi tis thesis %d exei kataxwrithei",x);
        }
        else
        {
            printf("\nH thesi den einai kratimeni!\nDen mporei na ginei akurwsi gia mi kratimeni thesi!");
        }
    }
}
void print_results(SEAT x, int *y)
{
    int j;
    if(x.full_name[0]!='\0')
    {
        printf("\n%d)%-40s ",*y+1,x.full_name);
        for(j=0; j<10; j++)
        {
            printf("%hu",x.tel_num[j]);
        }
        printf("\t\t %u",x.seat_num);
        *y+=1;//voithitikos metritis aksiopoieitai otan den exei ginei kamia ektupwsi i otan exoun ginei parapanv apo mia
    }
}
void open_write_to_file(SEAT *p,int x,char y[8])
{
    int i,j;
    FILE* f_out;/* metablites-deiktes se arxeio */
    f_out = fopen("bus.txt","w+");/*Idio onoma arxeiou gia na to anoigei se epomeno anoigma tou programmatos*/
    /*To arxeio grafetai apo tin arxi den enimerwnetai aplws giati theloume to arxeio na einai taksinomimeno kata arithmo thesis*/
    if(f_out==NULL)
    {
        printf("To arxeio bus.txt den mporese na anagnwstei\n");
        exit(1);/*eksodos apo programma*/
    }
    else
    {
        fprintf(f_out,"%s ",y);/*ektupwnei tin pinakida*/
        fprintf(f_out,"%d",x);/*ektupwsi arithmou thesewn*/
        for(i=0; i<x; i++)
        {
            if(p[i].seat_num!=0)/*ektupwsi stoixeiwn kateilimenwn thesewn*/
            {
                fprintf(f_out,"\n%s",p[i].full_name);
                fprintf (f_out," %u ",p[i].seat_num);
                for(j=0; j<10; j++)
                {
                    fprintf(f_out,"%hu",p[i].tel_num[j]);
                }
            }
        }
    }
    fclose(f_out);/*kleisimo arxeiou*/
}










