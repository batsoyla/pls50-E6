//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 3                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//*** Fullname:Vasiliki Tsiapakidou  A.M=123621             ***
//*************************************************************
#include<stdio.h>/*gia printf scanf*/
#include<string.h>/*gia memcpy*/
#include<time.h>/*gia srand(time(NULL))*/
struct player/*dimiourgeia struct gia paikti*/
{
    char name[17];
    unsigned char  score;
    char id;
};

struct card/*dimiourgeia struct gia karta*/
{
    char colour;
    char symbol;
    char  number;
    char shading;
};
/*Sunartisi olwn twn pithanwn sunduasmwn*/
void all_possible_comb(struct card *p);
/*tuxaia epilogi kartwn*/
void random_choice(struct card pinakas[][4],struct card *bus);
/*ektupwsi meta tin epilogi*/
void print_comb(struct card pinakas [][4]);
/*Epilogi kartwn*/
void choice_of_cards(struct card *p,struct card pinakas[][4]);
/*Sugrisi gia set*/
int comparison_of_cards(struct card *set1);
/*sunartisi epilogis kartwn*/
struct player *get_player(struct player *p,char o);
int main()
{
    int i;
    char a;/*Voithitiki metavliti*/
    /*Eisagwgi stoixewn gia tous paiktes se pinaka apo struct*/
    struct player play[3];
    strcpy(play[0].name, "Marina Andreou");
    play[0].score=0;
    play[0].id='a';
    strcpy(play[1].name, "Kostas Grammenos");
    play[1].score=0;
    play[1].id='g';
    strcpy(play[2].name, "Maria Perdika");
    play[2].score=0;
    play[2].id='p';
    struct card pin[82];/*pinakas apo domes gia olous tous pithanous sunduasmous*/
    struct card pinakas[3][4];/*Disdiastatos pinakas struct pou tha emfanizei tis kartes tou paixnidiou*/
    struct card set1[3];/*Pinakas pou tha apothikeuontai oi 3 kartes pou tha epilegei o energos paiktis*/
    random_choice(pinakas,pin);
    print_comb(pinakas);
    a='t';
    while(a!='0')
    {
        printf("\nEpilogi paikti\nEisagete id:");
        scanf(" %c",&a);
        if(a=='0')
        {
            printf("\nEpileksate eksodo apo to paixnidi!");
        }
        else
        {
            struct player *current;
            current=get_player(play,a);
            if (current==NULL)
            {
                /*Se periptwsi mi egkuris eisagwgis id ta xartia ksanaepilegontai apo tin arxi,auto voithaei kai
                stin periptwsi opou den entopizetai kapoio set thewroume oti enas 'paratiritis' eisagei mia mi egkuri
                epilogi gia na kseknisei kainourgios guros*/
                printf("\n eisagwgii mi egkurou paikti!");
                random_choice(pinakas,pin);
                print_comb(pinakas);
            }
            else
            {
                choice_of_cards(set1,pinakas);
                if(comparison_of_cards(set1)==0)/*I sugkrisi kartwn epistrefei 0 otan exoume set kai 1 otan den exoume*/
                {
                    current->score+=2;
                    printf("\nOnoma paikti %s\nscore=%u\n\n",current->name,current->score);
                    if(current->score>=10)
                    {
                        printf("\nTo paixnidi teleiwse\n\n");
                        a='0';/*Eksodos apo loop*/
                    }
                    else /*Nea partida*/
                    {
                        random_choice(pinakas,pin);
                        print_comb(pinakas);
                    }
                }
                else
                {
                    /*Edw o epomenos paiktis paizei gia tin idia 12ada kartwn*/
                    if(current->score>0)
                    {
                        current->score-=1;
                        printf("\nOnoma paikti %s\nscore=%u\n\n",current->name,current->score);
                        print_comb(pinakas);
                    }
                    else
                    {
                        printf("\nH vathmologia sou=0 den mporei na meiwthei allo!\n\n");
                        print_comb(pinakas);
                    }
                }
            }
        }
    }/*To paixnidi teleiwnei eite gia eisagwgi '0' eite an exoume nikiti*/
    printf("\n\nid Onoma paikti\t\tTeliko score\n");
    for(i=0; i<3; i++)
    {
        printf("\n%c %-20s\t\t%1hu",play[i].id,play[i].name,play[i].score);
    }
    for(i=0; i<3; i++)
    {
        if(play[i].score==10)
        {
            printf("\n O nikitis einai o/i %s!!!",play[i].name);
        }
    }
    return 0;
}


struct player *get_player(struct player *p,char o)
{
    int m;
    for(m=0; m<3; m++)
    {
        if(p[m].id==o)/*Vriskei apo pinaka paiktwn poios einai o energos*/
        {
            printf("\nEnergos paiktis:%s",p[m].name);
            printf("\nTo score paikti einai %u",p[m].score);
            return &p[m];
        }
    }
    return NULL;
}
void all_possible_comb(struct card *p)
{
    /*Dimiourgeia olwn ton pithanwn sunduasmwn*/
    int i,j,f,n,k;
    /*Oi pithanes times gia kathe idiotita tis kartas*/
    char array1[]="rgb";
    char array2[]="ctr";
    char array3[]="123";
    char array4[]="bhe";
    k=0;
    for(n=0; n<3; n++)
    {
        for(f=0; f<3; f++)
        {
            for(j=0; j<3; j++)
            {
                for(i=0; i<3; i++)
                {
                    p[k].colour=array1[i];
                    p[k].symbol=array2[j];
                    p[k].number=array3[f];
                    p[k].shading=array4[n];
                    /*Dimiourgeitai i karta kai auksanei o metritis gia na perasoume stin epomeni*/
                    k++;
                }
            }
        }
    }
}

