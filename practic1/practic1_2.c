#include <stdio.h>
int main() {
    int distance;
    scanf("%d", &distance);
    if (distance <= 500) {
        printf("The car can go to the charge station");
    }
    else {
        printf("The car can't go to the charge station");
    }
}