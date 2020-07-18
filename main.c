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
    float cant;
};

int main()
{
    int opc,opc2,i,flagMain,flag2,flag3,globalStock,numProduct;
    int limitSellProduct,numbOfArticlesToTicket;
    float totalTicket,cantProduct =0;
    globalStock=DEFAULT_P1+DEFAULT_P2+DEFAULT_P3+DEFAULT_P4+DEFAULT_P5;
    struct Product pdcto[LIMIT_STORE_SIZE];
    struct Ticket ticket[globalStock];

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
        flagMain=0;
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
//----------------------TICKET MENU MAKE ---------------------------------------------------------
            flag2=0;
            do
            {
                printf("S e l l   I n i t\n");
                printf("- - - - - - - - - - - - -\n\n");
                printf("- - - - - - - - - - - - -\n");
                printf("1.-Add products to ticket\n");
                printf("- - - - - - - - - - - - -\n");
                printf("2.-View current ticket\n");
                printf("- - - - - - - - - - - - -\n");
                printf("3.-Close ticket\n");
                printf("- - - - - - - - - - - - -\n");
                printf("4.-Exit to main menu\n");
                printf("- - - - - - - - - - - - -\n");
                printf("0.-Reset ticket to 0 products\n\n\n opc?:");
                scanf("%d",&opc2);
                clear_screen();

                switch (opc2)
                {
                case 0:
                    for (i=0 ; i<numbOfArticlesToTicket ; i++)
                    {
                        ticket[i].name ="empty";
                        ticket[i].desc ="empty";
                        ticket[i].priceUnit=0;
                        ticket[i].priceTotal=0;
                        ticket[i].cant=0;
                    }
                    printf("R E S T O R E  - - - -  C O M P L E T E \n");
                    clear_screen();

//              ----------------------------------------------------------RESTORE ALL TICKET------
                    break;
                case 1:

                    printf("T i c k e t   I n i t\n\n");
                    printf("- - - - - - - - - - - - - - - \n");
//                  printf("\tYou can buy this max. of products - > %d\n",globalStock);
                    printf("Number of articles to selling ?\n");
                    scanf("%d",&numbOfArticlesToTicket); //PENDING VALIDATE RANGE-------------!!!!
                    //INIT TICKET DEFAULT-----------------------------------------------------
                    for (i=0 ; i<numbOfArticlesToTicket ; i++)
                    {
                        ticket[i].name ="empty";
                        ticket[i].desc ="empty";
                        ticket[i].priceUnit=0;
                        ticket[i].priceTotal=0;
                        ticket[i].cant=0;
                    }
                    //INIT TICKET DEFAULT-----------------------------------------------------
                    flag3=0;
                    while (flag3<numbOfArticlesToTicket)
                    {
                        printf("P R O D U C T   AVAILABLE\n\n");
                        for(i=0; i<LIMIT_STORE_SIZE; i++)//LIST PRODUCT PRINT --------------------
                        {
                            printf("\n- - - - - - - - - - - - - - - \n");
                            printf("\tPRODUCT # %d\n",i+1);
                            printf("Name: %s \n",pdcto[i].name);
                            printf("Desc: %s \n",pdcto[i].desc);
                            printf("Price: %.2f \n",pdcto[i].price);
                            printf("Stock: %d\n",pdcto[i].cantStock);
                            printf("- - - - - - - - - - - - - - - \n");
                        }
                        printf("\n- - - - - - - - - - - - - - - \n");
                        printf("Num. of product to select and add to ticket ?\n:");
                        scanf("%d",&numProduct);
                        numProduct--;

                        if(numProduct >= 0 && numProduct < LIMIT_STORE_SIZE)
                        {
                            limitSellProduct=pdcto[numProduct].cantStock;

                            printf("\nHow much?\n of -> %s <-\n",pdcto[numProduct].name);
                            printf("Available = %d\n:",pdcto[numProduct].cantStock);
                            scanf("%f",&cantProduct);

                            if (cantProduct>0 && cantProduct<=limitSellProduct)
                            {
                                printf("\nYour are select %s and you",pdcto[numProduct].name);
                                printf("choice  buy %.2f\n",cantProduct);
                                printf("Price unit ->%.2f\n",pdcto[numProduct].price);


                                ticket[flag3].name = pdcto[numProduct].name;
                                ticket[flag3].desc = pdcto[numProduct].desc;
                                ticket[flag3].cant = cantProduct;
                                ticket[flag3].priceUnit = pdcto[numProduct].price;
                                ticket[flag3].priceTotal = pdcto[numProduct].price*cantProduct;
                                totalTicket+=ticket[flag3].priceTotal;

                            }
                            else
                                printf("Error, entry no valid !\n");
                            clear_screen();
                        }// IF TO CONTROL NUM OF PRODUCTS ITS OK---------------------------------

                        else
                        {
                            printf("ERROR X !!! \n Try Again...!!!\n");
                            clear_screen();
                            flag2=0;
                        }
                        flag3++;
                    } //WHILE TO CONTROL TICKET WRITE---------------------------------------------

                    clear_screen();
                    flag2=0;
                    break;

                case 2:
                    printf("V i e w    c u r r e n t    t i c k e t \n");
                    printf("- - - - - - - - - - - - - - - \n\n");
//Show current ticket-----------------------------------------------------------------------------
                    for(i=0; i<numbOfArticlesToTicket; i++)
                    {
                        printf("- - - - - - - - - - - - - - - \n");
                        printf("Product: %s\n",ticket[i].name);
                        printf("Description: %s\n",ticket[i].desc);
                        printf("Quantity : %.2f\n",ticket[i].cant);
                        printf("Unit price : %2.f\n",ticket[i].priceUnit);
                        printf("Total : %2.f\n",ticket[i].priceTotal);
                        printf("- - - - - - - - - - - - - - - \n");
                    }
                    system("pause");
                    clear_screen();
                    break;

                case 3:
//                  ---------------------------------------------------C l o s i n g   t i c k e t
                    printf("- - - - - - - - - - - - - - - \n");
                    printf("\tC l o s i n g   t i c k e t !!\n");
                    printf("- - - - - - - - - - - - - - - \n\n");
                    printf("Total products -> %d", numbOfArticlesToTicket);
                    printf("- - - - - - - - - - - - - - - \n");
                    printf("Total Price -> %.2f",totalTicket);
                    printf("- - - - - - - - - - - - - - - \n");
                    printf("* * * T i c k e t * * *\n\n");

                    for(i=0; i<numbOfArticlesToTicket; i++)
                    {
                        printf("- - - - - - - - - - - - - - - \n");
                        printf("Product: %s\n",ticket[i].name);
                        printf("Description: %s\n",ticket[i].desc);
                        printf("Quantity : %.2f\n",ticket[i].cant);
                        printf("Unit price : %2.f\n",ticket[i].priceUnit);
                        printf("Total : %2.f\n",ticket[i].priceTotal);
                        printf("- - - - - - - - - - - - - - - \n");
                    }
                    break;

                case 4:
                    printf("Closing ticket menu...\n");
                    clear_screen();
                    flag2=1;
                    break;
                default:
                    printf("* * *ERROR X !!! , Try again.!! * * * \n\n");
                    clear_screen();
                    break;

                }

            }

            while(flag2!=1);
            break;
//------------------------------------------------F I N I S H _ _ _ _ _  T I C K E T_ _ _ _P A R T
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
            flagMain=1;
            printf("C l o s i n g   s t o r e,   b y e !\n");
            clear_screen();
            break;

        default:
            printf("An ocurred a problem, try again !\n");
            clear_screen();
            flagMain=0;
            break;
        }

    }
    while(flagMain!=1);

    return 0;
}