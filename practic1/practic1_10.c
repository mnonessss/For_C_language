#include <stdio.h>
int main() {
    int temp;
    scanf("%d", &temp);
    if (temp >= -150 && temp <= 120) {
        printf("The temperature is OK");
    }
    else {
        printf("The temperature is bad");
    }
}