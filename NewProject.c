#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
// Functions, identifiers and data_type initializations 
void MainScreen(void);
void GoBackToMainScreen(void);

void CanteenMgmt(void);
void DisplayMenu(void);
void AboutUs(void);


//array to store orders (required for BillingWindow's use)
typedef struct{
    char food[20];
    int Rate;
    int Quantity;
} order;

order data[20];

void TakeOrder(void);
int BreakfastTakeOrder(int, int, order);
int LunchTakeOrder(int, int, order);
int SnacksTakeOrder(int, int, order);
int DinnerTakeOrder(int, int, order);

void BillingWindow(int, time_t, order);




//Start of the main program
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
    int totalamt=0;
    int totalqty=0;

    system("cls");
    int select;
    int Total;
    printf("\n\nCUSTOMER SECTION\n\n");
    
    printf("\nThe Menu Bar according to the Time slot:\n\n");
    printf("1. Breakfast        -> 7:00 AM - 9:30 AM \n2. Lunch            -> 10:00 PM - 12:00 PM  \n3. Snacks           -> 1:30 PM - 4:00 PM   \n4. Dinner           -> 5:00 PM - 7:30 PM \n\n");

    time_t t;
    time(&t);
    printf("\tTime : %s\n\n", ctime(&t) );
    printf("Please Enter According to the real time: ");
    scanf("%d",&select);

    system("cls");

    if(select == 1)
    {
        printf("\nMENU FOR BREAKFAST\n\n");
        printf(" Breakfast       Rate\n\n\n1. Coffee           Rs.20\n2. Tea              Rs.15\n3. Milk             Rs.25\n4. Orange Juice     Rs.30\n5. Egg Sandwich     Rs.40\n6. Veg Sandwich     Rs.30\n7. Doughnut         Rs.20\n8. Toasted Bread    Rs.30\n9. Bread and Butter Rs.35\n\n");
        BreakfastTakeOrder(totalamt,totalqty, data[20]);
        BillingWindow(totalamt, t, data[20]);
        
    }
    else if(select == 2)
    {
        printf("\nMENU FOR LUNCH\n\n");
        printf("   Lunch          Rate\n1. Veg Rice Set       Rs.60\n2. Chicken Rice Set   Rs.120\n\n\n");
        Total = LunchTakeOrder(totalamt,totalqty, data[20]);
        BillingWindow(totalamt,t, data[20]);
    }
    else if(select == 3)
    {
        printf("\nMENU FOR SNACKS AND DRINKS\n\n");
        printf("   Snacks              Rate\n1. Waiwai Fried noodles    Rs.40\n2. Veg Chowmein            Rs.40\n3. Chicken Chowmein        Rs.60\n4. Mini Mixed Pizza        Rs.100\n5. Buff Momo               Rs.100\n6. Coke-300ml              Rs.70\n7. Sprite-300ml            Rs.70\n8. Fanta-300ml             Rs.70\n9. Iced peach tea          Rs.150\n10. Lemonade                Rs.120\n\n");         
        SnacksTakeOrder(totalamt,totalqty, data[20]);
        BillingWindow(totalamt,  t,  data[20]);
    }
    else
    {
        printf("\nMENU FOR DINNERr\n\n ");
        printf("   Dinner         Rate\n1. Veg Rice Set       Rs.60\n2. Chicken Rice Set   Rs.120\n\n");
        DinnerTakeOrder(totalamt,totalqty, data[20]);
        BillingWindow( totalamt,  t, data[20]);
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

int BreakfastTakeOrder(int totalamt,int totalqty, order data[20])
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
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Coffee ");
        data[a].Rate = 20;
        data[a].Quantity = totalqty;


        break;

        case 2:
        c=b*15;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Tea ");
        data[a].Rate = 15;
        data[a].Quantity = totalqty;
        break;

        case 3:
        c=b*25;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Milk ");
        data[a].Rate = 25;
        data[a].Quantity = totalqty;
        break;

        case 4:
        c=b*30;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Orange Juice ");
        data[a].Rate = 30;
        data[a].Quantity = totalqty;;
        break;

        case 5:
        c=b*40;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Egg Sandwich ");
        data[a].Rate = 40;
        data[a].Quantity = totalqty;
        break;

        case 6:
        c=b*30;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Veg Sandwich ");
        data[a].Rate = 30;
        data[a].Quantity = totalqty;
        break;

        case 7:
        c=b*20;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Doughnut ");
        data[a].Rate = 20;
        data[a].Quantity = totalqty;
        break;

        case 8:
        c=b*30;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Toasted Bread ");
        data[a].Rate = 30;
        data[a].Quantity = totalqty;
        break;

        case 9:
        c=b*35;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        BreakfastTakeOrder(totalamt,totalqty, data[20]); 
    }

    printf("\nDo you want to order again?\n\n  YES for 1     NO for 0?\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            BreakfastTakeOrder(totalamt,totalqty,data[20]);
        }
        else if(e == 0)
        {
            printf("Your total amount from breakfast is: %d",totalamt);
            system("cls");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(totalamt, t,  data[20]);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

int LunchTakeOrder(int totalamt,int totalqty, order data[20])
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
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 2:
        c=b*120;
        totalamt= totalamt+c;
        totalqty= totalqty+b;
        strcpy(data[a].food,"Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        LunchTakeOrder(totalamt,totalqty, data[20]);
    }

    printf("\nDo you want to order again?\n\n  YES for 1     NO for 0?\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            LunchTakeOrder(totalamt,totalqty, data[20]);
        }
        else if(e == 0)
        {
            printf("Your total amount from lunch is: %d",totalamt);
            system("cls");
            printf("Press any key to continue");
            //if(getch());
            BillingWindow(totalamt, t,  data[20]);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

int SnacksTakeOrder(int totalamt,int totalqty, order data[20])
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
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 2:
        c=b*40;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 3:
        c=b*60;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food,"Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 4:
        c=b*100;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food , "Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 5:
        c=b*100;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food ,"Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 6:
        c=b*70;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food , "Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 7:
        c=b*70;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food , "Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 8:
        c=b*70;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food , "Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 9:
        c=b*150;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food , "Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 10:
        c=b*120;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food, "Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        SnacksTakeOrder(totalamt,totalqty, data[20]);
    }

    printf("\nDo you want to order again?\n\n  YES for 1     NO for 0?\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            SnacksTakeOrder(totalamt,totalqty, data[20]);
        }
        else if(e == 0)
        {
            printf("Your total amount is: %d",totalamt);
            system("cls");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(totalamt, t, data[20]);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

int DinnerTakeOrder(int totalamt,int totalqty, order data[20])
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
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food , "Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        case 2:
        c=b*120;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[a].food , "Bread and Butter ");
        data[a].Rate = 35;
        data[a].Quantity = totalqty;
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        DinnerTakeOrder(totalamt,totalqty), data[20]);
    }

    printf("\nDo you want to order again?\n\n  YES for 1     NO for 0?\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            DinnerTakeOrder(totalamt,totalqty, data[20]);
        }
        else if(e == 0)
        {
            printf("Your total amount is: %d",totalamt);
            system("cls");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(totalamt,  t,  data[20]);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}
