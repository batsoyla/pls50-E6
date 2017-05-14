//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 2                ***
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
struct node/*Dimiourgeia kombou gia sundedemeni lista*/
{
    SEAT data;/*apothikeuontai oi plirofories to kombou*/
    struct node *next;/*deixnei pou deixnei o kombos*/
}*start=NULL;/*orismos pointer kefali arxika deixnei se NULL i lista einai adeia*/

/*Sunartisi arxikopoiishs pinaka*/
void initialize(SEAT *p,int y);
/*Sunartisi anoigmatos arxeiou dimiourgeia dunamikou pinaka kai ektupwsi pinakidas kai arithmou thesewn*/
void open_read_file_licence_seats(SEAT **p,int *y,char *z);
/*Sunartisi dunamikis desmeusis mnimis*/
void allocate_memory(SEAT **p,int y);
/*Sunartisi pairnei kratiseis apo arxeio kai tis topothetei ston dunamiko pinaka*/
void open_read_file_reservations(SEAT *p,int y);
/*Sunartisi metrisis kenwn thesewn*/
int count_empty_seat(SEAT *p,int y);
/*Sunartisi ektupwsis kenwn thesewn*/
void print_empty_seat(SEAT *p,int x);
/*Sunartisi kratisis thesis*/
void make_reservation(SEAT *p,int x,int y);
/*Sunartisi gia pliroi stoixeia nomatos*/
void full_name(char *y);
/*Sunartisi anazitisi kratisis by name*/
void search_reservation_by_name(SEAT *p,char y[X],int x);
/*Sunartisi anazitisis kratisis mesw tilefwnou*/
void search_reservation_by_number(SEAT *p,unsigned short y[Y],int x);
/*Sunartisi akurwsis thesis*/
void cancel_reservation(SEAT *p,int x,int y);
/*Sunartisi Algorithmos taksinomisis se alfavitiki seira*/
void bubble_sort(SEAT *p,int n);
/*Sunartisi epanafora pinaka*/
void restore_array(SEAT *p,int n);
/*Sunartisi gia antallagi pliroforiwn anamesa se theseis pinaka*/
void swap(SEAT *p,SEAT *a);
/*Sunartisi gia taksinomisi me vasi ton arithmo thesis*/
void order_by_nymber(SEAT *p,int y);
/*Sunartisi eisagwgis sto telos listas*/
void insert_at_end(struct node **start,SEAT x);
/*Sunartisi apothikeusis stoixeiwn se arxeio*/
void open_write_to_file(struct node *start,int seats,char license[8]);
/*Sunartisi katastrofis listas*/
void destroy_list(struct node **start);

