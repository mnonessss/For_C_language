#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void upper() {
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(char) * 1000, stdin);
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    printf("%s", str);
}

void lower() {
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    printf("%s", str);
}

void reverse() {
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    char* res = (char*) malloc(sizeof(char) * strlen(str));
    for (int i = 0; i < strlen(str); i++) {
        res[i] = '0';
    }
    for (int i = 0; i < strlen(str) / 2; i++) {
        char temp = str[i];
        res[i] = str[strlen(str) - 1 - i];
        res[strlen(str) - 1 - i] = temp;
    }
    if (strlen(str) % 2 == 1) {
        res[(strlen(str) - 1) / 2] = str[(strlen(str) - 1) / 2];
    }
    printf("%s\n", res);
    free(res);
}


typedef void (*functions)();

typedef struct {
    char* name;
    functions func;
} comand;


int main() {
    comand comands[] = {
        {"upper", upper},
        {"lower", lower}, 
        {"reverse", reverse}, 
        {"exit", NULL}
    };
    char cmd[8];
    printf("Введите команду: ");
    scanf("%s", cmd);
    getchar();

    for (int i = 0; i < 4; i++) {
        if (strcmp(cmd, comands[i].name) == 0) {
            if (comands[i].func == NULL) {
                exit(0);
            }
            comands[i].func();
            break;
        }
    }
}