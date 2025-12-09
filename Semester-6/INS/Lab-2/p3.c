// 3)	Implement a program to read and write a text file.

#include <stdio.h>

int main() {
    FILE *fp;
    char text[200];

    fp = fopen("sample.txt", "w"); 

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter text to write into file: ");
    fgets(text, sizeof(text), stdin);

    fprintf(fp, "%s", text);  
    fclose(fp);

    fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nReading from file:\n");
    while (fgets(text, sizeof(text), fp) != NULL) {
        printf("%s", text);  
    }

    fclose(fp);

    return 0;
}