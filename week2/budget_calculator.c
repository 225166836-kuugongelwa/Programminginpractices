
#include <stdio.h>

int main() {

    // --- Core exercise variables ---
    double revenue;
    double expenses;
    double balance;

    // --- Extension exercise variables ---
    int departments;
    double payroll;
    double procurement;
    double assets;

    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("---------------------------\n");

    // Get core financial data
    printf("Enter total revenue: ");
    scanf("%lf", &revenue);

    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    balance = revenue - expenses;

    // Get extension data
    printf("\nEnter number of departments: ");
    scanf("%d", &departments);

    printf("Enter total payroll: ");
    scanf("%lf", &payroll);

    printf("Enter total procurement cost: ");
    scanf("%lf", &procurement);

    printf("Enter total asset value: ");
    scanf("%lf", &assets);

    // --- Output: core results ---
    printf("\nRevenue: %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance: %.2f\n", balance);

    // --- Output: extension summary ---
    printf("\nMUNICIPAL FINANCIAL SUMMARY\n");
    printf("----------------------------\n");
    printf("Departments: %d\n", departments);
    printf("Payroll: %.2f\n", payroll);
    printf("Procurement: %.2f\n", procurement);
    printf("Assets: %.2f\n", assets);

    return 0;
}
