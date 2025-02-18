#include <stdio.h>
void check_fuel(int fuel_level) {
    if (fuel_level < 10) {
        printf("You have low fuel so you have to go to a gas station\n");
    }
    else {
        printf("You have enough fuel!\n");
    }
}