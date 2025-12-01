// Write a C program to implement left and right circular bit rotations.

#include <stdio.h>

int main() {
    unsigned int num, n, left_rotate, right_rotate;
    int bits = 32;  // assume 32-bit unsigned int

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Enter number of positions to rotate: ");
    scanf("%u", &n);

    n %= bits;  // to avoid rotating more than 32

    // Left circular rotation
    left_rotate = (num << n) | (num >> (bits - n));

    // Right circular rotation
    right_rotate = (num >> n) | (num << (bits - n));

    printf("\nOriginal Number: %u\n", num);
    printf("After Left Circular Rotation : %u\n", left_rotate);
    printf("After Right Circular Rotation: %u\n", right_rotate);

    return 0;
}