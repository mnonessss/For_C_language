#include <stdio.h>
#include <strings.h>

int main() {
    char *password;
    printf("Введите код: ");
    fgets(password, sizeof(char) * 1000, stdin);
    if (strcasecmp(password, "LAUNCH-2025\n") == 0) {
        printf("Код принят\n");
    }
    else {
        printf("Ошибка: неверный код!\n");
    }
}