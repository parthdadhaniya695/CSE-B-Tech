// 3.	Write a C program to find the multiplicative inverse of a number modulo n.

#include <stdio.h>

int modInverse(int a, int n)
{
    int x;

    for(x = 1; x < n; x++)
    {
        if((a * x) % n == 1)
            return x;
    }

    return -1;
}

int main()
{
    int a, n;

    printf("Enter number and modulo: ");
    scanf("%d %d", &a, &n);

    int inv = modInverse(a, n);

    if(inv == -1)
        printf("Inverse does not exist\n");
    else
        printf("Multiplicative inverse = %d\n", inv);

    return 0;
}