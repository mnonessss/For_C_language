#include <stdio.h>
int main() {
    int date;
    scanf("%d", &date);
    if (date > 20250211) {
        printf("This date is after today");
    }
    else {
        printf("This date has already been");
    }
}