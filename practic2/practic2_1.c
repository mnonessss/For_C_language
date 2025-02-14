#include <stdio.h>
#include <stdlib.h>
int main() {
    struct Student {
        char name[50];
        int age;
        float average;
    };
    int count;
    printf("Сколько студентов вы хотите добавить: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("введите имя студента, его возраст и средний балл");
        struct Student student;
        scanf("%s", student.name);
        scanf("%d", &student.age);
        scanf("%f", &student.average);
        printf("%s %s %s", "Name:", student.name, "\n");
        printf("%s %d %s", "Age:", student.age, "\n");
        printf("%s %f %s", "GPA:", student.average, "\n");
        printf("\n");
    }
}