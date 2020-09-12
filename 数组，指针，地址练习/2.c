#include<stdio.h>
#include<string.h>

int main()
{
    char str1[]="I love you !";
    char str2[]="she come";
    char str3[100];
    
    printf("str1 的长度%d\n",strlen(str1)); 
    printf("str1的大小%d\n",sizeof(str1));

    strcpy(str1,str2);
    strcpy(str3,"she is girl.");
    strcpy(str2,str3);

    printf("str1: %s\n",str1);
    printf("str2: %s\n",str2);
    printf("str3: %s\n",str3);

    return 0;
}
/*
str1 的长度12
str1的大小13
str1: I am boy.
str2: I am boy.
str3: she is girl.
*/
/*有结果可知
1，字符串可由“ ”赋值
2，字符串的长度包括空格
3，字符串的大小包括回车长度不包括回车，要想储存字符串时需要将回车的位置留出
*/