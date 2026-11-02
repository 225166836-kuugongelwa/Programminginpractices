/* pointers.c - Week 12: swap, array functions and employee updates */
#include <stdio.h>
#include "pointers.h"

/* ---------- Part B: swap by address ---------- */

void swapSalaries(double *a, double *b)
{
    double temp = *a;   /* go to the first address and keep the value safe */
    *a = *b;            /* copy the second value into the first box */
    *b = temp;          /* put the saved value into the second box */
}

/* ---------- Part C: arrays are passed by address ---------- */

void displaySalaries(const double salaries[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("  Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

double findHighest(const double salaries[], int n)
{
    double highest = salaries[0];
    int i;

    for (i = 1; i < n; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
    }
    return highest;
}

double calculateAverage(const double salaries[], int n)
{
    double total = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        total += salaries[i];
    }
    return total / n;
}

/* No const here: this function is allowed to change the ORIGINAL array. */
void giveRaise(double salaries[], int n, double percent)
{
    int i;

    for (i = 0; i < n; i++) {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

/* ---------- Part D: pointers to structures ---------- */

void updateSalary(Employee *e, double newSalary)
{
    e->salary = newSalary;      /* arrow operator: go to e, then take salary */
}

Employee *findEmployee(Employee list[], int n, int id)
{
    int i;

    for (i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i];    /* the address of the matching record */
        }
    }
    return NULL;                /* not found */
}
