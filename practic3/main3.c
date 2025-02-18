#include <stdio.h>
#include "navigation.c"
#include "fuel.c"

int main() {
    float speed, time;
    int fuel;
    printf("Введите через пробел скорость и время: ");
    scanf("%f %f", &speed, &time);
    calculate_distance(speed, time);
    printf("Введите количество оставшегося топлива в процентах: ");
    scanf("%d", &fuel);
    check_fuel(fuel);
}

//Дополнительный вопрос: после связывания файл main3.0, судя по выводу утилиты nm забирает функции у fuel.o и navigation.o
//без изменений, при этом добавляя новые функции. __isoc99_scanf - это функция scanf(), а также функция main с флагом T, что означает, что функция находится в секции '.text'