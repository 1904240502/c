#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* strcomb(char *str1, char *str2)
{
    char *p = str1;
    char *q = str2;
    while(*p != '\0')
        p++;
    while(*q != '\0')
    {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    return str1;
}

int main(void)
{
    char str1[20],str2[20];
    printf("请输入第一个字符串：\n");
    gets(str1);
    printf("请输入第二个字符串：\n");
    gets(str2);
    strcmp(str1,strcomb(str1,str2));
    puts(str1);
    return 0;
}