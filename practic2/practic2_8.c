#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    union Grade {
        int percents;
        char grade;
    };
    union Grade grades;
    int n;
    char current[3];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", current);
        if (current[0] > 64 && current[0] < 91) {
            grades.grade = current[0];
            printf("%s: %c %s", "Grade", grades.grade, "\n");
        }
        else {
            grades.percents = atof(current);
            printf("%s: %d %s", "Grade", grades.percents, "\n");
        }

    }
}