#include <stdio.h>

int main() {
    float basicSalary;
    float housing;
    float transport;
    float tax;
    float grossSalary;
    float netSalary;

    // Input section
    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    // Calculations
    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    // Output section
    printf("\n-------------------------------\n");
    printf("Employee Salary Report\n");
    printf("-------------------------------\n");
    printf("Gross Salary : %.2f\n", grossSalary);
    printf("Net Salary   : %.2f\n", netSalary);
    printf("-------------------------------\n");

    return 0;
}

