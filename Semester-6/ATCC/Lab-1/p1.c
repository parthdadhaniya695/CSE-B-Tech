#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char  filename[] = "du.txt";
    char ch;
    int chars = 0, spaces = 0, tabs = 0, newlines = 0;
    fp = fopen(filename, "r");
    ch = fgetc(fp);
    while (ch != EOF) {
        if (ch == ' ')
            spaces++;
        else if (ch == '\t')
            tabs++;
        else if (ch == '\n')
            newlines++;
        else
            chars++;
        ch = fgetc(fp);
    }
    fclose(fp);
    printf("Characters: %d\n", chars);
    printf("Spaces: %d\n", spaces);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}