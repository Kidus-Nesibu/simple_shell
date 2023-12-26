#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* _strtok(char *str, const char *delim) {
    static char *lastToken = NULL;  // To keep track of the last token between calls

    // If str is not NULL, initialize lastToken
    if (str != NULL) {
        lastToken = str;
    } else if (lastToken == NULL) {
        return NULL;  // No more tokens if both str and lastToken are NULL
    }

    // Find the beginning of the next token (skipping delimiters)
    char *tokenStart = lastToken + strspn(lastToken, delim);

    // Check if the end of the string has been reached
    if (*tokenStart == '\0') {
        lastToken = NULL;  // No more tokens
        return NULL;
    }

    // Find the end of the token
    char *tokenEnd = tokenStart + strcspn(tokenStart, delim);

    // Replace the delimiter with a null terminator
    if (*tokenEnd != '\0') {
        *tokenEnd = '\0';
        lastToken = tokenEnd + 1;  // Set lastToken for the next call
    } else {
        lastToken = NULL;  // No more tokens after this one
    }

    return tokenStart;
}

int main() {
    char input[] = "This,is,a,sample,string";
    const char *delimiter = ",";

    char *token = _strtok(input, delimiter);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = _strtok(NULL, delimiter);
    }

    return 0;
}