void random_choice(struct card pinakas[][4],struct card *pin)
{
    all_possible_comb(pin);/*Dimiourgei olous tous pithanous sunduasmous*/
    srand(time(NULL));/*aparaititi gia dimiourgeia tuxaiwn arithmwn pairnei
    san orisma stoixeia wras sustimatos gia kaluteri dimiougeia tuxaiwn arithmwn*/
    int j,x,k,selector;
    selector=0;
    for(j=0; j<3; j++)
    {
        for(k=0; k<4; k++)
        {
            selector=0;
            x=rand()%82;/*gennitria tuxaiwn arithmwn apo 0  ews 81*/
            while(selector==0)
            {
                if(pin[x].colour!='\0')
                {
                    pinakas[j][k].colour= pin[x].colour;
                    pinakas[j][k].symbol= pin[x].symbol;
                    pinakas[j][k].number=pin[x].number;
                    pinakas[j][k].shading =pin[x].shading;
                    pin[x].colour='\0';/*I karta afaireitai apo ton pinaka gia na min uparxoun idies kartes ston pinakas[3][4]*/
                    selector=1;/*Otan dialegei karta kai tin topothetei ston pinakas[3][4]
vaginei apo tin while kai ksanampainei stin for gia nea karta*/
                }
                else
                {
                    x=rand()%82;/*Nea epilogi arithmou apo 0 ews 81 afou gia ton proigoumeno arithmo i karta eixe idia epilegei*/
                }
            }
        }
    }
}
void print_comb(struct card pinakas [][4])
{
    /*ektupwsi sunduasmou 12 kartwn*/
    int j,k;
    k=0;/*Metritis*/
    printf("\nParatiriste tis kartes kai vreite poios sunduasmos 3 kartwn dimiourgei set...\n\n");
    for(j=0; j<3; j++)
    {
        printf("\n\t\t[%c,%c,%c,%c] ",pinakas[j][k].colour,pinakas[j][k].symbol,pinakas[j][k].number,pinakas[j][k].shading);
        k++;
        printf("[%c,%c,%c,%c] ",pinakas[j][k].colour,pinakas[j][k].symbol,pinakas[j][k].number,pinakas[j][k].shading);
        k++;
        printf("[%c,%c,%c,%c] ",pinakas[j][k].colour,pinakas[j][k].symbol,pinakas[j][k].number,pinakas[j][k].shading);
        k++;
        printf("[%c,%c,%c,%c]\n",pinakas[j][k].colour,pinakas[j][k].symbol,pinakas[j][k].number,pinakas[j][k].shading);
        k=0;
    }
}
void choice_of_cards(struct card *p,struct card pinakas[][4])
{
    /*Epilogi kartwn apo ton paikti*/
    struct card copy[3][4];
    memcpy(copy, pinakas, sizeof(copy));
    int a,i,x,y;
    i=0;
    a=0;
    while(i<3)
    {
        x=y=0;
        printf("\nEpilogi kartas No %d",i+1);
        printf("\nGrammi No: ");
        scanf("%d",&x);
        printf("Stili  No:");
        scanf("%d",&y);
        if((x<0 ||x>2) ||(y<0 || y>3))
        {
            printf("\nDwsate epiloges ektos epitreptwn oriwn");
        }
        else
        {
            if(copy[x][y].colour!='a')
            {
                p[i]=copy[x][y];
                copy[x][y].colour='a';/*Gia na min ksanadialeksei o paiktis tin idia karta*/
                i+=1;/*Auksisi metriti gia epilogi epomenis kartas stis alles
 periptwseis o metritis den auksanei kai ksanaziteitai apo ton paikti na dialeksei tin idia karta*/
            }
            else
            {
                printf("\nExete idi dialeksi auti tin karta!");
            }
        }
    }
}
int comparison_of_cards(struct card *set1)
{
    /*elegos an dimiourgeitai set*/
    if((set1[0].colour==set1[1].colour && set1[0].colour==set1[2].colour)||(set1[0].colour!=set1[1].colour && set1[0].colour!=set1[2].colour && set1[1].colour!=set1[2].colour))
    {
        if((set1[0].symbol==set1[1].symbol && set1[0].symbol==set1[2].symbol)||(set1[0].symbol!=set1[1].symbol && set1[0].symbol!=set1[2].symbol && set1[1].symbol!=set1[2].symbol))
        {
            if((set1[0].number==set1[1].number && set1[0].number==set1[2].number)||(set1[0].number!=set1[1].number&& set1[0].number!=set1[2].number && set1[1].number!=set1[2].number))
            {
                if((set1[0].shading==set1[1].shading && set1[0].shading==set1[2].shading)||(set1[0].shading!=set1[1].shading&& set1[0].shading!=set1[2].shading && set1[1].shading!=set1[2].shading))
                {
                    printf("\nSugxaritiria petuxes set !") ;
                    return 0;
                }
                else
                {
                    printf("\nLupamai den petuxate set!!");
                    return 1;
                }
            }
            else
            {
                printf("\nLupamai den petuxate set!!");
                return 1;
            }
        }
        else
        {
            printf("\nLupamai den petuxate set!!");
            return 1;
        }
    }
    else
    {
        printf("\nLupamai den petuxate set!!");
        return 1;
    }
}




