#include <stdio.h>

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

void displayMenu() {
        printf("\nMUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("1. Calculate VAT\n");
         printf("2. Calculate Salary\n");
         printf("3. Calculate Budget\n");
         printf("4. Exit\n");
        printf("Enter choice: ");
     }

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            float amount;
            printf("Enter amount: ");
            scanf("%f", &amount);
            printf("VAT: %.2f\n", calculateVAT(amount));
        } else if (choice == 2) {
            float b,h,t;
                  printf("Enter basic, housing, transport: ");
                scanf("%f %f %f", &b,&h,&t);
            printf("Gross Salary: %.2f\n", calculateSalary(b,h,t));
} else if (choice == 3) {
            float r,e;
                   printf("Enter revenue and expenses: ");
            scanf("%f %f", &r,&e);
                printf("Budget Balance: %.2f\n", calculateBudget(r,e));
            }
    } while (choice != 4);

    return 0;
}
