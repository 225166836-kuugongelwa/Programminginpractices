
//Save Employees (Text)//


#include <stdio.h>

void loadEmployees(void) {
    FILE *fp = fopen("data/employees.txt", "r");
    int id; char name[50]; double salary;
    if (fp == NULL) {
        perror("data/employees.txt");
        return;
    }
 

