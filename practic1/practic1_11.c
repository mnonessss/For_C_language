#include <stdio.h>
int main() {
    float oxygen;
    scanf("%f", &oxygen);
    if (oxygen < 15) {
        printf("You have to turn the emergency system right now!");
    }
    else {
        printf("Everything is OK");
    }
}