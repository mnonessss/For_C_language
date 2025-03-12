#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* deleteSpaces(char* str) {
    char *res = (char*) malloc(sizeof(char) * (strlen(str) + 1));
    int spaces = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            res[i - spaces] = str[i];
        }
        else {
            spaces++;
        }
    }
    res[strlen(str) - spaces + 1] = '\0';
    return res;
}

char* vowelsToStar(char* str) {
    char vowels[12] = {'e', 'y', 'u', 'i', 'o', 'a', 'E', 'Y', 'U', 'I', 'O', 'A'};
    char* res = (char*) malloc (sizeof(char) * (strlen(str) + 1));
    for (int i = 0; i < strlen(str); i++) {
        int isVowel = 0;
        for (int j = 0; j < 12; j++) {
            if (str[i] == vowels[j]) {
                res[i] = '*';
                isVowel = 1;
            }
        }
        if (isVowel == 0) {
            res[i] = str[i];
        }
    }
    res[strlen(str)] = '\0';
    return res;
}

char* invertRegister(char* str) {
    char* res = (char*) malloc(sizeof(char) * (strlen(str) + 1));
    for (int i = 0; i < strlen(str); i++) {
        if (65 <= (int)str[i] && (int)str[i] <= 90) {
            res[i] = tolower(str[i]);
        }
        else if (97 <= (int)str[i] && (int)str[i] <= 122) {
            res[i] = toupper(str[i]);
        }
        else {
            res[i] = str[i];
        }
    }
    res[strlen(str)] = '\0';
    return res;
}

typedef char* (*func_ptr)(char*);

int main() {
    func_ptr functions[3] = {deleteSpaces, vowelsToStar, invertRegister};
    char* names_func[] = {"Удаление пробелов", "Замена всех гласных на '*'", "Инвертирование регистра символов"};
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    printf("Введите через пробел последовательность номеров операций, например, 1 2 1 (отсчет идет с единицы)\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, names_func[i]);
    }
    char answer[1000];
    fgets(answer, sizeof(answer), stdin);
    char* StrWithoutSpaces = strtok(answer, " ");
    char* res = strdup(str);
    while (StrWithoutSpaces) {
        int num = atoi(StrWithoutSpaces);
        char* temp = functions[num - 1](res);
        free(res);
        res = temp;
        StrWithoutSpaces = strtok(NULL, " ");
    }
    printf("%s", res);
    free(res);
}