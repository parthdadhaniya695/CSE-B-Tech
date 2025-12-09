// 5)	Write a C program to generate prime numbers in a given range.

#include <stdio.h>

int main() {
    int start, end, i, j, flag;

    printf("Enter start of range: ");
    scanf("%d", &start);

    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    for (i = start; i <= end; i++) {
        if (i <= 1)
            continue;  

        flag = 0;

        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1; 
                break;
            }
        }

        if (flag == 0)
            printf("%d ", i);
    }

    printf("\n");
    return 0;
}