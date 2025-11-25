#include <stdio.h>

int main() {
    FILE *source, *target;
    char srcFile[100], destFile[100];
    char ch;

    printf("Enter source file name: ");
    scanf("%s", srcFile);

    printf("Enter destination file name: ");
    scanf("%s", destFile);

    source = fopen(srcFile, "r");
    target = fopen(destFile, "a");  

    while ((ch = fgetc(source)) != EOF) {
        fputc( ch, target);
    }

    fclose(source);
    fclose(target);

    printf("File appended successfully.\n");
    return 0;
}