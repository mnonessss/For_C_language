#include <stdio.h>
int main() {
    struct Employee {
        char name[100];
        char role[100];
        float salary;
    };
    int n;
    printf("Введите количесвто сотрудников: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct Employee employee;
        printf("Введите через пробел имя сотрудника, его должность и зарплату: ");
        scanf("%s", employee.name);
        scanf("%s", employee.role);
        scanf("%f", &employee.salary);
        printf("%s: %s %s", "Name", employee.name, "\n");
        printf("%s: %s %s", "Position", employee.role, "\n");
        printf("%s: %f %s", "Salary", employee.salary, "\n");
    }
}