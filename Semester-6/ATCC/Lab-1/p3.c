#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp, *out;
    int ch;
    int start = 1; 

    fp = fopen("du2.txt", "r");
    if (fp == NULL) {
        printf("Input file not found!\n");
        return 1;
    }

    out = fopen("output.txt", "w");

    while ((ch = fgetc(fp)) != EOF) {

        if (start && isalpha(ch)) {
            ch = toupper(ch);  
            start = 0;
        }

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            start = 1;
        }

        fputc(ch, out);
    }

    fclose(fp);
    fclose(out);

    printf("New file created successfully (output.txt)\n");

    return 0;
}