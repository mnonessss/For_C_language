#include <stdio.h>
int main() {
    int weight;
    scanf("%d", &weight);
    if (weight < 60 && weight > 90){
        printf("You can't fly on this board");
    }
    else{
        printf("You can fly on this board");
    }
}

