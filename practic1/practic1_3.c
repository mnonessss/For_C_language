#include <stdio.h>
int main() {
    char symbol;
    int code;
    symbol = getchar();
    code = (int)(symbol);
    if (code > 64 && code < 91) {
        printf("All right");
    }
    else {
        printf("This is not a letter from A to Z");
    }
}