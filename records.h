/* records.h - the five MFMS record types and the functions that use them */
#ifndef RECORDS_H
#define RECORDS_H

#define MAX_RECORDS 100

/* ---------- Structures ---------- */

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
} Employee;

typedef struct {
    int id;
    char name[40];
    char email[40];
    char phone[15];
    char town[20];
} Supplier;

typedef struct {
    int id;
    char description[40];
    double value;
    Date acquired;          /* nested structure */
} Asset;

typedef struct {
    char department[20];
    double allocated;
    double spent;
} Budget;

typedef struct {
    int id;
    char title[40];
    double budget;
    Date startDate;         /* nested structures */
    Date endDate;
} Project;

/* ---------- Functions ----------
   Each add function returns the NEW number of records.
   If the array is full, it returns the old number unchanged. */

int addEmployee(Employee list[], int count);
void displayEmployees(const Employee list[], int count);

int addSupplier(Supplier list[], int count);
void displaySuppliers(const Supplier list[], int count);

int addAsset(Asset list[], int count);
void displayAssets(const Asset list[], int count);

int addBudget(Budget list[], int count);
void displayBudgets(const Budget list[], int count);

int addProject(Project list[], int count);
void displayProjects(const Project list[], int count);

/* Binary file saving (Week 10 idea applied to structures) */
int saveEmployees(const Employee list[], int count, const char *filename);
int loadEmployees(Employee list[], int max, const char *filename);

#endif
