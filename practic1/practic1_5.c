#include <stdio.h>
int main() {
    double calculation;
    double fact;
    scanf("%lf", &calculation);
    scanf("%lf", &fact);
    if (calculation - fact > 0.1 || fact - calculation > 0.1) {
        printf("The orbit is not stable");
    }
    else {
        printf("The orbit is stable");
    }
}