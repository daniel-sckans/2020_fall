
#include <stdlib.h>
#include <stdio.h>

#define LOOP for (int i = 0; i < 10; i++){
#define LOOP_END }
#define MAIN_LOOP while(1){
#define MAIN_LOOP_END }

#define menu "************************************\nWelome to my interactive menu\n************************************\n"
#define print_menu printf(menu)

#define NEXTLINE "\n"
#define NEWLINE printf(NEXTLINE)


int main(int argc, char** argv)
{


    int choice; 
    char ch;
    char name[50];

    double pricePurchase;
    float rate_of_tax = .065;

    int speedLimit;
    int driverSpeed;
    int doubleSpeedLimit = speedLimit * 2;



    /*printf("************************************\n");
    printf("Welome to my interactive menu\n");
    printf("************************************\n");*/

    print_menu;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Hello %s welcome to my program.\n", name);

    //printf("press enter to continue\n");
    //scanf("%c",&ch);


    MAIN_LOOP
        //printf("Enter name: ");
        //scanf("%s", name);
        //printf("Hello %s welcome to my program.", name);
        //printf("\n");
        NEWLINE;
        printf("1: Print hello your name 10 times.\n");
        printf("2: Total Sale Calculator\n");
        printf("3: Ticket Calculator\n");
        printf("4: Choose for a Suprise\n");
        printf("5: Exit Program.\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 5)
        {
            NEWLINE;
            printf("Invaild option\n");
        }

        //printf("\n");
        NEWLINE;
        

        switch(choice)
        {
            case 1:
                LOOP
                    printf("Hello, %s!\n", name);
                LOOP_END
                break;
            case 2:
                
                printf("Enter price of item: ");
                scanf("%lf", &pricePurchase);

                printf("Total amount is $%lf", pricePurchase * (1 + rate_of_tax));
                NEWLINE;
                
                break;

            case 3:

                printf("What was the posted speed limit: ");
                scanf("%d", &speedLimit);

                printf("Enter the drive speed: ");
                scanf("%d", &driverSpeed);

                NEWLINE;

                if(driverSpeed <= speedLimit)
                {
                    printf("No offense, driver's speed is legal");
                    NEWLINE;
                }
                else if(driverSpeed > speedLimit || driverSpeed > doubleSpeedLimit)
                {
                    printf("Your fine will be $%d .", 90 + (driverSpeed - speedLimit) * 5);
                    NEWLINE;
                }
                else if(driverSpeed > speedLimit)
                {
                    printf("Your fine will be $%d .", (driverSpeed - speedLimit) * 5);
                    NEWLINE;
                }
                else
                {
                    printf("Your fine will be $%d .", 90 + (driverSpeed - speedLimit) * 5);
                    NEWLINE;
                }
                break;

            case 4:

                printf("Happy birthday to you! \n");
                printf("Happy birthday to you! \n");
                printf("Happy birthday dear %s! \n", name);
                printf("Happy birthday to you! \n");
                NEWLINE;
                
                break;

            case 5:
                printf("Thank you for using my program!\n");
                exit(0);

        }
    MAIN_LOOP_END
    



    return EXIT_SUCCESS;
}
