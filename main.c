#include <stdio.h>
#include <stdlib.h>

#define LIMIT_STORE_SIZE 5
#define DEFAULT_P1 300
#define DEFAULT_P2 450
#define DEFAULT_P3 870
#define DEFAULT_P4 340
#define DEFAULT_P5 970



#ifdef _WIN32
#define CLEARS "cls"
#else
#define CLEARS "clear"
#endif // ClearScreenVal-Win-or-Linux.

void clear_screen()
{
    system("pause");
    system(CLEARS);
}

struct Product
{
    char* name;
    char* desc;
    float price;
    int cantStock;
};

struct Ticket
{
    char* name;
    char* desc;
    float priceUnit;
    float priceTotal;
    int cant;
};

int main()
{
    int opc,i,flag,globalStock,numProduct,cantProduct,limitSellProduct;
    float totalTicket=0;
    globalStock=DEFAULT_P1+DEFAULT_P2+DEFAULT_P3+DEFAULT_P4+DEFAULT_P5;
    struct Ticket ticket[globalStock];
    struct Product pdcto[LIMIT_STORE_SIZE];

    pdcto[0].name="Plakton";
    pdcto[0].desc="Imported 20gr";
    pdcto[0].price=12.50;
    pdcto[0].cantStock=DEFAULT_P1;

    pdcto[1].name="Tomato";
    pdcto[1].desc="Kg";
    pdcto[1].price=8.75;
    pdcto[1].cantStock=DEFAULT_P2;

    pdcto[2].name="Eggs";
    pdcto[2].desc="12 Pieces Pack";
    pdcto[2].price=24.50;
    pdcto[2].cantStock=DEFAULT_P3;

    pdcto[3].name="Beer";
    pdcto[3].desc="6 Pack ";
    pdcto[3].price=130.50;
    pdcto[3].cantStock=DEFAULT_P4;

    pdcto[4].name="Milk";
    pdcto[4].desc="Lt";
    pdcto[4].price=11.35;
    pdcto[4].cantStock=DEFAULT_P5;

    do
    {
        flag=0;
        printf("\t\tG R O C E R Y     S T O R E\n\n");
        printf("- - - - - - - - - - - - -\n");
        printf("\tMain Menu\n\n");
        printf("- - - - - - - - - - - - -\n");
        printf("1.-Show articles\n");
        printf("- - - - - - - - - - - - -\n");
        printf("2.-Start Sell\n");
        printf("- - - - - - - - - - - - -\n");
        printf("3.-View Storage\n");
        printf("- - - - - - - - - - - - -\n");
        printf("4.-Close Store\n");
        printf("- - - - - - - - - - - - -\n");
        printf("5.-Exit\n\n\n opc?:");

        scanf("%d",&opc);
        clear_screen();


        switch(opc)
        {

        case 1:
            printf("\tS h o w     A r t i c l e s\n");
            for(i=0; i<LIMIT_STORE_SIZE; i++)
            {
                printf("- - - - - - - - - - - - - - - \n");
                printf("\tPRODUCT # %d\n",i+1);
                printf("Name: %s \n",pdcto[i].name);
                printf("Desc: %s \n",pdcto[i].desc);
                printf("Price: %.2f \n",pdcto[i].price);
                printf("- - - - - - - - - - - - - - - \n");
            }
            clear_screen();
            break;
        case 2:
            flag=0;
            do
            {
                printf("S t o r e   S e l l   I n i t\n\n");

                for(i=0; i<LIMIT_STORE_SIZE; i++)//LIST PRODUCT PRINT ---------------------------
                {
                    printf("- - - - - - - - - - - - - - - \n");
                    printf("\tPRODUCT # %d\n",i+1);
                    printf("Name: %s \n",pdcto[i].name);
                    printf("Desc: %s \n",pdcto[i].desc);
                    printf("Price: %.2f \n",pdcto[i].price);
                    printf("Stock: %d\n",pdcto[i].cantStock);
                    printf("- - - - - - - - - - - - - - - \n");
                }
                printf("- - - - - - - - - - - - - - - \n");
                printf("\tYou can buy this max. of products - > %d\n",globalStock);
                printf("- - - - - - - - - - - - - - - \n");

                printf("Num. of product to add to Ticket ?\n:");
                scanf("%d",&numProduct);
                numProduct--;


                if(numProduct >= 0 && numProduct < LIMIT_STORE_SIZE)
                {

                    cantProduct=0;
                    limitSellProduct=pdcto[numProduct].cantStock;
                    printf("How much?\n of -> %s <-\n",pdcto[numProduct].name);
                    printf("Available = %d\n:",pdcto[numProduct].cantStock);
                    scanf("%d",&cantProduct);

                    if (cantProduct>0 && cantProduct<=limitSellProduct)
                    {
                        printf("Your are select %s and you",pdcto[numProduct].name);
                        printf("choice  buy %d\n",cantProduct);
                        //FINAL PART !!
                        clear_screen();
                        flag=1;
                        break;

                    }
                    else printf("Error, entry no valid !\n");
                    clear_screen();


                }// IF TO CONTROL NUM OF PRODUCTS ITS OK------------------------------------------

                else printf("ERROR X !!! \n Try Again...!!!\n");
                clear_screen();
                flag=0;

            }
            while(flag!=1);
            break;

        case 3:
            printf("\tS h o w     S t o r a g e\n\n");
            for(i=0; i<LIMIT_STORE_SIZE; i++)
            {
                printf("- - - - - - - - - - - - - - - \n");
                printf("\tPRODUCT # %d\n",i);
                printf("Name: %s \n",pdcto[i].name);
                printf("Desc: %s \n",pdcto[i].desc);
                printf("Stock: %d \n",pdcto[i].cantStock);
                printf("- - - - - - - - - - - - - - - \n");
            }
            clear_screen();

            break;
        case 4 :
            printf("C l o s i n g     S t o r e \n\n");
            printf("The storage are reset to default values\n");

            int i = 0;
            printf("- - - - - - - - - - - - - - - \n");
            printf("\tPRODUCT # %d\n",i+1);
            printf("Name: %s \n",pdcto[i].name);
            printf("Desc: %s \n",pdcto[i].desc);
            printf("Stock Final: %d \n",pdcto[i].cantStock);
            printf("RESET STOCK TO - - - > %d in Stock\n",DEFAULT_P1);
            printf("- - - - - - - - - - - - - - - \n");

            i++;
            printf("- - - - - - - - - - - - - - - \n");
            printf("\tPRODUCT # %d\n",i+1);
            printf("Name: %s \n",pdcto[i].name);
            printf("Desc: %s \n",pdcto[i].desc);
            printf("Stock Final: %d \n",pdcto[i].cantStock);
            printf("RESET STOCK TO - - - > %d in Stock\n",DEFAULT_P2);
            printf("- - - - - - - - - - - - - - - \n");

            i++;
            printf("- - - - - - - - - - - - - - - \n");
            printf("\tPRODUCT # %d\n",i+1);
            printf("Name: %s \n",pdcto[i].name);
            printf("Desc: %s \n",pdcto[i].desc);
            printf("Stock Final: %d \n",pdcto[i].cantStock);
            printf("RESET STOCK TO - - - > %d in Stock\n",DEFAULT_P3);
            printf("- - - - - - - - - - - - - - - \n");

            i++;
            printf("- - - - - - - - - - - - - - - \n");
            printf("\tPRODUCT # %d\n",i+1);
            printf("Name: %s \n",pdcto[i].name);
            printf("Desc: %s \n",pdcto[i].desc);
            printf("Stock Final: %d \n",pdcto[i].cantStock);
            printf("RESET STOCK TO - - - > %d in Stock\n",DEFAULT_P4);
            printf("- - - - - - - - - - - - - - - \n");

            i++;
            printf("- - - - - - - - - - - - - - - \n");
            printf("\tPRODUCT # %d\n",i+1);
            printf("Name: %s \n",pdcto[i].name);
            printf("Desc: %s \n",pdcto[i].desc);
            printf("Stock Final: %d \n",pdcto[i].cantStock);
            printf("RESET STOCK TO - - - > %d in Stock\n",DEFAULT_P5);
            printf("- - - - - - - - - - - - - - - \n");
            clear_screen();

            break;
        case 5 :
            flag=1;
            printf("C l o s i n g   s t o r e,   b y e !\n");
            clear_screen();
            break;

        default:
            printf("An ocurred a problem, try again !\n");
            clear_screen();
            flag=0;
            break;
        }

    }
    while(flag!=1);

    return 0;
}
