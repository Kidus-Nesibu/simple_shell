#include <stdio.h>

void tokenize(const char *str, const char *delimiters) {
    int inToken = 0;//declared variable

    while (*str) {
        if (*str == '\0') {
            break;//stops the loop if the value of str is null characther
        }

        int isDelimiter = 0;// another variable declaration
        for (const char *d = delimiters; *d; ++d) {
            if (*str == *d) {
                isDelimiter = 1;
                break;
            }
        }

        if (isDelimiter) {
            if (inToken) {
                putchar(' ');
                putchar('\0');
                inToken = 0;
            }
        } else {
            putchar(*str);
            inToken = 1;
        }

        ++str;
    }

    if (inToken) {
        putchar('\n');
    }
    printf("this is so cool\n");
}

int main() {
    const char str[] = "Hello,World,This,Is,Tokenization";
    const char delimiters[] = ",";

    tokenize(str, delimiters);

    return 0;
}
