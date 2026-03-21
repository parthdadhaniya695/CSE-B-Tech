// 2.	Write a C program to implement modular exponentiation (for RSA key generation).

#include <stdio.h>

long long modExp(long long base, long long exp, long long mod)
{
    long long result = 1;

    while(exp > 0)
    {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

int main()
{
    long long base, exp, mod;

    printf("Enter base exponent modulus: ");
    scanf("%lld %lld %lld", &base, &exp, &mod);

    printf("Result = %lld\n", modExp(base, exp, mod));

    return 0;
}