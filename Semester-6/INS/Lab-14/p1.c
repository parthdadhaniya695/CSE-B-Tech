// Implementation of Diffie-Hellman Key Exchange Technique

#include <stdio.h>
#include <math.h>

// function for modular exponentiation
long long power(long long base, long long exp, long long mod)
{
    long long result = 1;

    for(int i = 0; i < exp; i++)
    {
        result = (result * base) % mod;
    }

    return result;
}

int main()
{
    long long p, g;
    long long a, b;
    long long A, B;
    long long keyA, keyB;

    printf("Enter prime number (p): ");
    scanf("%lld", &p);

    printf("Enter primitive root (g): ");
    scanf("%lld", &g);

    printf("Enter private key of User A: ");
    scanf("%lld", &a);

    printf("Enter private key of User B: ");
    scanf("%lld", &b);

    // Public keys
    A = power(g, a, p);
    B = power(g, b, p);

    printf("\nPublic key of User A = %lld", A);
    printf("\nPublic key of User B = %lld", B);

    // Secret keys
    keyA = power(B, a, p);
    keyB = power(A, b, p);

    printf("\n\nSecret key calculated by User A = %lld", keyA);
    printf("\nSecret key calculated by User B = %lld", keyB);

    return 0;
}