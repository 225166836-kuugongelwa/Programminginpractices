//Binary Save/Load//

#include <stdio.h>

void loadEmployees(void) {
    FILE *fp = fopen("data/employees.txt", "r");
    int id; char name[50]; double salary;
    if (fp == NULL) {
        perror("data/employees.txt");
        return;
    }
    while (fscanf(fp, "%d|%49[^|]|%lf", &id, name, &salary) == 3) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", id, name, salary);
    }
    fclose(fp);
}
