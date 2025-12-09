// 1)	Write a program to reverse a string using pointers.

#include <stdio.h>

int main() {
    char str[100], *ptr_start, *ptr_end, temp;
    int len = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[len] != '\0' && str[len] != '\n')
        len++;

    ptr_start = str;          
    ptr_end = str + len - 1;  

    while (ptr_start < ptr_end) {
        temp = *ptr_start;
        *ptr_start = *ptr_end;
        *ptr_end = temp;

        ptr_start++;
        ptr_end--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}