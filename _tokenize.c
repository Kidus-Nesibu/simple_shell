#include<stdio.h>
#include<string.h>
char * tokenize(char *str, char *delim)
{
    //int i = 0;
    while (*str)
    {    
        if (*str == '\0')
        {
            break;
        }
        if(*str = *delim)
        {
            *str = '\0';
            str++;
        }
        str++;
    }   
    return (str);
}

int main() {
    const char str[] = "Hello,World,This,Is,Tokenization";
    const char delimiters[] = ",";

    char *ans = 
    tokenize(str, delimiters);
    printf("%s\n", ans);
    return 0;
}