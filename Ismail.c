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
                /* Clear invalid non-numeric input */
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
                    /* Clear invalid input */
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
                    /* Clear invalid input */
                }
                printf("\nInvalid water amount. Returning to main menu.\n");
                continue;
            }

            /* Compare actual water against target limit */
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

            /* Update category records */
            categoryCars[categoryIndex] = categoryCars[categoryIndex] + 1;
            categoryTargetTotal[categoryIndex] = categoryTargetTotal[categoryIndex] + targetLimit;
            categoryActualWater[categoryIndex] = categoryActualWater[categoryIndex] + actualWater;
            categoryExcessWater[categoryIndex] = categoryExcessWater[categoryIndex] + excessWater;

            /* Update overall daily counters */
            totalCarsWashed = totalCarsWashed + 1;
            totalWaterUsed = totalWaterUsed + actualWater;
            totalExcessWater = totalExcessWater + excessWater;

            printf("\nCar wash record saved! (Total cars logged today: %d)\n", totalCarsWashed);
        }