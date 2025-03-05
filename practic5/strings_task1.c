#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[5000];
    int found = 0;
    printf("Введите через пробел или запятые названия кораблей: ");
    fgets(str, sizeof(char) * 5000, stdin);
    char *ships = strtok(str, ", \n");
    while (ships) {
    char firstTwo[3] = {toupper(ships[0]), toupper(ships[1]), '\0'};
        if (strncmp("SS", firstTwo, 2) == 0) {
            found = 1;
            printf("%s\n", ships);
            break;
        }
        ships = strtok(NULL, ", \n");
    }
    if (found == 0) {
        printf("Не найдено\n");
    }
}
