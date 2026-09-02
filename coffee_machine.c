#include <stdio.h>
#include <time.h>

int main()
{
    // ==========================================
    // COFFEE MACHINE - COMPLETE SIMULATION
    // ==========================================

    // ----------- MACHINE INVENTORY ------------
    int coffee = 1000;       // grams
    int milk = 5000;         // ml
    int sugar = 1000;        // grams
    int water = 10000;       // ml
    int cups = 50;           // cups

    // ----------- SALES INFORMATION ------------
    int totalCupsSold = 0;
    int totalRevenue = 0;
    int billNumber = 1001;

    int mainChoice;

    while (1)
    {
        printf("\n\n");
        printf("===============================================\n");
        printf("          AUTOMATIC COFFEE MACHINE\n");
        printf("===============================================\n");

        printf("\n1. Buy Coffee\n");
        printf("2. Check Machine Stock\n");
        printf("3. Refill Machine\n");
        printf("4. Cleaning Mode\n");
        printf("5. End of Day Report\n");
        printf("6. Shutdown Machine\n");

        printf("\nEnter your choice: ");
        scanf("%d", &mainChoice);

        // =================================================
        // 1. BUY COFFEE
        // =================================================

        if (mainChoice == 1)
        {
            int coffeeChoice;
            int quantity;

            printf("\n-----------------------------------------------\n");
            printf("                COFFEE MENU\n");
            printf("-----------------------------------------------\n");

            printf("1. Black Coffee   - Rs. 30\n");
            printf("2. Milk Coffee    - Rs. 40\n");
            printf("3. Cappuccino     - Rs. 60\n");
            printf("4. Latte          - Rs. 70\n");

            printf("\nSelect Coffee: ");
            scanf("%d", &coffeeChoice);

            if (coffeeChoice < 1 || coffeeChoice > 4)
            {
                printf("\nInvalid coffee choice!\n");
                continue;
            }

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("\nInvalid quantity!\n");
                continue;
            }

            // ---------------------------------------------
            // INGREDIENT REQUIREMENTS
            // ---------------------------------------------

            int requiredCoffee = 0;
            int requiredMilk = 0;
            int requiredSugar = 0;
            int requiredWater = 0;
            int price = 0;

            if (coffeeChoice == 1)
            {
                // Black Coffee
                requiredCoffee = 15 * quantity;
                requiredWater = 150 * quantity;
                price = 30 * quantity;
            }

            else if (coffeeChoice == 2)
            {
                // Milk Coffee
                requiredCoffee = 15 * quantity;
                requiredMilk = 100 * quantity;
                requiredSugar = 10 * quantity;
                requiredWater = 50 * quantity;
                price = 40 * quantity;
            }

            else if (coffeeChoice == 3)
            {
                // Cappuccino
                requiredCoffee = 15 * quantity;
                requiredMilk = 150 * quantity;
                requiredSugar = 10 * quantity;
                price = 60 * quantity;
            }

            else if (coffeeChoice == 4)
            {
                // Latte
                requiredCoffee = 15 * quantity;
                requiredMilk = 200 * quantity;
                requiredSugar = 10 * quantity;
                price = 70 * quantity;
            }

            // ---------------------------------------------
            // CHECK STOCK
            // ---------------------------------------------

            if (coffee < requiredCoffee)
            {
                printf("\nERROR: Not enough coffee powder!\n");
                continue;
            }

            if (milk < requiredMilk)
            {
                printf("\nERROR: Not enough milk!\n");
                continue;
            }

            if (sugar < requiredSugar)
            {
                printf("\nERROR: Not enough sugar!\n");
                continue;
            }

            if (water < requiredWater)
            {
                printf("\nERROR: Not enough water!\n");
                continue;
            }

            if (cups < quantity)
            {
                printf("\nERROR: Not enough cups!\n");
                continue;
            }

            // ---------------------------------------------
            // DISPLAY ORDER
            // ---------------------------------------------

            printf("\n-----------------------------------------------\n");
            printf("                ORDER DETAILS\n");
            printf("-----------------------------------------------\n");

            if (coffeeChoice == 1)
                printf("Coffee       : Black Coffee\n");
            else if (coffeeChoice == 2)
                printf("Coffee       : Milk Coffee\n");
            else if (coffeeChoice == 3)
                printf("Coffee       : Cappuccino\n");
            else if (coffeeChoice == 4)
                printf("Coffee       : Latte\n");

            printf("Quantity     : %d\n", quantity);
            printf("Total Price  : Rs. %d\n", price);

            // ---------------------------------------------
            // PAYMENT
            // ---------------------------------------------

            int insertedMoney = 0;
            int note;

            printf("\n-----------------------------------------------\n");
            printf("              PAYMENT SYSTEM\n");
            printf("-----------------------------------------------\n");

            printf("Accepted: Rs.10, Rs.20, Rs.50, Rs.100,\n");
            printf("          Rs.200, Rs.500\n");

            printf("\nEnter 0 to cancel payment.\n");

            while (insertedMoney < price)
            {
                printf("\nAmount inserted: Rs. %d\n", insertedMoney);

                printf("Insert note/coin: Rs. ");
                scanf("%d", &note);

                if (note == 0)
                {
                    printf("\nTransaction cancelled.\n");
                    printf("Refund: Rs. %d\n", insertedMoney);
                    insertedMoney = 0;
                    break;
                }

                if (note == 10 || note == 20 ||
                    note == 50 || note == 100 ||
                    note == 200 || note == 500)
                {
                    insertedMoney = insertedMoney + note;
                    printf("Accepted: Rs. %d\n", note);
                }
                else
                {
                    printf("Invalid denomination!\n");
                }
            }

            if (insertedMoney == 0)
            {
                continue;
            }

            // ---------------------------------------------
            // CHANGE
            // ---------------------------------------------

            int change = insertedMoney - price;

            printf("\nPayment successful!\n");
            printf("Total paid : Rs. %d\n", insertedMoney);
            printf("Change     : Rs. %d\n", change);

            // ---------------------------------------------
            // COFFEE PREPARATION
            // ---------------------------------------------

            printf("\n===============================================\n");
            printf("             COFFEE PREPARATION\n");
            printf("===============================================\n");

            printf("\nStep 1: Taking cup...\n");
            printf("Step 2: Grinding coffee beans...\n");
            printf("Step 3: Measuring coffee powder...\n");
            printf("Step 4: Heating water...\n");

            if (requiredMilk > 0)
            {
                printf("Step 5: Heating milk...\n");
            }

            printf("Step 6: Adding coffee...\n");

            if (requiredMilk > 0)
            {
                printf("Step 7: Adding milk...\n");
            }

            if (requiredSugar > 0)
            {
                printf("Step 8: Adding sugar...\n");
            }

            printf("Step 9: Mixing ingredients...\n");
            printf("Step 10: Brewing coffee...\n");
            printf("Step 11: Filling cup...\n");
            printf("Step 12: Dispensing coffee...\n");

            printf("\n-----------------------------------------------\n");
            printf("       YOUR COFFEE IS READY!\n");
            printf("       Please collect your cup.\n");
            printf("-----------------------------------------------\n");

            // ---------------------------------------------
            // REMOVE INGREDIENTS FROM STOCK
            // ---------------------------------------------

            coffee = coffee - requiredCoffee;
            milk = milk - requiredMilk;
            sugar = sugar - requiredSugar;
            water = water - requiredWater;
            cups = cups - quantity;

            // ---------------------------------------------
            // SALES UPDATE
            // ---------------------------------------------

            totalCupsSold = totalCupsSold + quantity;
            totalRevenue = totalRevenue + price;

            // ---------------------------------------------
            // BILL
            // ---------------------------------------------

            printf("\n\n");
            printf("===============================================\n");
            printf("                  BILL\n");
            printf("===============================================\n");

            printf("Bill Number  : %d\n", billNumber);

            if (coffeeChoice == 1)
                printf("Item         : Black Coffee\n");
            else if (coffeeChoice == 2)
                printf("Item         : Milk Coffee\n");
            else if (coffeeChoice == 3)
                printf("Item         : Cappuccino\n");
            else if (coffeeChoice == 4)
                printf("Item         : Latte\n");

            printf("Quantity     : %d\n", quantity);
            printf("Price        : Rs. %d\n", price);
            printf("Paid         : Rs. %d\n", insertedMoney);
            printf("Change       : Rs. %d\n", change);

            printf("-----------------------------------------------\n");
            printf("        THANK YOU FOR YOUR ORDER!\n");
            printf("===============================================\n");

            billNumber++;

            // ---------------------------------------------
            // LOW STOCK WARNING
            // ---------------------------------------------

            printf("\nMachine Status:\n");

            if (coffee < 100)
                printf("WARNING: Coffee powder is LOW!\n");

            if (milk < 500)
                printf("WARNING: Milk is LOW!\n");

            if (sugar < 100)
                printf("WARNING: Sugar is LOW!\n");

            if (water < 1000)
                printf("WARNING: Water is LOW!\n");

            if (cups < 5)
                printf("WARNING: Cups are LOW!\n");
        }

        // =================================================
        // 2. CHECK STOCK
        // =================================================

        else if (mainChoice == 2)
        {
            printf("\n===============================================\n");
            printf("              MACHINE STOCK\n");
            printf("===============================================\n");

            printf("Coffee Powder : %d g\n", coffee);
            printf("Milk          : %d ml\n", milk);
            printf("Sugar         : %d g\n", sugar);
            printf("Water         : %d ml\n", water);
            printf("Cups          : %d\n", cups);

            printf("\n-----------------------------------------------\n");

            if (coffee < 100)
                printf("Coffee: LOW\n");
            else
                printf("Coffee: OK\n");

            if (milk < 500)
                printf("Milk: LOW\n");
            else
                printf("Milk: OK\n");

            if (sugar < 100)
                printf("Sugar: LOW\n");
            else
                printf("Sugar: OK\n");

            if (water < 1000)
                printf("Water: LOW\n");
            else
                printf("Water: OK\n");

            if (cups < 5)
                printf("Cups: LOW\n");
            else
                printf("Cups: OK\n");
        }

        // =================================================
        // 3. REFILL MACHINE
        // =================================================

        else if (mainChoice == 3)
        {
            int refillChoice;
            int amount;

            printf("\n===============================================\n");
            printf("                REFILL MODE\n");
            printf("===============================================\n");

            printf("1. Coffee Powder\n");
            printf("2. Milk\n");
            printf("3. Sugar\n");
            printf("4. Water\n");
            printf("5. Cups\n");

            printf("\nSelect item: ");
            scanf("%d", &refillChoice);

            printf("Enter amount to add: ");
            scanf("%d", &amount);

            if (amount <= 0)
            {
                printf("Invalid amount!\n");
                continue;
            }

            if (refillChoice == 1)
            {
                coffee = coffee + amount;
                printf("Coffee powder refilled.\n");
            }

            else if (refillChoice == 2)
            {
                milk = milk + amount;
                printf("Milk refilled.\n");
            }

            else if (refillChoice == 3)
            {
                sugar = sugar + amount;
                printf("Sugar refilled.\n");
            }

            else if (refillChoice == 4)
            {
                water = water + amount;
                printf("Water refilled.\n");
            }

            else if (refillChoice == 5)
            {
                cups = cups + amount;
                printf("Cups refilled.\n");
            }

            else
            {
                printf("Invalid refill choice!\n");
            }
        }

        // =================================================
        // 4. CLEANING MODE
        // =================================================

        else if (mainChoice == 4)
        {
            printf("\n===============================================\n");
            printf("               CLEANING MODE\n");
            printf("===============================================\n");

            printf("Cleaning coffee nozzle...\n");
            printf("Cleaning milk pipe...\n");
            printf("Cleaning mixing chamber...\n");
            printf("Cleaning cup dispenser...\n");
            printf("Flushing water system...\n");
            printf("Removing leftover coffee...\n");

            printf("\nCleaning completed successfully.\n");
        }

        // =================================================
        // 5. END OF DAY REPORT
        // =================================================

        else if (mainChoice == 5)
        {
            printf("\n===============================================\n");
            printf("             END OF DAY REPORT\n");
            printf("===============================================\n");

            printf("Total Cups Sold : %d\n", totalCupsSold);
            printf("Total Revenue   : Rs. %d\n", totalRevenue);
            printf("Last Bill No.   : %d\n", billNumber - 1);

            printf("\nRemaining Stock:\n");
            printf("Coffee          : %d g\n", coffee);
            printf("Milk            : %d ml\n", milk);
            printf("Sugar           : %d g\n", sugar);
            printf("Water           : %d ml\n", water);
            printf("Cups            : %d\n", cups);

            printf("===============================================\n");
        }

        // =================================================
        // 6. SHUTDOWN
        // =================================================

        else if (mainChoice == 6)
        {
            printf("\n===============================================\n");
            printf("          SHUTTING DOWN MACHINE...\n");
            printf("===============================================\n");

            printf("Saving sales information...\n");
            printf("Checking machine status...\n");
            printf("Closing valves...\n");
            printf("Turning off heater...\n");
            printf("Machine shutdown complete.\n");

            break;
        }

        else
        {
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

