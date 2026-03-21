// Implementation of RSA Algorithm Technique.

#include <stdio.h>
#include <math.h>

// Function to find GCD
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find (base^exp) % mod
long long modExp(long long base, long long exp, long long mod)
{
    long long result = 1;

    while (exp > 0)
    {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

int main()
{
    int p, q, n, phi, e, d = 1, k = 1;
    int msg;
    long long cipher, decrypt;

    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("Enter value of e: ");
    scanf("%d", &e);

    while (gcd(e, phi) != 1)
    {
        printf("e must be coprime with %d. Enter again: ", phi);
        scanf("%d", &e);
    }

    // Finding d
    while (1)
    {
        if ((k * phi + 1) % e == 0)
        {
            d = (k * phi + 1) / e;
            break;
        }
        k++;
    }

    printf("Public Key (e, n) = (%d, %d)\n", e, n);
    printf("Private Key (d, n) = (%d, %d)\n", d, n);

    printf("Enter message (number): ");
    scanf("%d", &msg);

    cipher = modExp(msg, e, n);
    printf("Encrypted Message = %lld\n", cipher);

    decrypt = modExp(cipher, d, n);
    printf("Decrypted Message = %lld\n", decrypt);

    return 0;
}