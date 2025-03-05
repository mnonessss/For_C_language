#include <stdio.h>
#include <string.h>

int main() {
    char *names;
    printf("Введите фамилии космонавтов, разделяя их только точкой с запятой: ");
    scanf("%s", names);
    char* ptr = strtok(names, ";");
    while (ptr) {
        printf("%s\n", ptr);
        ptr = strtok(NULL, ";");
    }
}