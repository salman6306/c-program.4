#include <stdio.h>
#include <stdlib.h>

struct Employee 
{
    int eno;
    char ename[100];
    float salary;
};

int main() 
{
    int n, i;
    struct Employee employees[100];

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
	{
        printf("Enter details of employee %d:\n", i+1);

        printf("Enter employee number: ");
        scanf("%d", &employees[i].eno);

        printf("Enter employee name: ");
        scanf("%s", employees[i].ename);

        printf("Enter employee salary: ");
        scanf("%f", &employees[i].salary);
    }
    int max_index = 0;
    float max_salary = employees[0].salary;

    for (i = 1; i < n; i++) {
        if (employees[i].salary > max_salary) 
		{
            max_salary = employees[i].salary;
            max_index = i;
        }
    }
    printf("\nDetails of employee with highest salary:\n");
    printf("Employee number: %d\n", employees[max_index].eno);
    printf("Employee name: %s\n", employees[max_index].ename);
    printf("Employee salary: %.2f\n", employees[max_index].salary);

    return 0;
}
