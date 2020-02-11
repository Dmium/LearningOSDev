#include <stdio.h>
#include <string.h>
#include <kernel/tty.h>

void kernel_main(void) {
	terminal_initialize();
	kerror("Hello, kernel World!\n");
	printf("Hello, kernel Worlda!\n");
	printf("Hello, kernel Worldb!\n");
	printf("Hello, kernel Worldc!\n");
	printf("Hello, kernel Worldd!\n");
	printf("Hello, kernel Worldc!\n");
	printf("Hello, kernel Worldd!\n");
	kerror("Hello, kernel World!\n");
	printf("Hello, kernel Worldc!\n");
	printf("Hello, kernel Worldd!\n");
	printf("Hello, kernel Worldc!\n");
	printf("Hello, kernel Worldd!\n");
	printf("Hello, kernel Worldc!\n");
	printf("Hello, kernel Worldd!\n");
	printf("Hello, kernel Worldc!\n");
	printf("Hello, kernel Worldd!\n");
	printf("Hello, kernel Worlde!\n");
	printf("Hello, kernel Worldf!\n");
	printf("Hello, kernel Worldg!\n");
	printf("Hello, kernel Worlda!\n");
	printf("Hello, kernel Worldb!\n");
	printf("Hello, kernel Worldc!\n");
	printf("Hello, kernel Worldd!\n");
	printf("Hello, kernel Worlde!\n");
	printf("Hello, kernel Worldf!\n");
	printf("Hello, kernel Worldg!\n");
	kerror("Hello, kernel World!\n");
	kerror("Hello, kernel World!\n");
	printf("Hello, kernel World!\n");
	printf("Hello, kernel World!\n");
	kerror("Hello, kernel World!\n");
    printf("X %d\n", strlen("12345678987654321234567897543333333333333333333333333333333123456"));
    printf("X %d\n", 147483647);
    printf("y\n");
}