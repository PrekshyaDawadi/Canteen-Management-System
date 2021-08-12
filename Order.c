int BreakfastTakeOrder( int totalamt, int totalqty, order data[], int size)
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
        strcpy(data[BillCounter].food,"Coffee ");
        data[BillCounter].Rate = 20;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;


        break;

        case 2:
        c=b*15;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Tea ");
        data[BillCounter].Rate = 15;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 3:
        c=b*25;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Milk ");
        data[BillCounter].Rate = 25;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 4:
        c=b*30;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Orange Juice ");
        data[BillCounter].Rate = 30;
        data[BillCounter].Quantity = totalqty;;
        BillCounter += 1;
        break;

        case 5:
        c=b*40;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Egg Sandwich ");
        data[BillCounter].Rate = 40;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 6:
        c=b*30;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Veg Sandwich ");
        data[BillCounter].Rate = 30;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 7:
        c=b*20;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Doughnut ");
        data[BillCounter].Rate = 20;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 8:
        c=b*30;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Toasted Bread ");
        data[BillCounter].Rate = 30;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 9:
        c=b*35;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Bread and Butter ");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        BreakfastTakeOrder(totalamt,totalqty, data, size); 
    }

    printf("\nDo you want to order again?\n\n  Enter 1 for YES     0 for NO.\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            BreakfastTakeOrder(totalamt,totalqty,data, size);
        }
        else if(e == 0)
        {
            printf("Your total amount from breakfast is: %d",totalamt);
            system("clear");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(totalamt, data, size);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

int LunchTakeOrder(int totalamt,int totalqty, order data[], int size)
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
        strcpy(data[BillCounter].food,"Veg Rice Set");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 2:
        c=b*120;
        totalamt= totalamt+c;
        totalqty= totalqty+b;
        strcpy(data[BillCounter].food,"Chicken Rice Set");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        LunchTakeOrder(totalamt,totalqty, data, size);
    }

    printf("\nDo you want to order again?\n\n  Enter 1 for YES     0 for NO.\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            LunchTakeOrder(totalamt,totalqty, data, size);
        }
        else if(e == 0)
        {
            printf("Your total amount from lunch is: %d",totalamt);
            system("clear");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(totalamt, data, size);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

int SnacksTakeOrder(int totalamt,int totalqty, order data[], int size)
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
        strcpy(data[BillCounter].food,"Wai Wai Fried Noodles");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 2:
        c=b*40;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Veg Chowmein");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 3:
        c=b*60;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food,"Chicken Chowmein");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 4:
        c=b*100;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food , "Mini-mixed pizza");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 5:
        c=b*100;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food ,"Buff Mo:mo");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 6:
        c=b*70;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food , "Coke");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 7:
        c=b*70;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food , "Sprite");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 8:
        c=b*70;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food , "Fanta");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 9:
        c=b*150;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food , "Iced peach tea");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 10:
        c=b*120;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food, "Lemonade");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        SnacksTakeOrder(totalamt,totalqty, data, size);
    }

    printf("\nDo you want to order again?\n\n  Enter 1 for YES     0 for NO.\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            SnacksTakeOrder(totalamt,totalqty, data, size);
        }
        else if(e == 0)
        {
            printf("Your total amount is: %d",totalamt);
            system("clear");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(totalamt, data, size);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}

int DinnerTakeOrder(int totalamt,int totalqty, order data[], int size)
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
        strcpy(data[BillCounter].food , "Veg Rice Set");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        case 2:
        c=b*120;
        totalamt=totalamt+c;
        totalqty=totalqty+b;
        strcpy(data[BillCounter].food , "Chicken Rice Set");
        data[BillCounter].Rate = 35;
        data[BillCounter].Quantity = totalqty;
        BillCounter += 1;
        break;

        default:
        printf("\t\t\tEnter the correct choice please!!!!\n");
        DinnerTakeOrder(totalamt,totalqty, data, size);
    }

    printf("\nDo you want to order again?\n\n  Enter 1 for YES     0 for NO.\n\n");
    scanf("%d",&e);

        if(e == 1)
        {
            DinnerTakeOrder(totalamt,totalqty, data, size);
        }
        else if(e == 0)
        {
            printf("Your total amount is: %d",totalamt);
            system("clear");
            printf("Press any key to continue");
            if(getch());
            BillingWindow(totalamt,data, size);
        }
        else
        {
            exit(0);
        }

    return totalqty;
}