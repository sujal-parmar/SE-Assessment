#include <stdio.h>
#include <string.h>

int main() {
    int foodID, quantity;
    char choice;
    float totalBill = 0.0;
    float price = 0.0;
    char name[40];

    // Menu data (arrays)
    int ids[] = {1, 2, 3, 4, 5, 6, 7};
    char names[][40] = {
        "Chocolate Foudue", 
        "Oreo Waffle", 
        "Choco Surprise Bomb", 
        "Smoking Brownie", 
        "Hawana Club", 
        "Hot Chocolate", 
        "Choco Lava"
    };
    float prices[] = {370.0, 220.0, 650.0, 470.0, 530.0, 300.0, 450.0};
    int size = sizeof(ids) / sizeof(ids[0]);

    printf("******** Welcome to Food Billing System ********\n");

    do {
        // Display menu
        printf("\n===== Available Food Items =====\n");
        for (int i = 0; i < size; i = i + 1) {
            printf("%d. %-20s ₹ %.2f\n", ids[i], names[i], prices[i]);
        }
        printf("================================\n");

        // Take food order
        printf("Enter the food item number you want to order: ");
        scanf("%d", &foodID);

        // Search for ID
        int found = 0;
        for (int i = 0; i < size; i = i + 1) {
            if (ids[i] == foodID) { // Relational operator
                strcpy(name, names[i]); // Assignment
                price = prices[i];      // Assignment
                found = 1;              // Assignment
            }
        }

        // If valid ID
        if (found == 1) {
            printf("Enter quantity for %s: ", name);
            scanf("%d", &quantity);

            float subtotal = price * quantity;  // Arithmetic
            totalBill = totalBill + subtotal;   // Arithmetic + assignment

            printf("You added %d x %s (₹ %.2f each) = ₹ %.2f to your bill.\n",
                   quantity, name, price, subtotal);
        } else {
            printf("Invalid item selected. Please try again.\n");
        }

        // Ask for continuation
        printf("Do you want to order more items? (y/n): ");
        scanf(" %c", &choice);  // space before %c to consume newline

    } while (choice == 'y' || choice == 'Y'); // Logical and relational operators

    // Final bill
    printf("\n******** Final Bill ********\n");
    printf("Total Amount to Pay: ₹ %.2f\n", totalBill);   
    printf("Thank you for your order!\nVisit again.\n");

    return 0;
}
