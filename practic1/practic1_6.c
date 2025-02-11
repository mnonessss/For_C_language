#include <stdio.h>
int main() {
    int astronauts;
    scanf("%d", &astronauts);
    int two, three, four;
    if (astronauts % 2 != 0) {
        printf("%s %d %s", "Необходимо", (astronauts - 1) / 2, "двухместных кораблей. Одного космонавта нужно оставить.\n");
    }
    else {
        printf("%s %d %s", "Необходимо", astronauts / 2, "двухместных кораблей.\n");
    }

    if (astronauts % 3 != 0) {
        if ((astronauts - 1) % 3 == 0) {
            printf("%s %d %s", "Необходимо", (astronauts - 1) / 3, "трехместных кораблей. Одного космонавта нужно оставить.\n");
        }
        else {
            printf("%s %d %s", "Необходимо", (astronauts - 2) / 3, "трехместных кораблей. Двух космонавтов нужно оставить.\n");
        }
    }
    else {
        printf("%s %d %s", "Необходимо", astronauts / 3, "трехместных кораблей.\n");
    }

    if (astronauts % 4 != 0) {
        if ((astronauts - 1) % 4 == 0) {
            printf("%s %d %s", "Необходимо", (astronauts - 1) / 4, "четырехместных кораблей. Одного космонавта нужно оставить.\n");
        }
        else if ((astronauts - 2) % 4 == 0) {
            printf("%s %d %s", "Необходимо", (astronauts - 2) / 4, "четырехместных кораблей. Двух космонавтов нужно оставить.\n");
        }
        else {
            printf("%s %d %s", "Необходимо", (astronauts - 3) / 4, "четырехместных кораблей. Трех космонавтов нужно оставить.\n");
        }
    }
    else {
        printf("%s %d %s", "Необходимо",  astronauts / 4, "четырехместных кораблей.\n");
    }
}