/* pointer_demo.c - Week 12 lab, Parts A to D as a small test program.
   Build: gcc -std=c99 -Wall -Wextra -pedantic pointer_demo.c pointers.c records.c -o pointer_demo */
#include <stdio.h>
#include "pointers.h"

/* The WRONG version (Part B, task 4): plain double parameters get COPIES,
   so the originals in main() never change. */
static void swapWrong(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    /* ---------- Part A: a pointer to an int ---------- */
    int age = 25;
    int *p = &age;

    printf("=== Part A: pointer warm-up ===\n");
    printf("age   = %d\n", age);
    printf("&age  = %p\n", (void *)&age);
    printf("p     = %p (same address)\n", (void *)p);
    printf("*p    = %d (the value at that address)\n", *p);

    *p = 30;                       /* go to the address and change the value */
    printf("After *p = 30: age = %d, *p = %d\n", age, *p);

    {
        int *q = NULL;             /* points to nothing yet */
        if (q == NULL) {
            printf("q is NULL, so it is NOT safe to use *q.\n");
        }
    }

    /* ---------- Part B: swap salaries ---------- */
    {
        double salaryA = 18500.50;
        double salaryB = 21000.75;

        printf("\n=== Part B: swap salaries ===\n");
        printf("Before:          A = %.2f, B = %.2f\n", salaryA, salaryB);

        swapWrong(salaryA, salaryB);
        printf("After swapWrong: A = %.2f, B = %.2f  (nothing changed)\n", salaryA, salaryB);

        swapSalaries(&salaryA, &salaryB);
        printf("After swapSalaries: A = %.2f, B = %.2f  (swapped!)\n", salaryA, salaryB);
    }

    /* ---------- Part C: arrays and functions ---------- */
    {
        double salaries[4] = {15000.00, 18500.50, 21000.75, 17200.00};

        printf("\n=== Part C: arrays passed to functions ===\n");
        printf("Salaries before the raise:\n");
        displaySalaries(salaries, 4);
        printf("Highest salary: N$%.2f\n", findHighest(salaries, 4));
        printf("Average salary: N$%.2f\n", calculateAverage(salaries, 4));

        giveRaise(salaries, 4, 10.0);
        printf("\nSalaries after a 10%% raise (the ORIGINAL array changed):\n");
        displaySalaries(salaries, 4);
        printf("New average salary: N$%.2f\n", calculateAverage(salaries, 4));
    }

    /* ---------- Part D: modify employee records ---------- */
    {
        Employee staff[3] = {
            {1001, "Maria", "Finance", 18500.50},
            {1002, "Simon", "Roads",   17200.00},
            {1003, "Anna",  "Water",   21000.75}
        };
        Employee *found;

        printf("\n=== Part D: update employee records ===\n");

        /* Test 1: employee FOUND and updated */
        found = findEmployee(staff, 3, 1002);
        if (found != NULL) {
            updateSalary(found, 19000.00);
            printf("Test 1 (found): %s now earns N$%.2f\n", found->name, found->salary);
        }

        /* Test 2: employee NOT FOUND */
        found = findEmployee(staff, 3, 9999);
        if (found != NULL) {
            updateSalary(found, 1.00);
        } else {
            printf("Test 2 (not found): no employee with ID 9999.\n");
        }

        /* Test 3: the same employee updated TWICE */
        found = findEmployee(staff, 3, 1003);
        if (found != NULL) {
            updateSalary(found, 22000.00);
            printf("Test 3 (first update):  %s now earns N$%.2f\n", found->name, found->salary);
            updateSalary(found, 23500.00);
            printf("Test 3 (second update): %s now earns N$%.2f\n", found->name, found->salary);
        }

        /* Proof that the ORIGINAL array changed */
        printf("\nFinal records in the array:\n");
        displayEmployees(staff, 3);
    }

    return 0;
}
