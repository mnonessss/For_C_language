#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char useful[] = "qwertyuiopasdfghjklzxcvbnm1234567890";
    char noNeed[] = "#*";
    char str[100];
    printf("Введите строку: ");
    scanf("%99s", str);

    int firstLetter = strcspn(str, useful);
    char withoutStart[100];
    strcpy(withoutStart, str + firstLetter);

    int lastLetter = strcspn(withoutStart, noNeed);
    withoutStart[lastLetter] = '\0';
    printf("%s, %ld", withoutStart, strlen(withoutStart));
}