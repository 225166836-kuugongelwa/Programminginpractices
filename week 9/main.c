#include <stdio.h>
#include "employees.h"
#include "budget.h"

int main(void) {
    printf("Municipal Financial Management System\n");
    addEmployee();
    listEmployees();
    printf("Budget Balance: %.2f\n", calculateBudget(500000,350000));
    return 0;
}
