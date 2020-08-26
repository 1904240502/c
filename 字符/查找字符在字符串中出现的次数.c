/*
fgets(s,n,fp)。s可以是一个字符数组名，或是指向字符串的指针；n为要读取的最多的字符个数：fp是指向该文件的文件型指针。字符串输入函数的功能是：从fp所指向的文件中读取长度不超过n-1个字符的字符串，并将该字符串存放到字符数组s中。
*/
#include <stdio.h>
 
int main()
{
   char str[1000], ch;
   int i, frequency = 0;
 
   printf("输入字符串: ");
   fgets(str, (sizeof str / sizeof str[0]), stdin);
 
   printf("输入要查找的字符: ");
   scanf("%c",&ch);
 
   for(i = 0; str[i] != '\0'; ++i)
   {
       if(ch == str[i])
           ++frequency;
   }
 
   printf("字符 %c 在字符串中出现的次数为 %d", ch, frequency);
 
   return 0;
}