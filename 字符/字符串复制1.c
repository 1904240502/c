//ʹ��strcpy
#include<stdio.h>
#include <string.h>
 
int main()
{
   char src[40];
   char dest[100];
  
   strcpy(src, "This is runoob.com");
   strcpy(dest, src);
 
   printf("���յ�Ŀ���ַ����� %s\n", dest);
   
   return(0);
}