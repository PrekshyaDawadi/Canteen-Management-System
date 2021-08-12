// libraries to include
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

//Files to include
#include screens.c
#include Menu.c 
#include Order.c 
#include BillPrinting.c 


//array to store orders (required for BillingWindow's use)
typedef struct{
    char food[20];
    int Rate;
    int Quantity;
} order;


// global variable initializations
int size = 50;
order data[50];
int BillCounter = 0;
float final_amount = 0;
float amount[50];


// Functions initializations 
void MainScreen(void);
void GoBackToMainScreen(void);

void CanteenMgmt(void);
void DisplayMenu(void);
void AboutUs(void);



void TakeOrder(void);
int BreakfastTakeOrder(int,int, order array[], int);
int LunchTakeOrder(int, int, order array[], int);
int SnacksTakeOrder(int, int, order array[], int);
int DinnerTakeOrder(int, int, order array[], int);

void BillingWindow(int, order array[], int);




//Start of the main program
int main()
{
    // Order initialization 
    int i;
    for (int i=0; i<=50; i++){
        strcpy(data[i].food, "null");
    }
    MainScreen();
}