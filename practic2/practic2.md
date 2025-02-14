Составные (или агрегатные) типы данных - массивы, структуры, объединения. перечисления
Структура - это тип данных, который позволяет объединять различные типы данных в одну сущность.
Синтаксис:
struct Person {
    char name[50];
    int age;
    float height;
};

Пример использования:
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    struct Person p = {"Alice", 30, 1.75};
    printf("Name: %s, Age: %d, Height: %.2f\n", p.name, p.age, p.height);
    return 0;
}

union Data {
    int i;
    float f;
    chat str[20];
};

В объединении только одно поле может содержать значение в любой момент времени.
Размер объединения соответсвует размеру самого большого поля.
Поля объединения делят одну и ту же область памяти.

Пример использования:
union Data {
    int i;
    float f;
    chat str[20];
};
int main() {
    union Data data;
    data.i = 10;
    printf("data.i = %d\n", data.i);
    data.f = 220.5;
    printf("data.f = %.2f", data.f);
    return 0;
}

Перечисление позволяет задать набор именованных целых констант.
Синтаксис перечислений:
enum Something {
    const1,
    const2
};
Пример:
enum Day {Sunday, Monday, Tuesday, Wedvesday, Thursday, Friday, Saturday};
int main() [
    enum Day today = Wednesday;
]
