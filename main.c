/* main.c - MFMS Week 12: Week 11 records plus pointer-based salary updates */
#include <stdio.h>
#include "records.h"

#define EMPLOYEE_FILE "employees.dat"

static void showMenu(int employeeCount, int supplierCount, int assetCount,
                     int budgetCount, int projectCount)
{
    printf("\n==============================================\n");
    printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM (MFMS)\n");
    printf("==============================================\n");
    printf("Employees: %d | Suppliers: %d | Assets: %d | Budgets: %d | Projects: %d\n\n",
           employeeCount, supplierCount, assetCount, budgetCount, projectCount);
    printf("  1.  Add Employee\n");
    printf("  2.  Display Employees\n");
    printf("  3.  Add Supplier\n");
    printf("  4.  Display Suppliers\n");
    printf("  5.  Add Asset\n");
    printf("  6.  Display Assets\n");
    printf("  7.  Add Budget\n");
    printf("  8.  Display Budgets\n");
    printf("  9.  Add Project\n");
    printf("  10. Display Projects\n");
    printf("  11. Save Employees to file\n");
    printf("  12. Load Employees from file\n");
    printf("  13. Update Employee Salary\n");
    printf("  14. Salary Statistics (highest and average)\n");
    printf("  0.  Exit\n");
    printf("Choose an option: ");
}

int main(void)
{
    Employee employees[MAX_RECORDS];
    Supplier suppliers[MAX_RECORDS];
    Asset assets[MAX_RECORDS];
    Budget budgets[MAX_RECORDS];
    Project projects[MAX_RECORDS];

    int employeeCount = 0;
    int supplierCount = 0;
    int assetCount = 0;
    int budgetCount = 0;
    int projectCount = 0;

    int choice = -1;
    int loaded;
    char line[32];

    while (choice != 0) {
        showMenu(employeeCount, supplierCount, assetCount, budgetCount, projectCount);

        /* Read the choice as text first so a wrong key cannot crash the menu */
        if (fgets(line, sizeof line, stdin) == NULL) {
            break;
        }
        if (sscanf(line, "%d", &choice) != 1) {
            choice = -1;
        }

        switch (choice) {
        case 1:
            employeeCount = addEmployee(employees, employeeCount);
            break;
        case 2:
            displayEmployees(employees, employeeCount);
            break;
        case 3:
            supplierCount = addSupplier(suppliers, supplierCount);
            break;
        case 4:
            displaySuppliers(suppliers, supplierCount);
            break;
        case 5:
            assetCount = addAsset(assets, assetCount);
            break;
        case 6:
            displayAssets(assets, assetCount);
            break;
        case 7:
            budgetCount = addBudget(budgets, budgetCount);
            break;
        case 8:
            displayBudgets(budgets, budgetCount);
            break;
        case 9:
            projectCount = addProject(projects, projectCount);
            break;
        case 10:
            displayProjects(projects, projectCount);
            break;
        case 11:
            if (saveEmployees(employees, employeeCount, EMPLOYEE_FILE)) {
                printf("Saved %d employee(s) to %s.\n", employeeCount, EMPLOYEE_FILE);
            }
            break;
        case 12:
            loaded = loadEmployees(employees, MAX_RECORDS, EMPLOYEE_FILE);
            if (loaded > 0) {
                employeeCount = loaded;
                printf("Loaded %d employee(s) from %s.\n", employeeCount, EMPLOYEE_FILE);
            } else {
                printf("Nothing was loaded. Your current employees were not changed.\n");
            }
            break;
        case 13:
            updateEmployeeSalaryMenu(employees, employeeCount);
            break;
        case 14:
            salaryStatistics(employees, employeeCount);
            break;
        case 0:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please choose 0 to 14.\n");
        }
    }

    return 0;
}
