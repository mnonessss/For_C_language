#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

static char* memory = NULL;
static int memory_size = 0;
static bool allocated = false;

typedef struct {
    const char* name;
    void (*handler)(int argc, char** argv);
} Command;

void handle_alloc(int argc, char** argv);
void handle_free(int argc, char** argv);
void handle_write(int argc, char** argv);
void handle_print(int argc, char** argv);
void handle_exit(int argc, char** argv);

Command commands[] = {
    {"alloc", handle_alloc},
    {"free", handle_free},
    {"write", handle_write},
    {"print", handle_print},
    {"exit", handle_exit},
    {NULL, NULL}
};

void check_num_args(int expected, int real, const char* cmd) {
    if (expected != real) {
        fprintf(stderr, "Для команды %s нужно %ls аргументов\n", cmd, &expected);
    }
}

void handle_alloc(int argc, char** argv) {
    check_num_args(1, argc - 1, "alloc");
    if (allocated) {
        printf("Освобождаем занятую память\n");
        free(memory);
    }
    memory_size = strtoul(argv[1], NULL, 10);
    if (memory_size == 0) {
        fprintf(stderr, "Некорректный размер памяти\n");
        return;
    }
    memory = malloc(memory_size);
    if (!memory) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }
    memset(memory, 0, memory_size);
    allocated = true;
    printf("Память успешно выделена\n");
}

void handle_free(int argc, char** argv) {
    check_num_args(0, argc - 1, "free");
    if (!allocated) {
        fprintf(stderr, "Память не выделена, поэтому ее нельзя очистить\n");
        return;
    }
    free(memory);
    memory = NULL;
    memory_size = 0;
    allocated = false;
    printf("Память освобождена\n");
}

void handle_write(int argc, char** argv) {
    check_num_args(1, argc - 1, "write");
    if (!allocated) {
        fprintf(stderr, "Память не выделена, поэтому в нее нельзя ничего записать\n");
        return;
    }
    const char* toWrite = argv[1];
    int len_to_write = strlen(toWrite);
    if (len_to_write >= memory_size) {
        printf("Будет записано только %d символов, так как на остальные не хватит выделенной памяти\n", memory_size - 1);
    }
    strncpy(memory, toWrite, memory_size - 1);
    memory[memory_size - 1] = '\0';
    printf("Текст записан в память\n");
}

void handle_print(int argc, char** argv) {
    check_num_args(0, argc - 1, "print");
    if (!allocated) {
        fprintf(stderr, "Память не выделена\n");
        return;
    }
    printf("Содержимое памяти: %s\n", memory);
}

void handle_exit(int argc, char** argv) {
    if (allocated) {
        free(memory);
    }
    printf("Программа завершена\n");
    exit(0);
}

int main() {
    char input[5000];
    char *argv[10];
    printf("Доступные команды:\n"
           "alloc <size>    - выделить память\n"
           "free            - освободить память\n"
           "write <text>    - записать текст\n"
           "print           - вывести содержимое\n"
           "exit            - выход\n\n");
    while (true){
        printf("Введите название команды и через пробел аргументы, если необходимо: ");
        if (!fgets(input, sizeof(char) * 5000, stdin)) {
            break;
        };
        int argc = 0;
        char* token = strtok(input, " \t\n");
        while(token && argc < 10) {
            argv[argc++] = token;
            token = strtok(NULL, " \t\n");
        }
        for (Command *cmd = commands; cmd->name; cmd++) {
            if (strcmp(argv[0], cmd->name) == 0) {
                cmd->handler(argc, argv);
            }
        }
    }
}



