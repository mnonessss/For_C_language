#include <stdio.h>
int main() {
    int degrees;
    scanf("%d", &degrees);
    if (degrees < 180 && degrees > -180) {
        printf("Everything is good");
    }
    else {
        printf("The system is broken");
    }
}