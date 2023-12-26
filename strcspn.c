#include<stdio.h>
#include<string.h>
int main ()
{
    char *str = "afkaghasdjf123415";
    char *num = "123456789";

    int cnt = strcspn(str, num);
    char *bfr =  str + cnt;
    printf("%s\n", bfr);


    printf("%d\n", cnt);

    return (0);
}