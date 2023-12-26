#include<stdio.h>
#include<string.h>
int main()
{
    /*char *s = "1234152452345625this is so cool";
    char *num = "123456789";
    int pos = strspn(s, num);
    char *remaining = s+pos;
    printf("%s\n", remaining);
    printf("%d\n", pos);*/
    const char *str1 = "Hllo123";
    const char *str2 = "Hlo";
    size_t length = strspn(str1, str2); // Returns 5
    printf("%lu\n", length);

    return (0);
}