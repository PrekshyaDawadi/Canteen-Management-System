#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

void MainScreen(void);
void GoBackToMainScreen(void);

void CanteenMgmt(void);
void DisplayMenu(void);
void AboutUs(void);

void TakeOrder(void);
int BreakfastTakeOrder(int, int);
int LunchTakeOrder(int, int);
int SnacksTakeOrder(int, int);
int DinnerTakeOrder(int, int);

int BillingWindow(int,int);
char order[20][20];
int qt[20];

int main()
{
    MainScreen();
}

void MainScreen()
{
    system("cls");
    printf("___________________________________________________________________________________________________________________\n");
    printf("                                       Welcome to KU Canteen System\n\n");
    printf("\t\t\t\t\t1. Canteen Management Section\n");
    printf("\t\t\t\t\t2. Customer Section\n");
    printf("\t\t\t\t\t3. About Us\n");
    printf("\t\t\t\t\t4. Exit\n");
    printf("___________________________________________________________________________________________________________________\n");

    int select;
    printf("\n\nEnter your selected option: ");
    scanf("%d",&select);


    switch(select)
    {
        case 1:
        CanteenMgmt();
        break;

        case 2:
        DisplayMenu();
        break;

        case 3:
        AboutUs();
        break;

        case 4:
        system("cls"); 
        printf("_________________________________________________________________________________________________________________________\n");
        printf("\t\t\t\t\t\t\tFEELING HUNGRY ?\n");
        printf("\t\t\t\t\t\t\tYOU CAN PLACE YOUR ORDER NOW!\n");
        printf("\t\t\t\t\t\t\tTHANK YOU. VISIT AGAIN\n");
        printf("_________________________________________________________________________________________________________________________\n");

        GoBackToMainScreen();
        break;

        default:
        printf("YOU ENTERED AN INVALID KEY!");
    }  

    exit(0);
}
void GoBackToMainScreen()
{
    int value;

    printf("\n\nDo you wish to go back to the main screen ? \n\n 1 for Yes \t 2 for No.\n");
    scanf("%d",&value);

    if(value == 1)
    {
        MainScreen();
    }
    else if(value == 0)
    {
        exit(0);
    }
    exit(0);
}


void CanteenMgmt()
{
    system("cls");
    printf("\n\nCANTEEN MANAGEMENT SECTION\n\n");
    char ans[100];
    int value;

    printf("\nCANTEEN RULES, every students must abide by:\n\n");
    printf("1. Only KU students are allowed in this canteen.\n");
    printf("2. Foods are available according to the time slot. The menu you order from depends on the time you place your order.\n");
    printf("For instance, you can only order from the breakfast section in the morning. \n");
    printf("3. Only Cash Allowed to order the food in the canteen.\n");
    printf("4. Please maintain silence in the canteen.\n\n");

    printf("    Press Any Key");
    if(getch());
    GoBackToMainScreen();

    exit(0);
}

void DisplayMenu()
{
    int *totalamt=0;
    int totalqty=0;

    system("cls");
    int select;
    int Total;
    printf("\n\nCUSTOMER SECTION\n\n");
    
    printf("\nThe Menu Bar according to the Time slot:\n\n");
    printf("1. Breakfast        -> 7:00 AM - 9:30 AM \n2. Lunch            -> 10:00 PM - 12:00 PM  \n3. Snacks           -> 1:30 PM - 4:00 PM   \n4. Dinner           -> 5:00 PM - 7:30 PM \n\n");

    time_t *t;
    time(&*t);
    printf("\tTime : %s\n\n", ctime(&*t) );
    printf("Please Enter According to the real time: ");
    scanf("%d",&select);

    system("cls");

    if(select == 1)
    {
        printf("\nMENU FOR BREAKFAST\n\n");
        printf(" Breakfast       Rate\n\n\n1. Coffee           Rs.20\n2. Tea              Rs.15\n3. Milk             Rs.25\n4. Orange Juice     Rs.30\n5. Egg Sandwich     Rs.40\n6. Veg Sandwich     Rs.30\n7. Doughnut         Rs.20\n8. Toasted Bread    Rs.30\n9. Bread and Butter Rs.35\n\n");
        BreakfastTakeOrder(*totalamt,totalqty);
        
    }
    else if(select == 2)
    {
        printf("\nMENU FOR LUNCH\n\n");
        printf("   Lunch          Rate\n1. Veg Rice Set       Rs.60\n2. Chicken Rice Set   Rs.120\n\n\n");
        Total = LunchTakeOrder(*totalamt,totalqty);
        //BillingWindow(Total);
    }
    else if(select == 3)
    {
        printf("\nMENU FOR SNACKS AND DRINKS\n\n");
        printf("   Snacks              Rate\n1. Waiwai Fried noodles    Rs.40\n2. Veg Chowmein            Rs.40\n3. Chicken Chowmein        Rs.60\n4. Mini Mixed Pizza        Rs.100\n5. Buff Momo               Rs.100\n6. Coke-300ml              Rs.70\n7. Sprite-300ml            Rs.70\n8. Fanta-300ml             Rs.70\n9. Iced peach tea          Rs.150\n10. Lemonade                Rs.120\n\n");         
        SnacksTakeOrder(*totalamt,totalqty);
        //BillingWindow(Total);
    }
    else
    {
        printf("\nMENU FOR DINNERr\n\n ");
        printf("   Dinner         Rate\n1. Veg Rice Set       Rs.60\n2. Chicken Rice Set   Rs.120\n\n");
        DinnerTakeOrder(*totalamt,totalqty);
        //BillingWindow(Total);
    }
    exit(0);
}

