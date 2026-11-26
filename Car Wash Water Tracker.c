#include <stdio.h>
int main()
{
    const int BASIC_LIMIT = 40;
    const int FULL_LIMIT = 60;
    const int PREMIUM_LIMIT = 100;

    int targetLimits[3] = {BASIC_LIMIT, FULL_LIMIT, PREMIUM_LIMIT};
    int categoryCars[3] = {0, 0, 0};
    int categoryTargetTotal[3] = {0, 0, 0};
    int categoryActualWater[3] = {0, 0, 0};
    int categoryExcessWater[3] = {0, 0, 0};

    int totalCarsWashed = 0;
    int totalWaterUsed = 0;
    int totalExcessWater = 0;

    int menuChoice = 0;
    while (menuChoice != 3)
    {
        printf("\n========================================\n");
        printf(" CAR WASH WATER TRACKER\n");
        printf("========================================\n");
        printf("1. Record a Car Wash\n");
        printf("2. View End-of-Day Report\n");
        printf("3. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &menuChoice) != 1)
        {
            while (getchar() != '\n')
            {
                
            }
            printf("\nInvalid input. Please enter a number between 1 and 3.\n");
            continue;
        }

        if (menuChoice == 1)
        {
            int serviceChoice = 0;
            int categoryIndex = 0;
            int targetLimit = 0;
            int actualWater = 0;
            int excessWater = 0;

            printf("\n--- RECORD A CAR WASH ---\n");
            printf("1. Basic Wash (Target Limit: %d L)\n", BASIC_LIMIT);
            printf("2. Full Wash (Target Limit: %d L)\n", FULL_LIMIT);
            printf("3. Premium Wash (Target Limit: %d L)\n", PREMIUM_LIMIT);
            printf("Pick a wash service (1-3): ");

            if (scanf("%d", &serviceChoice) != 1 || serviceChoice < 1 || serviceChoice > 3)
            {
                while (getchar() != '\n')
                {
    
                }
                printf("\nInvalid wash service choice. Returning to main menu.\n");
                continue;
            }

            categoryIndex = serviceChoice - 1;
            targetLimit = targetLimits[categoryIndex];

            printf("\nWash Service : ");
            if (serviceChoice == 1)
            {
                printf("Basic Wash\n");
            }
            else if (serviceChoice == 2)
            {
                printf("Full Wash\n");
            }
            else
            {
                printf("Premium Wash\n");
            }

            printf("Target Limit : %d L\n", targetLimit);
            printf("Enter actual water used (in liters): ");

            if (scanf("%d", &actualWater) != 1 || actualWater < 0)
            {
                while (getchar() != '\n')
                {
                  
                }
                printf("\nInvalid water amount. Returning to main menu.\n");
                continue;
            }

            if (actualWater > targetLimit)
            {
                excessWater = actualWater - targetLimit;
                printf("Excess Water Used : %d L\n", excessWater);
                printf("ALERT: Water usage exceeded the target limit by %d L!\n", excessWater);
            }
            else
            {
                excessWater = 0;
                printf("Excess Water Used : 0 L\n");
                printf("Status: Water usage is within the target limit.\n");
            }

            categoryCars[categoryIndex] = categoryCars[categoryIndex] + 1;
            categoryTargetTotal[categoryIndex] = categoryTargetTotal[categoryIndex] + targetLimit;
            categoryActualWater[categoryIndex] = categoryActualWater[categoryIndex] + actualWater;
            categoryExcessWater[categoryIndex] = categoryExcessWater[categoryIndex] + excessWater;

            totalCarsWashed = totalCarsWashed + 1;
            totalWaterUsed = totalWaterUsed + actualWater;
            totalExcessWater = totalExcessWater + excessWater;

            printf("\nCar wash record saved! (Total cars logged today: %d)\n", totalCarsWashed);
        }
        else if (menuChoice == 2)
        {
            int i = 0;

            printf("\n=====================================================================\n");
            printf(" END-OF-DAY REPORT\n");
            printf("=====================================================================\n");
            printf("%-14s %-14s %-14s %-15s %-14s\n",
                   "Wash Service",
                   "Cars Washed",
                   "Target Limit",
                   "Actual Water",
                   "Excess Water");
            printf("---------------------------------------------------------------------\n");

            for (i = 0; i < 3; i++)
            {
                if (i == 0)
                {
                    printf("%-14s ", "Basic");
                }
                else if (i == 1)
                {
                    printf("%-14s ", "Full");
                }
                else
                {
                    printf("%-14s ", "Premium");
                }

                printf("%-14d %-14d %-15d %-14d\n",
                       categoryCars[i],
                       categoryTargetTotal[i],
                       categoryActualWater[i],
                       categoryExcessWater[i]);
            }

            printf("---------------------------------------------------------------------\n");
            printf("OVERALL SUMMARY:\n");
            printf(" Total Cars Washed : %d\n", totalCarsWashed);
            printf(" Total Water Used : %d L\n", totalWaterUsed);
            printf(" Excess Water Used : %d L\n", totalExcessWater);
            printf("=====================================================================\n");
        }
        else if (menuChoice == 3)
        {
            printf("\nExiting Car Wash Water Tracker. Goodbye!\n");
        }
        else
        {
            printf("\nInvalid choice. Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}
