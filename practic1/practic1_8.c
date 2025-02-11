#include <stdio.h>
int main() {
    int weight;
    scanf("%d", &weight);
    if (weight % 4 == 0) {
        printf("%s %d %s", "We can share weight. Each compartment will contain", weight / 4, "kilograms");
    }
    else {
        printf("We can't share weight for four compartments");
    }
}