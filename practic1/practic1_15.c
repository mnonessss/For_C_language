#include <stdio.h>
int main() {
    double m;
    double speed;
    scanf("%lf", &m);
    scanf("%lf", &speed);
    double kb = m * 1024;
    printf("%lf %s", kb / 60, "минут");
}