int main()
{
    int i,j,x,choice,choice1; /* boithitikes metablites */
    int seats; /* plithos thesewn */
    char license[8];/* pinakida kykloforias, 7 grammata-arithmoi kai to '\0' */
    SEAT *bus=NULL;/*Dilwsi pointer pou deixnei NULL*/
    open_read_file_licence_seats(&bus,&seats,license);/*Pairnei plirofories apo arxeio ektupwnei arithmo pinakidas kai
arithmo thesewn kai desmeuei dunamika pinaka gia arithmo thesewn*/
    open_read_file_reservations(bus,seats);/*Anoigei ksana to arxeio kai enimervnei ton dunamiko pinaka gia tis
kratiseis pou exoun ginei kai ta ektupwnei stin othoni*/
    choice=1;/* arxiki timi gia eisodo sto loop */
    while (choice!=0) /* mexri na epilegei termatismos */
    {
        printf("\n\n1.Emfanisi sunolikou plithous kenwn thesewn kai taksinomimeni lista twn aritmwn tous");
        printf("\n2. Kratisi thesis me sugkekrimeno arithmo");
        printf("\n3. Anazitisi an einai kratimeni sugkekrimeni thesi me vasi\nstoixeia onomatepwnumou eite arithmo tilefwnou");
        printf("\n4. Akurwsi kratisis me sugkekrimeno arithmo");
        printf("\n5.Emfanisi listas kratimenwn thesewn taksinomimeni kata onomatepwnumo i aritmo thesis");
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
            choice1=1;
            while(choice1!=0)
            {
                /*Epilegw loop etsi wste an o xristis den dwsei mi egkuri timi ektupwnetai minima lathous kai
                epistrefei sto menou opou tou dinetai kai i epilogi eksodou*/
                printf("\nEpitheimeite taksinomisi listas kata:\nAlfavitiki seira:1\nArithmo thesis:2\nEksodo:0");
                printf("\nEpilogi:");
                scanf("%d",&choice1);
                if(choice1==1)/*Taksinomisi me alfavitiki seira*/
                {printf("\n\t\t***Taksinomimeni lista se alphavitiki seira***\nA/AFullname\t\t\t\t\t tel.numb \t\tNo.seat");
                    int k;//metritis pou voithaei stin ektupwsi
                    k=0;
                    bubble_sort(bus,seats);//Algorithmos taksinomisis me alfavitiki seira
                    for(i=0; i<seats; i++)
                    {
                        if(bus[i].full_name[0]!='\0')/*Ektupwsi pleon twn alfavitika taksinomimenwn thesewn*/
                        {
                            printf("\n%d)%-40s\t ",k+1,bus[i].full_name);
                            for(j=0; j<10; j++)
                            {
                                printf("\%hu",bus[i].tel_num[j]);
                            }
                            printf("\t\t  %u",bus[i].seat_num);
                            k++;
                        }
                    }
                    restore_array(bus,seats);/*Apokatastasi pinaka*/
                    choice1=0;/*eksodos apo loop*/
                }
                else if(choice1==2)
                {printf("\n\t\t***Taksinomimeni lista me vasi aritho thesis***");
                    order_by_nymber(bus,seats);/*Taksinomisi me vasi arithmo*/
                    choice1=0;
                }
                else if(choice1==0)
                {
                    printf("\nEpileksate eksodo!");
                }
                else
                {
                    printf("\nMi egkuri epilogi!");
                }
            }
            break;
        }
        case 0:  /* min kaneis tipote */
            break;
        default:
            printf("\nakatallili epilogi!!\n");
        }
    }
    bubble_sort(bus,seats);/*Taksinomisi pali me vasi to onomatepwnumo*/
    for(i=0; i<seats; i++)
    {
        if(bus[i].full_name[0]!='\0')/*otan uparxei kratisi eisagei sto telos listas*/
        {
            //printf("\n gia thesi %d kai onoma %s",i,bus[i].full_name);
            insert_at_end(&start,bus[i]);/*eisagwgi sto telos listas me anadromiko algorithmo*/
        }
    }
    open_write_to_file(start,seats,license);/*Pairnei kai apothikeuei pinakida kai arithmo thesewn ek neou episis pairnei
san orisma tin lista kai tin apothikeuei sto arxeio*/
    destroy_list(&start);/*Katastrofi listas*/
    free(bus);//Apeleutherwsi pinaka bus
    return 0;
}

