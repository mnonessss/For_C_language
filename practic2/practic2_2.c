#include <stdio.h>
int main() {
    struct Item {
        char name[100];
        int count;
        float price;
    };
    int count;
    printf("Сколько товаров вы хотите указать: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        struct Item item;
        printf("Введите название товара, его количество и цену через пробел: ");
        scanf("%s", item.name);
        scanf("%d", &item.count);
        scanf("%f", &item.price);
        printf("%s %s %s", "Item:", item.name, "\n");
        printf("%s %d %s", "Quantity:", item.count, "\n");
        printf("%s %f %s", "Price:", item.price, "\n");
    }
}