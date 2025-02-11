#include <stdio.h>
int main() {
    double time;
    scanf("%lf", &time);
    int minuites = 0;
    while (time >= 60) {
        minuites++;
        time -= 60.0;
    }
    printf("%d %s %lf %s", minuites, "минут и", time, "секунд");
}