#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    fp = fopen("readfile.txt", "r");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    char c;
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;

    while ((c = fgetc(fp)) != EOF) {
        chars++;

        if (c == '\n') {
            lines++;
        }

        if (isspace(c)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    fclose(fp);

    printf("Characters: %d\n", chars);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
