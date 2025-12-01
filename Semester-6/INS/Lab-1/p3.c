// Write a C program that takes a string and performs bitwise AND and XOR operations with a constant value (e.g., 127). (Simulates simple encryption idea)

#include <stdio.h>
#include <string.h>

#define KEY 127

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);

    printf("\nOriginal String: %s\n", str);

    // Perform bitwise AND
    printf("After AND with %d: ", KEY);
    for (int i = 0; i < len; i++) {
        printf("%c", str[i] & KEY);
    }
    printf("\n");

    // Perform bitwise XOR
    printf("After XOR with %d: ", KEY);
    for (int i = 0; i < len; i++) {
        printf("%c", str[i] ^ KEY);
    }
    printf("\n");

    return 0;
}