void initialize(SEAT *p,int y)
{
    int i;
    for(i=0; i<y; i++)
    {
        p[i].full_name[0]='\0';/*opws orizei i ekfwnisi*/
        p[i].tel_num[0]=0;
        p[i].seat_num=i+1;/*Mas voithaei stin taksinomisi pinaka*/
    }
}
void open_read_file_licence_seats(SEAT **p,int *y,char *z)
{
    int i,j;
    FILE* f_in;/* metablites-deiktes se arxeio */
    f_in = fopen("bus.txt","r");
    char line[80];//orismos voithitikou string pou tha "diavazei" grammi-grammi to arxeio
    char *item;//Voithitikos pointer gia diavasma arxeiou
    int reccount = 0;/*voithitikos metriti*/
    if(f_in==NULL)
    {
        printf("To arxeio bus.txt den mporese na anagnwstei\n");
        exit(1);/*eksodos apo programma*/
    }
    else
    {
        while(fgets(line,79,f_in)!=NULL)
        {
            if(reccount==0)//diavazei prwti grammi arxeiou mono
            {
                item =strtok(line," ");
                strcpy(z,item);
                printf("\nH pinakida kukloforias einai:%s",z);
                item =strtok(NULL,"\n");
                *y=atoi(item);
                printf("\nO arithmos thesewn einai:%d\n",*y);
                allocate_memory(p,*y);//Desmeuei dunamika mnimi gia arithmo thesewn pou diavase
                initialize(*p,*y);//arxikopoiisi thesewn ston dunamiko pinaka
                reccount=1;
            }
            fclose(f_in);//kleisimo arxeiou
        }
    }
}
void allocate_memory(SEAT **p,int y)
{
    *p=malloc(sizeof(SEAT )*y);/*Desmeusi mnimis gia ton arithmo thesewn pou diavase apo arxeio*/
    if(!*p)
    {
        printf("\nApotuxia desmeusis mnimis!");
        exit(0);
    }
}
void open_read_file_reservations(SEAT *p,int y)
{
    int i,j;
    FILE* f_in;/* metablites-deiktes se arxeio */
    f_in = fopen("bus.txt","r");
    char line[80];//orismos voithitikou string pou tha "diavazei" grammi-grammi to arxeio
    char *item;//Voithitikos pointer gia diavasma arxeiou
    int reccount = 0;/*voithitikos metriti*/
    char epitheto[20];/*voithitikes metavlites*/
    char onoma[19];/*voithitikes metavlites*/
    char fullname[40];/*voithitikes metavlites*/
    unsigned short telnum[10];/*voithitikes metavlites*/
    unsigned int seatnum;/*voithitikes metavlites*/
    if(f_in==NULL)
    {
        printf("To arxeio bus.txt den mporese na anagnwstei\n");
        exit(1);/*eksodos apo programma*/
    }
    else
    {
        while(fgets(line,79,f_in)!=NULL)
        {
            if(reccount==0)
            {/*Edw diavazei tin prwti seira den kanei tipota aplws auksanei ton metriti*/
                reccount++;
            }
            else/*Diavasma tou upoloipou arxeiou me tis kratiseis stamataei otan vrei keno eite \n*/
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
            reccount++;
        }
        fclose(f_in);//kleisimo arxeiou
        for(i=0; i<y; i++)/*Ektupwsi kratisewn stin othoni*/
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
{
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
            z+=1;/*metraei poses fores exei ginei kratisi me auta ta stoixeia*/
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
    int i,z,s;/*voithitikes metavlites*/
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
    if(x<1 || x>y)/*elegxos an i dosmenos arithmos einai entos oriwn*/
    {
        printf("\nEpilogi thesis ektos epitreptwn oriwn!\n");
    }
    else
    {
        if(p->full_name[0]!='\0')
        {
            p->full_name[0]='\0';
            p->tel_num[0]=0;
            p->seat_num=x;
            printf("\nH akyrwsi tis thesis %d exei kataxwrithei",x);
        }
        else
        {
            printf("\nH thesi den einai kratimeni!\nDen mporei na ginei akurwsi gia mi kratimeni thesi!");
        }
    }
}
void bubble_sort(SEAT *p,int n)
{
    int i,j,l;
    for(i=0; i<n; i++)
    {/*Algorithmos taksinomisis gia alfavitiki seira*/
        /*loop gia olous tous arithmous thesewn*/
        for(j=n-1; j>=i+1; j--) /*deutero loop pou diavazei ton pinaka anapoda*/
        {
            l=strcmp(p[j].full_name,p[j-1].full_name);//Sugkrisi sumboloseirwn
            if(l<0)
            {
                swap(&p[j],&p[j-1]);//tis allazei theseis metaksu tous analoga me to apotelesma
            }
        }
    }
}
void restore_array(SEAT *p,int n)
{
    int i,j,l;
    for(i=0; i<n; i++)
    {
        /*loop gia olous tous arithmous thesewn*/
        for(j=n-1; j>=i+1; j--) /*deutero llop pou diavazei ton pinaka anapoda*/
        {
            if(p[j].seat_num<p[j-1].seat_num)
            {
                swap(&p[j],&p[j-1]);//tis allazei theseis metaksu tous analoga me to apotelesma
            }
        }
    }
}
void swap(SEAT *p,SEAT *a)
{
    char fullname[40];
    unsigned short telnum[10];
    unsigned int seatnum;
    strcpy(fullname,p->full_name);
    strcpy(p->full_name,a->full_name);
    strcpy(a->full_name,fullname);
    seatnum=p->seat_num;
    p->seat_num=a->seat_num;
    a->seat_num=seatnum;
    memcpy( telnum,p->tel_num, sizeof(telnum) );
    memcpy( p->tel_num,a->tel_num, sizeof(p->tel_num) );
    memcpy(a->tel_num,telnum,sizeof(a->tel_num));
}
void order_by_nymber(SEAT *p,int y)
{
    printf("\nA/AFullname\t\t\t\t\t tel.numb \t\tNo.seat");
    int i,j,k;
    k=0;
    for(i=0; i<y; i++)
    {
        if(p[i].full_name[0]!='\0')
        {
            printf("\n%d)%-40s\t ",k+1,p[i].full_name);
            for(j=0; j<10; j++)
            {
                printf("\%hu",p[i].tel_num[j]);
            }
            printf("\t\t  %u",p[i].seat_num);

            k++;
        }
    }
}
void insert_at_end(struct node **start,SEAT x)
{
    struct node *temp;
    struct node *new_node=(struct node *)malloc(sizeof(struct node));/*Dunamiki desmeusi gia neo kombo*/
    if(new_node == NULL)
    {
        printf( "Unable to allocate memory for new node\n");
        exit(-1);
    }
    swap(&new_node->data,&x);/*ston neo kombo metaferoume tis times pou exei to x*/
    new_node->next=NULL;
    temp=*start;
    if(*start  == NULL)
    {
        /*Arxika i lista einai keni kai i prwti eisagwgi ginetai stin arxi*/
        temp=new_node;
        *start=new_node;
    }
    else
    {
        if(temp->next == NULL )
        {/*Otan einai sto telos tis listas ginetai eisagwgi*/
            temp->next= new_node;
        }
        else
        {
            insert_at_end(&temp->next,new_node->data);/*anadromi otan den einai sto telos gia epomeni thesi
            ksanakaloume tin sunartisi gia new_mode->data giati prin praktika tous antallaksame plirofories ara
            oi plirofories tou x twra vriskontai sto new_mode->data*/
        }
    }
}
void open_write_to_file(struct node *start,int seats,char license[8])
{
    int i;
    FILE* f_out;/* metablites-deiktes se arxeio */
    f_out = fopen("bus.txt","w+");
    if(f_out==NULL)
    {
        printf("To arxeio bus.txt den mporese na anagnwstei\n");
        exit(1);/*eksodos apo programma*/
    }
    else
    {/*Apothikesi pinakidas kai arithmou thesewn sto arxeio*/
        fprintf(f_out,"%s ",license);
        fprintf(f_out,"%d",seats);
        if(start==NULL)
        {
            printf("\nH lista einai adea!");
            return;
        }
        else
        {
            while (start!=NULL)
            {
                /*Sarwnei tin lista apothikeuei sto arxeio kai proxwraei stin epomeni thesi*/
                fprintf(f_out,"\n%s %u ",start->data.full_name,start->data.seat_num);
                for (i=0; i<10; i++)
                {
                    fprintf(f_out,"%hu",start->data.tel_num[i]);
                }
                start=start->next;/*proxwraei sti lista*/
            }
        }
    }
    fclose(f_out);/*kleisimo arxeiou*/
}
void destroy_list(struct node **start)
{
    /*Apodesmeuei enan enan tous kombous tis listas*/
    struct node *ptr;
    while(*start!=NULL)
    {
        ptr=*start;
        *start=(*start)->next;
        free(ptr);
    }
}



















