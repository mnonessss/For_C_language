#include <stdio.h>
int main() {
    struct Date {
            int day;
            int month;
            int year;
    };
    struct Event {
        char name[100];
        struct Date date;
        char description[1000];
    };
    int n;
    printf("Введите количесвто событий: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct Event event;
        struct Date date;
        printf("Через пробел введите название мероприятия, день, месяц и год проведения, описание: ");
        scanf("%s", event.name);
        scanf("%d", &date.day);
        scanf("%d", &date.month);
        scanf("%d", &date.year);
        event.date = date;
        scanf("%s", event.description);
        printf("%s %s %s", "Event:", event.name, "\n");
        printf("%s %d/%d/%d %s", "Date:", event.date.day, event.date.month, event.date.year, "\n");
        printf("%s %s %s", "Description:", event.description, "\n");
    }
}