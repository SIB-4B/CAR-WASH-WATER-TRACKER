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