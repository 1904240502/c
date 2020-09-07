#include<stdio.h>
int main()
{
    int a[3]={1,2,3};
    int * p=a;
    printf("a的地址是%d\n",a);
    printf("a[0]的地址是%d\n",&a[0]);
    printf("a[1]的地址是%d\n",&a[1]);
    printf("a[2]的地址是%d\n",&a[2]);
    printf("p的值指向的值是%d\n",*p);
    printf("p+1的值指向的值是%d\n",*(p+1));
    printf("p+2的值指向的值是%d\n",*(p+2));
    printf("p的值是%d\n",p);
    printf("p+1的值是%d\n",p+1);
    printf("p+2的值是%d\n",p+2);
    printf("p的地址是%d\n",&p);
    return 0;
}
/*
a的地址是6422036
a[0]的地址是6422036
a[1]的地址是6422040
a[2]的地址是6422044
p的值指向的值是1
p+1的值指向的值是2
p+2的值指向的值是3
p的值是6422036
p+1的值是6422040
p+2的值是6422044
p的地址是6422024
*/
/*由结果可知
1，数组名代表数组的首地址
2，指针变量中存放的是地址
3，指针值+1相当与数组的地址向后移动一位
4，* p是指针变量中所储存位置指向的值
*/