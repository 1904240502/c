//使用strcpy
#include<stdio.h>
#include <string.h>
 
int main()
{
   char src[40];
   char dest[100];
  
   strcpy(src, "This is runoob.com");
   strcpy(dest, src);
 
   printf("最终的目标字符串： %s\n", dest);
   
   return(0);
}