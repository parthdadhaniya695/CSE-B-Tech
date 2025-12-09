// 4)	Write a C program to test whether a number is prime or composite.

#include <stdio.h>

int main() {
    int num, i, flag = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1) {
        printf("Number is neither prime nor composite.\n");
        return 0;
    }

    // Check divisors from 2 to num/2
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            flag = 1;   
            break;
        }
    }

    if (flag == 0)
        printf("%d is a PRIME number.\n", num);
    else
        printf("%d is a COMPOSITE number.\n", num);

    return 0;
}