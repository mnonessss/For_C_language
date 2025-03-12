#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int alphabet(const void* a, const void* b) {
    return strcasecmp(*(const char**)a, *(const char**)b);
}

int length(const void* a, const void* b) {
    int len_a = strlen(*(const char**)a);
    int len_b = strlen(*(const char**)b);
    return (len_a > len_b) - (len_a < len_b);
}

int count_vowels(const void* a, const void* b) {
    const char vowels[12] = {'e', 'y', 'u', 'i', 'o', 'a', 'E', 'Y', 'U', 'I', 'O', 'A'};
    int vowels_in_a = 0;
    int vowels_in_b = 0;
    const char* first_str = *(const char**)a;
    const char* second_str = *(const char**)b;
    for (int i = 0; i < strlen(first_str); i++){
        for (int j = 0; j < 12; j++) {
            if (vowels[j] == first_str[i]){
                vowels_in_a++;
                break;
            }
        }
    }
    for (int i = 0; i < strlen(second_str); i++){
        for (int j = 0; j < 12; j++) {
            if (vowels[j] == second_str[i]){
                vowels_in_b++;
                break;
            }
        }
    }
    return vowels_in_a - vowels_in_b;
}

int main() {
    typedef int(*func_ptr)(const void*, const void*);
    func_ptr functions[3] = {alphabet, length, count_vowels};
    char** strings = NULL;
    int count = 0;
    printf("Введите строки, разделяя их символом перехода на новую строку. Для остановки введите пустую строку: ");
    char str[1000];
    while(fgets(str, sizeof(str), stdin) && str[0] != '\n'){
        str[strcspn(str, "\n")] = '\0';
        strings = realloc(strings, (count + 1) * sizeof(char*));
        strings[count] = strdup(str);
        count++;
    }

    int mode;
    printf("Выберите режим сортировки: 1.По алфавиту; 2.По длине строки; 3.По количеству гласных букв (Регистр нигде не учитывается, ввести нужно только цифру)");
    scanf("%d", &mode);
    qsort(strings, count, sizeof(char*), functions[mode-1]);
    for (int i = 0; i < count; i++){
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);
}