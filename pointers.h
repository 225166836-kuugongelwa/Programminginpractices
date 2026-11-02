/* pointers.h - Week 12: functions that use pointers and arrays */
#ifndef POINTERS_H
#define POINTERS_H

#include "records.h"

/* Part B: swap two salaries by address */
void swapSalaries(double *a, double *b);

/* Part C: functions that receive an array (the address of its first box).
   n is the number of items, because the function cannot know the length. */
void displaySalaries(const double salaries[], int n);
double findHighest(const double salaries[], int n);
double calculateAverage(const double salaries[], int n);
void giveRaise(double salaries[], int n, double percent);

/* Part D: functions that receive a pointer to a structure */
void updateSalary(Employee *e, double newSalary);

/* Returns the ADDRESS of the matching employee, or NULL if not found. */
Employee *findEmployee(Employee list[], int n, int id);

#endif
