void BillingWindow(int totalamt, order data[], int size){

    // clear the screen 
    system("clear");
    
    //Information to print in the bill
    char FirstName[20];
	char LastName[20];

    printf("\n\n\n");
	printf("Please Give Your Name \n");
	printf(" First Name : ");
	scanf("%s",FirstName);
	printf(" Last Name  : ");
	scanf("%s",LastName);
	printf("\n\n");
 

    int count;
    // clears the screen again
    system("clear");
    
    

    // formatting of the bill 
    printf("\t \t \t \t \t Kathmandu University\n");
    printf("______________________________________________________________________________________________________________________________\n");

    printf("Canteen Management System\n");
    printf("\n");
    printf("Name: %s %s\n",FirstName, LastName);

    // prints date and time
    time_t rawtime;
    struct tm *info;
    time( &rawtime );
    info = localtime( &rawtime );
    printf("Current local time and date: %s", asctime(info));
    printf("\n");
    printf("______________________________________________________________________________________________________________________________\n");
    printf("S.N \t \t \t Order \t \t \t Rate(in Rs.) \t \t \t Quantity \t \t \t Amount(in Rs.)\n");
    printf("______________________________________________________________________________________________________________________________\n");
    printf("\n");
    // end of formatting

    
    // Main bill-printing
    int counter = 0;
    while (counter <= size && strcmp(data[counter].food, "null")){
        printf("%2d", counter+1);
        printf("%32s", data[counter].food);
        printf("%19.2d", data[counter].Rate);
        printf("%32d", data[counter].Quantity);
        amount[counter]= (float)data[counter].Rate * data[counter].Quantity;
        printf("%38.2f", amount[counter]);
        printf("\n");
        counter+=1;
    }
    for (int i=0; i<=size;i++){
        final_amount += amount[i];
    }

    printf("\n");
    printf("\t \t \t \t \t \t \t \t \tTotal amount:  %19.2f\n",final_amount);
    exit(0);
}