void BillingWindow(int totalamt, time_t t, order data[20]){
    // clear the screen 
    system("clear");
    
    //Information to print in the bill
    char FirstName[20], LastName[20];
    printf("Please Enter you name in format <FirstName><space><LastName>: ");
    scanf("%s %s", &FirstName, &LastName);
    //date
    typedef struct {
        int day;
        int month;
        int year;
    } Date;
    Date today;
    today.day = 27;
    today.month = 07;
    today.year = 2021;

    int count;
    // clears the screen again
    system("clear")

    // formatting of the bill 
    printf("\t \t \t \t \t Kathmandu University\n");
    printf("______________________________________________________________________________________________________________________________\n");

    printf("Canteen Management System\n");
    printf("\n");
    printf("Name: %s %s\n",FirstName, LastName);
    printf("Date: %d-%d-%d\n", today.day, today.month, today.year);
    printf("Time of printing the bill: %f\n", t);
    printf("\n");
    printf("______________________________________________________________________________________________________________________________\n");
    printf("S.N \t \t \t Order \t \t \t Rate(in Rs.) \t \t \t Quantity \t \t \t Amount(in Rs.)\n");
    printf("______________________________________________________________________________________________________________________________\n");
    printf("\n");
    // end of formatting

    
    // Main bill-printing
    int counter = 0;
    for (counter=1; counter <= NumberOfOrders; counter++){
        printf("%2d", counter);
        printf("%32s", data[counter].food);
        printf("%19.2f", data[counter].Rate);
        printf("%32d", data[counter].Quantity);
        printf("%38.2f", (float)data[counter].Rate * data[counter].Quantity);
        printf("\n");
    }
    printf("\n");
    printf("\t \t \t \t \t \t \t \t \tTotal amount payable:  %19.2d\n",totalamt);
    exit(0);
}
