#include<stdio.h>

int main (void)
{
    while(1)
    {
        char *buff = NULL;
        size_t n;
        printf("$ ");
        getline(&buff, &n, stdin);
        /*printf("%s", buff);*/
    }
    return (0);
}