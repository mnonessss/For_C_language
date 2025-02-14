#include <stdio.h>
int main() {
    union Data {
        int integer;
        float notint;
        char str[1000];
    };
    int choice = getchar();
    union Data data;
    if (choice == '1') {
        scanf("%d", &data.integer);
        printf("%s: %d %s", "Integer", data.integer, "\n");
    }
    else if (choice == '2') {
        scanf("%f", &data.notint);
        printf("%s: %f %s", "Float", data.notint, "\n");
    }
    else {
        scanf("%s", data.str);
        printf("%s: %s %s", "String", data.str, "\n");
    }
}