#include <stdio.h>
int main(){
    // declaring varables
    //1.salary 
    //2.total
    //3.highest
    //4. lowest
    //5. acverage
    double salaries[50];
    double total = 0.0;
    double average = 0.0;
     double highest = 0.0;
      double lowest = 0.0;
// prompting for the salary of every employee
 for (int i=1 ; i<= 50; i++){
    printf("enter salararies %d: ",i+1);
    scanf("%2f",&salaries[i] );
    total += salaries[i]; //this will be calculated as we go 
 }
 //avrage calculation
 average = total/50;
 //  Highest and lowest salary
    highest = salaries[0];
    lowest = salaries[0];
    for (int i = 1; i < 50; i++)
    {
        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
        if (salaries[i] < lowest)
        {
            lowest = salaries[i];
        }
    }
printf("total salaries: %.2f\n", total);
printf("average salaries: %.2f\n  ", average);
printf("lowest salaries: %.2f\n", lowest);
printf("highest salaries: %.2f\n",highest);
 return 0 ;
}