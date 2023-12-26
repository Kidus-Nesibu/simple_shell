#include<stdio.h>
int main ()
{
    const int x = 20;
    int y = 23;
    x < y? printf("x\n") : printf("y\n");
    printf("%d", x);
    return(0);
}