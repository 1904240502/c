#include<stdio.h>
#include<string.h>

int main()
{
    char str1[]="I love you !";
    char str2[]="she come";
    char str3[100];
    
    printf("str1 �ĳ���%d\n",strlen(str1)); 
    printf("str1�Ĵ�С%d\n",sizeof(str1));

    strcpy(str1,str2);
    strcpy(str3,"she is girl.");
    strcpy(str2,str3);

    printf("str1: %s\n",str1);
    printf("str2: %s\n",str2);
    printf("str3: %s\n",str3);

    return 0;
}
/*
str1 �ĳ���12
str1�Ĵ�С13
str1: I am boy.
str2: I am boy.
str3: she is girl.
*/
/*�н����֪
1���ַ������ɡ� ����ֵ
2���ַ����ĳ��Ȱ����ո�
3���ַ����Ĵ�С�����س����Ȳ������س���Ҫ�봢���ַ���ʱ��Ҫ���س���λ������
*/