void AboutUs()
{
    system("cls");
	printf("PEOPLE BEHIND THIS PROJECT :\n\n   -->Sampada Deoju\n\n   -->Prekshya Dawadi\n\n   -->Prasiddhi Dahal\n\n   -->Barsha Devkota\n\n   -->Dilasha Upadhyaya\n\n");
	printf("\n\n");
    printf("*****************************THANK YOU*****************************");
	printf("\n\n\t\t\tPress Any Key ");
	if(getch());
    GoBackToMainScreen();
    
}

int BreakfastTakeOrder(int *totalamt,int totalqty)
{
    int a,b,c,e=1;
    int amt,qty;

    printf("Enter your choice\n");
    scanf("%d",&a);
    printf("Enter the quantity\n");
    scanf("%d",&b);
    
    switch(a)
    {
        case 1:
        c=b*20;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Coffee ");
        intcpy(*qt, b);

        break;

        case 2:
        c=b*15;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Tea ");
        break;

        case 3:
        c=b*25;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Milk ");
        break;

        case 4:
        c=b*30;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Orange Juice ");
        break;

        case 5:
        c=b*40;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Egg Sandwich ");
        break;

        case 6:
        c=b*30;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Veg Sandwich ");
        break;

        case 7:
        c=b*20;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Doughnut ");
        break;

        case 8:
        c=b*30;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Toasted Bread ");
        break;

        case 9:
        c=b*35;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Bread and Butter ");
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        BreakfastTakeOrder(*totalamt,totalqty); 
    }

    printf("\nDo you want to order again?\n\n  YES for 1     NO for 0?\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            BreakfastTakeOrder(*totalamt,totalqty);
        }
        else if(e == 0)
        {
            printf("Your total amount from breakfast is: %d",*totalamt);
            system("cls");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(*totalamt,totalqty);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

int LunchTakeOrder(int *totalamt,int totalqty)
{
    int a,b,c,e=1;
   
    printf("Enter your choice\n");
    scanf("%d",&a);
    printf("Enter the quantity\n");
    scanf("%d",&b);
    
    switch(a)
    {
        case 1:
        c=b*60;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Veg Rice Set ");
        break;

        case 2:
        c=b*120;
        *totalamt= *totalamt+c;
        totalqty= totalqty+b;
        strcpy(*order, "Chicken Rice Set ");
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        LunchTakeOrder(*totalamt,totalqty);
    }

    printf("\nDo you want to order again?\n\n  YES for 1     NO for 0?\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            LunchTakeOrder(*totalamt,totalqty);
        }
        else if(e == 0)
        {
            printf("Your total amount from lunch is: %d",*totalamt);
            system("cls");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(*totalamt,totalqty);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

int SnacksTakeOrder(int *totalamt,int totalqty)
{
    int a,b,c,e=1;

    printf("Enter your choice\n");
    scanf("%d",&a);
    printf("Enter the quantity\n");
    scanf("%d",&b);
    
    switch(a)
    {
        case 1:
        c=b*40;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Wai Wai Fried Noodles ");
        break;

        case 2:
        c=b*40;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Veg Chowmin ");
        break;

        case 3:
        c=b*60;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Chicken Chowmin ");
        break;

        case 4:
        c=b*100;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Mini Mixed Pizza ");
        break;

        case 5:
        c=b*100;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Buff Mo:Mo ");
        break;

        case 6:
        c=b*70;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Coke ");
        break;

        case 7:
        c=b*70;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Sprite ");
        break;

        case 8:
        c=b*70;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Fanta ");
        break;

        case 9:
        c=b*150;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Iced peach tea ");
        break;

        case 10:
        c=b*120;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Lemonade ");
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        SnacksTakeOrder(*totalamt,*totalqty);
    }

    printf("\nDo you want to order again?\n\n  YES for 1     NO for 0?\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            SnacksTakeOrder(*totalamt,*totalqty);
        }
        else if(e == 0)
        {
            printf("Your total amount is: %d",*totalamt);
            system("cls");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(*totalamt,totalqty);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

int DinnerTakeOrder(int *totalamt,int *totalqty)
{
    int a,b,c,e=1;

    printf("Enter your choice\n");
    scanf("%d",&a);
    printf("Enter the quantity\n");
    scanf("%d",&b);
    
    switch(a)
    {
        case 1:
        c=b*60;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Veg Rice Set ");
        break;

        case 2:
        c=b*120;
        *totalamt=*totalamt+c;
        totalqty=totalqty+b;
        strcpy(*order, "Chicken Rice Set ");
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        DinnerTakeOrder(*totalamt,totalqty);
    }

    printf("\nDo you want to order again?\n\n  YES for 1     NO for 0?\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            DinnerTakeOrder(*totalamt,totalqty);
        }
        else if(e == 0)
        {
            printf("Your total amount is: %d",*totalamt);
            system("cls");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(*totalamt,totalqty);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

