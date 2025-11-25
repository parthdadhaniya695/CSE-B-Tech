#include <stdio.h>

int main() {
    FILE *source, *target;
    char srcFile[100], destFile[100];
    char buffer[1000];  // temporary buffer for reading text

    printf("Enter source file name: ");
    scanf("%s", srcFile);

    printf("Enter destination file name: ");
    scanf("%s", destFile);

    source = fopen(srcFile, "r");
    target = fopen(destFile, "a");  

    if (source == NULL || target == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fscanf(source, "%[^\n]\n", buffer) != EOF) {
        fprintf(target, "%s\n", buffer);
    }

    fclose(source);
    fclose(target);

    printf("File appended successfully.\n");
    return 0;
}