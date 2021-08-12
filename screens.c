void MainScreen()
{
    system("clear");
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
        system("clear"); 
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
    system("clear");
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
