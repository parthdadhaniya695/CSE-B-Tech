// "To write a C program that reads a source file, removes all single-line (//) and multi-line (/* ... */) comments from the code, and writes the cleaned output into another file."

#include <stdio.h>

int main() {
    FILE *src, *dest;
    int c;

    src = fopen("input.txt", "r");
    dest = fopen("output.txt", "w");

    if (!src || !dest) {
        printf("Error opening files!\n");
        return 1;
    }

    while ((c = fgetc(src)) != EOF) {

        if (c == '/') {
            int temp = fgetc(src);   

            if (temp == '/') {
                while ((c = fgetc(src)) != EOF && c != '\n');
                fputc('\n', dest);
                continue;
            }

            else if (temp == '*') {
                while (1) {
                    c = fgetc(src);
                    if (c == EOF) break;

                    if (c == '*') {
                        int t = fgetc(src);
                        if (t == '/') break;
                        else ungetc(t, src);
                    }
                }
                continue;
            }

            else {
                fputc('/', dest);
                ungetc(temp, src);
                continue;
            }
        }

        fputc(c, dest);
    }

    fclose(src);
    fclose(dest);

    printf("Comments removed and saved to output.txt successfully!\n");
    return 0;
}
