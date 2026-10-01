#ifndef BUDGET_H
#define BUDGET_H

#include "common.h"

// Student 2: Budget Management//

void budgetMenu(Budget budgets[], int *budgetCount);

void enterBudget(Budget budgets[], int *budgetCount);
void enterExpenditure(Budget budgets[], int budgetCount);
double calculateRemainingBudget(Budget b);
const char *checkBudgetStatus(Budget b);
void displayBudgetStatus(Budget budgets[], int budgetCount);

#endif // BUDGET_H //
