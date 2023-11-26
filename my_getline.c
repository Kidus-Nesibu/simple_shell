#include<stdio.h>
#include<stdlib.h>
size_t my_getline(char **buff, int *n, FILE *stream);
int main(void)
{
    char *arr;
    int num;
    ssize_t get;
    get = my_getline(&arr, &num, stdin);
    printf("%s\n", arr);
    printf("%zd\n", get);
    free(arr);

    return (0);
}
size_t my_getline(char **buff, int *n, FILE *stream)
{
    if(buff == NULL || n == NULL || stream == NULL)
    {
        return (-1);
    }
    printf("all parameters are correct\n");

    if (*buff == NULL || *n == 0)
    {
        *n = 128;
        *buff = malloc(sizeof(char) * (*n));
        if (*buff == NULL)
        {
            return (-1);
        }
        printf("buffer is allocated properly\n");

    }

    int getc;
    size_t read = 0;
    char *tmp;

    getc = fgetc(stream);
    while (getc != EOF && getc != '\n')
    {
        if(read >= *n)
        {
            *n =(*n) * 2;
            tmp = malloc(sizeof(char) * (*n));
            if (tmp == NULL)
            {
                free(*buff);
                *buff = NULL;
                return (-1);
            }
            *buff = tmp;
            printf("buf is reallocated succesfully\n");
        }
        (*buff)[read++] = getc;
        getc =fgetc(stream);
        printf("the buff is not full yet\n");
    }
    printf("loop is exited\n");
    if (read < *n)
    {
        (*buff)[read] = '\0';
    }
    printf("array is null terminated\n");
    return (getc == EOF && read == 0) ? -1 : read;
}
