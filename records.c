/* records.c - add, display, save and load functions for the MFMS records */
#include <stdio.h>
#include <string.h>
#include "records.h"

/* ---------- Small input helpers (only used in this file) ---------- */

/* Read a line of text (spaces allowed) and remove the newline. */
static void readText(const char *prompt, char *buf, int size)
{
    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

/* Keep asking until the user types a whole number. */
static int readInt(const char *prompt)
{
    char line[64];
    int value;

    for (;;) {
        printf("%s", prompt);
        if (fgets(line, sizeof line, stdin) == NULL) {
            return 0;
        }
        if (sscanf(line, "%d", &value) == 1) {
            return value;
        }
        printf("  Please enter a whole number.\n");
    }
}

/* Keep asking until the user types a number (decimals allowed). */
static double readDouble(const char *prompt)
{
    char line[64];
    double value;

    for (;;) {
        printf("%s", prompt);
        if (fgets(line, sizeof line, stdin) == NULL) {
            return 0.0;
        }
        if (sscanf(line, "%lf", &value) == 1) {
            return value;
        }
        printf("  Please enter a number.\n");
    }
}

/* Ask for day, month and year and return them as a Date structure. */
static Date readDate(const char *label)
{
    Date d;

    printf("  %s\n", label);
    do {
        d.day = readInt("    Day (1-31): ");
    } while (d.day < 1 || d.day > 31);
    do {
        d.month = readInt("    Month (1-12): ");
    } while (d.month < 1 || d.month > 12);
    do {
        d.year = readInt("    Year (e.g. 2026): ");
    } while (d.year < 1900 || d.year > 2100);

    return d;
}

/* ---------- Employee ---------- */

int addEmployee(Employee list[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Employee list is full (%d records). Cannot add more.\n", MAX_RECORDS);
        return count;
    }

    printf("\n--- Add Employee ---\n");
    list[count].id = readInt("  ID: ");
    readText("  Name: ", list[count].name, sizeof list[count].name);
    readText("  Department: ", list[count].department, sizeof list[count].department);
    list[count].salary = readDouble("  Salary (N$): ");

    printf("Employee added.\n");
    return count + 1;
}

void displayEmployees(const Employee list[], int count)
{
    int i;

    printf("\n--- Employees (%d) ---\n", count);
    if (count == 0) {
        printf("No employees stored yet.\n");
        return;
    }

    printf("%-6s %-20s %-15s %12s\n", "ID", "Name", "Department", "Salary (N$)");
    for (i = 0; i < count; i++) {
        printf("%-6d %-20s %-15s %12.2f\n",
               list[i].id, list[i].name, list[i].department, list[i].salary);
    }
}

/* ---------- Supplier ---------- */

int addSupplier(Supplier list[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Supplier list is full (%d records). Cannot add more.\n", MAX_RECORDS);
        return count;
    }

    printf("\n--- Add Supplier ---\n");
    list[count].id = readInt("  ID: ");
    readText("  Name: ", list[count].name, sizeof list[count].name);
    readText("  Email: ", list[count].email, sizeof list[count].email);
    readText("  Phone: ", list[count].phone, sizeof list[count].phone);
    readText("  Town: ", list[count].town, sizeof list[count].town);

    printf("Supplier added.\n");
    return count + 1;
}

void displaySuppliers(const Supplier list[], int count)
{
    int i;

    printf("\n--- Suppliers (%d) ---\n", count);
    if (count == 0) {
        printf("No suppliers stored yet.\n");
        return;
    }

    printf("%-6s %-20s %-25s %-14s %-12s\n", "ID", "Name", "Email", "Phone", "Town");
    for (i = 0; i < count; i++) {
        printf("%-6d %-20s %-25s %-14s %-12s\n",
               list[i].id, list[i].name, list[i].email, list[i].phone, list[i].town);
    }
}

/* ---------- Asset (has a nested Date) ---------- */

int addAsset(Asset list[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Asset list is full (%d records). Cannot add more.\n", MAX_RECORDS);
        return count;
    }

    printf("\n--- Add Asset ---\n");
    list[count].id = readInt("  ID: ");
    readText("  Description: ", list[count].description, sizeof list[count].description);
    list[count].value = readDouble("  Value (N$): ");
    list[count].acquired = readDate("Date acquired:");

    printf("Asset added.\n");
    return count + 1;
}

void displayAssets(const Asset list[], int count)
{
    int i;

    printf("\n--- Assets (%d) ---\n", count);
    if (count == 0) {
        printf("No assets stored yet.\n");
        return;
    }

    printf("%-6s %-25s %14s %-12s\n", "ID", "Description", "Value (N$)", "Acquired");
    for (i = 0; i < count; i++) {
        printf("%-6d %-25s %14.2f %02d/%02d/%d\n",
               list[i].id, list[i].description, list[i].value,
               list[i].acquired.day, list[i].acquired.month, list[i].acquired.year);
    }
}

/* ---------- Budget (balance = allocated - spent) ---------- */

int addBudget(Budget list[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Budget list is full (%d records). Cannot add more.\n", MAX_RECORDS);
        return count;
    }

    printf("\n--- Add Budget ---\n");
    readText("  Department: ", list[count].department, sizeof list[count].department);
    list[count].allocated = readDouble("  Amount allocated (N$): ");
    list[count].spent = readDouble("  Amount spent (N$): ");

    printf("Budget added.\n");
    return count + 1;
}

void displayBudgets(const Budget list[], int count)
{
    int i;
    double balance;

    printf("\n--- Budgets (%d) ---\n", count);
    if (count == 0) {
        printf("No budgets stored yet.\n");
        return;
    }

    printf("%-20s %14s %14s %14s\n", "Department", "Allocated", "Spent", "Balance");
    for (i = 0; i < count; i++) {
        balance = list[i].allocated - list[i].spent;
        printf("%-20s %14.2f %14.2f %14.2f", list[i].department,
               list[i].allocated, list[i].spent, balance);
        if (balance < 0) {
            printf("  <-- OVERSPENT");
        }
        printf("\n");
    }
}

/* ---------- Project (two nested Dates) ---------- */

int addProject(Project list[], int count)
{
    if (count >= MAX_RECORDS) {
        printf("Project list is full (%d records). Cannot add more.\n", MAX_RECORDS);
        return count;
    }

    printf("\n--- Add Project ---\n");
    list[count].id = readInt("  ID: ");
    readText("  Title: ", list[count].title, sizeof list[count].title);
    list[count].budget = readDouble("  Budget (N$): ");
    list[count].startDate = readDate("Start date:");
    list[count].endDate = readDate("End date:");

    printf("Project added.\n");
    return count + 1;
}

void displayProjects(const Project list[], int count)
{
    int i;

    printf("\n--- Projects (%d) ---\n", count);
    if (count == 0) {
        printf("No projects stored yet.\n");
        return;
    }

    printf("%-6s %-25s %14s %-12s %-12s\n", "ID", "Title", "Budget (N$)", "Start", "End");
    for (i = 0; i < count; i++) {
        printf("%-6d %-25s %14.2f %02d/%02d/%d %02d/%02d/%d\n",
               list[i].id, list[i].title, list[i].budget,
               list[i].startDate.day, list[i].startDate.month, list[i].startDate.year,
               list[i].endDate.day, list[i].endDate.month, list[i].endDate.year);
    }
}

/* ---------- Save and load employees (binary file) ---------- */

/* Returns 1 on success, 0 on failure. */
int saveEmployees(const Employee list[], int count, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    size_t written;

    if (fp == NULL) {
        perror(filename);
        return 0;
    }

    written = fwrite(list, sizeof list[0], (size_t)count, fp);
    fclose(fp);

    if (written != (size_t)count) {
        printf("Warning: only %zu of %d records were written.\n", written, count);
        return 0;
    }
    return 1;
}

/* Returns the number of records loaded (0 if the file is missing). */
int loadEmployees(Employee list[], int max, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    size_t loaded;

    if (fp == NULL) {
        printf("Could not open %s (has it been saved yet?).\n", filename);
        return 0;
    }

    loaded = fread(list, sizeof list[0], (size_t)max, fp);
    fclose(fp);

    return (int)loaded;
}
