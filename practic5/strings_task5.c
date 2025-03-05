#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char text[200];
    printf("Введите текст для копирования: ");
    fgets(text, sizeof(text), stdin);
    char* cp = strdup(text);
    printf("Оригинал: %s", text);
    printf("Копия: %s", cp);
    free(cp);
}