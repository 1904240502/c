#include<stdio.h>
#include<string.h>

int main()
{
    char str1[]="123456";                       //�����ʼ�� 123456 �����ַ�+һ��'\0'=7  �ַ�����СΪ7  ����Ϊ6
    char str2[]="789";
    char str3[100];                             //û�г�ʼ��Ĭ��Ϊ 0
    printf("ԭstr1�ĳ���%d\n",strlen(str1)); 
    printf("ԭstr1�Ĵ�С%d\n",sizeof(str1));
    printf("ԭstr2�ĳ���%d\n",strlen(str2)); 
    printf("ԭstr2�Ĵ�С%d\n\n",sizeof(str2));
    

    strcpy(str1,str2);
    printf("str1: %s\n",str1);
    printf("str2: %s\n",str2);
    printf("str1�ĵ�6λΪ%c\n",str1[5]);
    printf("��str1�ĳ���%d\n",strlen(str1)); 
    printf("��str1�Ĵ�С%d\n",sizeof(str1));
    printf("��str2�ĳ���%d\n",strlen(str2)); 
    printf("��str2�Ĵ�С%d\n\n",sizeof(str2));
    strcpy(str3,"abcdefghijklmn");
    printf("ԭstr3�ĳ���%d\n",strlen(str3));
    strcpy(str2,str3);
    printf("str1: %s\n",str1);
    printf("str2: %s\n",str2);
    printf("str3: %s\n",str3);
    printf("str1�ĵ�6λΪ%c\n",str1[5]);
    printf("��str1�ĳ���%d\n",strlen(str1)); 
    printf("��str1�Ĵ�С%d\n",sizeof(str1));
    printf("��str2�ĳ���%d\n",strlen(str2)); 
    printf("��str2�Ĵ�С%d\n",sizeof(str2));
    printf("��str3�ĳ���%d\n",strlen(str3)); 
    return 0;
}
/*
ԭstr1�ĳ���6
ԭstr1�Ĵ�С7 
ԭstr2�ĳ���3 
ԭstr2�Ĵ�С4 

str1: 789
str2: 789
str1�ĵ�6λΪ6
��str1�ĳ���3
��str1�Ĵ�С7
��str2�ĳ���3
��str2�Ĵ�С4

ԭstr3�ĳ���14
str1: efghijklmn
str2: abcdefghijklmn
str3: abcdefghijklmn
str1�ĵ�6λΪj
��str1�ĳ���10
��str1�Ĵ�С7
��str2�ĳ���14
��str2�Ĵ�С4
��str3�ĳ���14
*/
/*�н����֪
1���ַ������ɡ� ����ֵ
2���ַ����ĳ��Ȱ���'\n'
3���ַ����Ĵ�С����'\n'��Ҫ�봢���ַ���ʱ��Ҫ��'\n'��λ������      ��С=����+1
4��strcpy����'\n'�Ż�ֹͣ����,���strcpy(a,b) �� a<b��ʹa��ֵ���ֱ�����Ƶ�b��'\n'   ���磺������str1��str2�������
5��strcpy�ķ���ֵ�� char * �ǵ�ַ��Ҳ����Ϊʲô��str3���Ƶ�str2ʱ��ı�str1��ֵ
*/