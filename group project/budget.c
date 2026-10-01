/* 
   BUDGET.C
   Owner: Student 2 sevelina kuugongelwa (Budget Management)

   Handles entering departmental budgets and expenditure,
   calculating what's left, and flagging departments that have
   gone over budget.
    */

#include <stdio.h>
#include <string.h>
#include "budget.h"

// Sub-menu: called from main.c //
void budgetMenu(Budget budgets[], int *budgetCount) {
    int choice;
    printf("\n-- Budget Management --\n");
    printf("1. Enter Budget\n2. Enter Expenditure\n3. Display Budget Status\n4. Back\n");
    choice = readIntInRange("Enter your choice: ", 1, 4);

    switch (choice) {
        case 1: enterBudget(budgets, budgetCount); break;
        case 2: enterExpenditure(budgets, *budgetCount); break;
        case 3: displayBudgetStatus(budgets, *budgetCount); break;
        default: break;
    }
 }

// Add a new department's allocated budget //
    void enterBudget(Budget budgets[], int *budgetCount) {
    char deptName[DEPT_LEN];
    double allocated;

    if (*budgetCount >= MAX_DEPARTMENTS) {
        printf("Cannot add more departments. Budget list is full.\n");
        return;
       }

    printf("Enter department name: ");
    fgets(deptName, DEPT_LEN, stdin);
    deptName[strcspn(deptName, "\n")] = '\0'; //strip trailing newline //

    if (!isNonEmptyString(deptName)) {
        printf("Department name cannot be empty.\n");
        return;
       }

    // Prevent duplicate department entries //
    for (int i = 0; i < *budgetCount; i++) {
        if (strcmp(budgets[i].department, deptName) == 0) {
            printf("That department already has a budget entry. Use option 2 to add expenditure instead.\n");
            return;
          }
     }

    printf("Enter allocated budget (N$): ");
    scanf("%lf", &allocated);
    while (getchar() != '\n'); /* clear leftover newline from scanf */

    if (!isPositiveNumber(allocated)) {
        printf("Allocated budget cannot be negative.\n");
        return;
       }

     strcpy(budgets[*budgetCount].department, deptName);
   budgets[*budgetCount].allocatedBudget = allocated;
     budgets[*budgetCount].expenditure = 0.0;
     (*budgetCount)++;

    printf("Budget added for %s.\n", deptName);
}

// Record expenditure against an existing department //
void enterExpenditure(Budget budgets[], int budgetCount) {
 char deptName[DEPT_LEN];
  double amount;
  int found = 0;

    if (budgetCount == 0) {
        printf("No departments have a budget yet. Use option 1 first.\n");
        return;
    }

    printf("Enter department name: ");
    fgets(deptName, DEPT_LEN, stdin);
    deptName[strcspn(deptName, "\n")] = '\0';

    for (int i = 0; i < budgetCount; i++) {
        if (strcmp(budgets[i].department, deptName) == 0) {
            printf("Enter expenditure amount (N$): ");
            scanf("%lf", &amount);
            while (getchar() != '\n');

            if (!isPositiveNumber(amount)) {
                printf("Expenditure cannot be negative.\n");
                return;
            }

            budgets[i].expenditure += amount;
            found = 1;

            printf("Expenditure recorded for %s.\n", budgets[i].department);
            if (strcmp(checkBudgetStatus(budgets[i]), "EXCEEDED") == 0) {
                printf("WARNING: %s has now EXCEEDED its allocated budget!\n", budgets[i].department);
            }
            break;
    }
     }

    if (!found) {
        printf("Department not found. Use option 1 to add it first.\n");
    }
}

/* ---------- Remaining budget = allocated - expenditure ---------- */
double calculateRemainingBudget(Budget b) {
    return b.allocatedBudget - b.expenditure;
}

/* ---------- WITHIN BUDGET or EXCEEDED ---------- */
const char *checkBudgetStatus(Budget b) {
    if (b.expenditure > b.allocatedBudget) {
        return "EXCEEDED";
    }
    return "WITHIN BUDGET";
}

/* ---------- Display every department, flagging those over budget ---------- */
void displayBudgetStatus(Budget budgets[], int budgetCount) {
    if (budgetCount == 0) {
      printf("No budget records to display.\n");
        return;
    }

    printf("\n%-20s %15s %15s %15s %15s\n",
           "Department", "Allocated", "Expenditure", "Remaining", "Status");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < budgetCount; i++) {
        double remaining = calculateRemainingBudget(budgets[i]);
        printf("%-20s %15.2f %15.2f %15.2f %15s\n",
        budgets[i].department,
       budgets[i].allocatedBudget,
      budgets[i].expenditure,
     remaining,
    checkBudgetStatus(budgets[i]));
    }

    printf("\nDepartments that have EXCEEDED their budget:\n");
    int noneExceeded = 1;
    for (int i = 0; i < budgetCount; i++) {
        if (strcmp(checkBudgetStatus(budgets[i]), "EXCEEDED") == 0) {
            printf(" - %s\n", budgets[i].department);
            noneExceeded = 0;
        }
    }
    if (noneExceeded) {
        printf(" - None. All departments are within budget.\n");
    }
}
