#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char *buff = NULL;
    size_t n;
    printf("enter some text\n");
    getline(&buff, &n, stdin);
    printf("size: %ld\n", n);
    printf("text: %s\n", buff);
    free(buff);
    return (0);
}