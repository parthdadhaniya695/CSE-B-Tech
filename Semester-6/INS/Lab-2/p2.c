// 2)	Implement string functions like strlen, strcat, and strcmp.

#include <stdio.h>

int my_strlen(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void my_strcat(char dest[], char src[]) {
    int i = 0, j = 0;

    while (dest[i] != '\0') {
        i++;
    }

    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0'; 
}

int my_strcmp(char s1[], char s2[]) {
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }

    return s1[i] - s2[i];  
}

int main() {
    char s1[100], s2[100];

    printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);

    for (int i = 0; s1[i]; i++)
        if (s1[i] == '\n') s1[i] = '\0';

    for (int i = 0; s2[i]; i++)
        if (s2[i] == '\n') s2[i] = '\0';

    printf("\nLength of s1 : %d\n", my_strlen(s1));
    printf("Length of s2 : %d\n", my_strlen(s2));

    my_strcat(s1, s2);
    printf("After concatenation (s1 + s2): %s\n", s1);

    int result = my_strcmp(s1, s2);

    if (result == 0)
        printf("Strings are equal.\n");
    else if (result > 0)
        printf("s1 is greater than s2.\n");
    else
        printf("s1 is smaller than s2.\n");

    return 0;
}
