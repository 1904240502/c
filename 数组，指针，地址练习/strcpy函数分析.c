#include<stdio.h>
#include<string.h>

int main()
{
    char str1[]="123456";                       //数组初始化 123456 六个字符+一个'\0'=7  字符串大小为7  长度为6
    char str2[]="789";
    char str3[100];                             //没有初始化默认为 0
    printf("原str1的长度%d\n",strlen(str1)); 
    printf("原str1的大小%d\n",sizeof(str1));
    printf("原str2的长度%d\n",strlen(str2)); 
    printf("原str2的大小%d\n\n",sizeof(str2));
    

    strcpy(str1,str2);
    printf("str1: %s\n",str1);
    printf("str2: %s\n",str2);
    printf("str1的第6位为%c\n",str1[5]);
    printf("中str1的长度%d\n",strlen(str1)); 
    printf("中str1的大小%d\n",sizeof(str1));
    printf("中str2的长度%d\n",strlen(str2)); 
    printf("中str2的大小%d\n\n",sizeof(str2));
    strcpy(str3,"abcdefghijklmn");
    printf("原str3的长度%d\n",strlen(str3));
    strcpy(str2,str3);
    printf("str1: %s\n",str1);
    printf("str2: %s\n",str2);
    printf("str3: %s\n",str3);
    printf("str1的第6位为%c\n",str1[5]);
    printf("现str1的长度%d\n",strlen(str1)); 
    printf("现str1的大小%d\n",sizeof(str1));
    printf("现str2的长度%d\n",strlen(str2)); 
    printf("现str2的大小%d\n",sizeof(str2));
    printf("现str3的长度%d\n",strlen(str3)); 
    return 0;
}
/*
原str1的长度6
原str1的大小7 
原str2的长度3 
原str2的大小4 

str1: 789
str2: 789
str1的第6位为6
中str1的长度3
中str1的大小7
中str2的长度3
中str2的大小4

原str3的长度14
str1: efghijklmn
str2: abcdefghijklmn
str3: abcdefghijklmn
str1的第6位为j
现str1的长度10
现str1的大小7
现str2的长度14
现str2的大小4
现str3的长度14
*/
/*有结果可知
1，字符串可由“ ”赋值
2，字符串的长度包括'\n'
3，字符串的大小包括'\n'，要想储存字符串时需要将'\n'的位置留出      大小=长度+1
4，strcpy遇到'\n'才会停止复制,如果strcpy(a,b) 且 a<b会使a的值溢出直到复制到b的'\n'   （如：上面现str1与str2的情况）
5，strcpy的返回值是 char * 是地址这也就是为什么在str3复制到str2时会改变str1的值
*/