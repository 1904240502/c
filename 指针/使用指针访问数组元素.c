/*
����Ԫ��: 1
2
3
4
5
���������: 
1
2
3
4
5
*/
#include <stdio.h>
 
int main()
{
   int data[5], i;
   printf("����Ԫ��: ");
 
   for(i = 0; i < 5; ++i)
     scanf("%d", data + i);
 
   printf("���������: \n");
   for(i = 0; i < 5; ++i)
      printf("%d\n", *(data + i));
 
   return 0;
}