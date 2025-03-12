#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float plus(float a, float b) {
    return a + b;
}

float minus(float a, float b) {
    return a - b;
}

float multiplication(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0.) {
        printf("Делить на ноль нельзя!\n");
        exit(1);
    }
    return a / b;
}

typedef float(*func_ptr)(float, float);

int main() {
    func_ptr functions[4] = {plus, minus, multiplication, divide};
    char operations[4] = {'+', '-', '*', '/'};
    char acceptableSymbols[16] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' ', '\n', '+', '-', '*', '/'};
    char mistake = '\0';
    printf("Введите строку, разделяя числа и знаки операций пробелами: ");
    char expression[1000];
    fgets(expression, sizeof(expression), stdin);
    for (int i = 0; i < strlen(expression); i++){
        int accept = 0;
        for (int j = 0; j < 16; j++) {
            if (acceptableSymbols[j] == expression[i]) {
                accept = 1;
                break;
            }
        }
        if (accept == 0) {
            printf("Некорректный ввод! Символ %c недопустим!\n", (char)expression[i]);
            exit(1);
        }
    }
    char* ptr = expression;
    float result = strtod(ptr, &ptr);
    while (*ptr != '\0' && *ptr != '\n') {
        while (*ptr == ' ') {
            ptr++;
        }
        char operation = *ptr;
        ptr++;
        while (*ptr == ' ') {
            ptr++;
        }
        float num = strtod(ptr, &ptr);
        int operationIndex = 0;
        for (int i = 0; i < 4; i++){
            if (operation == operations[operationIndex]){
                result = functions[operationIndex](result, num);
                break;
            }
            else {
                operationIndex++;
            }
        }
    }
    printf("Результат: %f\n", result);
}