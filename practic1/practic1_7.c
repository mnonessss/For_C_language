#include <stdio.h>
int main() {
    float signal;
    scanf("%f", &signal);
    if (signal >= 2.5 && signal <= 3.3) {
        printf("the signal is stable");
    }
    else {
        printf("The signal is not stable");
    }
}