#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char** splitString(char *input, const char *delim, int *wordcount)
{
    *wordcount = 0;/*intialized wordcount*/
    char* copy = strdup(input);/*stored the duplicated string in copy string*/
    char* token = strtok(copy, delim);/*tokenized the given string*/
    
    while (token != NULL)
    {
        (*wordcount)++;/*counts the number of the words */
        token = strtok(NULL, delim);/*continues to the next word*/
    }
    free(copy);/*frees the memory allocated by the strdup function*/
    
    char **word = malloc(sizeof(char*) * (*wordcount));/*allocate memory for the tokenized words*/
    
    copy = strdup(input);/*copies the input again*/
    token = strtok(copy, delim);/*tokenize the copied string again*/
    for (int i = 0; i < (*wordcount); i++)
    {
        word[i] = strdup(token);/*stores copy of the tokenized word*/
        token = strtok(NULL, delim);/*moves to the next word*/
        /*free(token)*//*why not use this question for later*/
        
    }
    free(copy);/*frees the allocated memory by the string*/
    return (word);/*returns the word array*/
}
int main() {
    const char* input = "This is a sample string";
    const char* delim = " ";

    int wordcount;
    char** word = splitString(input, delim, &wordcount);

    printf("Number of words: %d\n", wordcount);
    for (int i = 0; i < wordcount; i++) {
        printf("Word %d: %s\n", i + 1, word[i]);
        free(word[i]);
    }

    free(word); 

    return 0;
}
