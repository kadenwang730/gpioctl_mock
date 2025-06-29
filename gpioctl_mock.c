#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GPIO_BASE_PATH "./mock_sys/class/gpio"

void write_file(const char* path, const char* content) {
    FILE* fp = fopen(path, "w");
    if (!fp) {
        perror(path);
        return;
    }
    fprintf(fp, "%s", content);
    fclose(fp);
}

void read_file(const char* path) {
    char value[8];
    FILE* fp = fopen(path, "r");
    if (!fp) {
        perror(path);
        return;
    }
    fgets(value, sizeof(value), fp);
    fclose(fp);
    printf("GPIO value: %s
", value);
}

void export_gpio(int pin) {
    char path[128];
    snprintf(path, sizeof(path), GPIO_BASE_PATH "/export");
    char pin_str[8];
    snprintf(pin_str, sizeof(pin_str), "%d", pin);
    write_file(path, pin_str);
}

void set_direction(int pin, const char* direction) {
    char path[128];
    snprintf(path, sizeof(path), GPIO_BASE_PATH "/gpio%d/direction", pin);
    write_file(path, direction);
}

void write_gpio(int pin, int value) {
    char path[128];
    snprintf(path, sizeof(path), GPIO_BASE_PATH "/gpio%d/value", pin);
    write_file(path, value ? "1" : "0");
}

void read_gpio(int pin) {
    char path[128];
    snprintf(path, sizeof(path), GPIO_BASE_PATH "/gpio%d/value", pin);
    read_file(path);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s -r pin\n", argv[0]);
        printf("       %s -w pin value\n", argv[0]);
        return 1;
    }

    int pin = atoi(argv[2]);
    export_gpio(pin);

    if (strcmp(argv[1], "-w") == 0 && argc == 4) {
        int value = atoi(argv[3]);
        set_direction(pin, "out");
        write_gpio(pin, value);
        printf("GPIO %d set to %d\n", pin, value);
    } else if (strcmp(argv[1], "-r") == 0) {
        set_direction(pin, "in");
        read_gpio(pin);
    } else {
        fprintf(stderr, "Invalid arguments\n");
        return 1;
    }

    return 0;
}
