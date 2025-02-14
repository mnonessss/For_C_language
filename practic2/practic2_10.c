#include <stdio.h>
int main() {
    struct Course {
        char name[100];
        int credits;
        char teacher[100];
    };
    printf("Введите количестов курсов: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct Course course;
        printf("Введите через пробел название курса, количесвто кредитов и преподавателя: ");
        scanf("%s", course.name);
        scanf("%d", &course.credits);
        scanf("%s", course.teacher);
        printf("%s: %s %s", "Course", course.name, "\n");
        printf("%s: %d %s", "Credits", course.credits, "\n");
        printf("%s: %s %s", "Professor", course.teacher, "\n");
    }
}