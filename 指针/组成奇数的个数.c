//求0—7所能组成的奇数个数。
/*
1位数为奇数的个数4
2位数为奇数的个数28
3位数为奇数的个数224
4位数为奇数的个数1792
5位数为奇数的个数14336
6位数为奇数的个数114688
7位数为奇数的个数917504
8位数为奇数的个数7340032
奇数的总个数为：8388608
*/
#include<stdio.h>
int main(int agrc, char*agrv[])
{
    long sum = 4, s = 4;//sum的初始值为4表示，只有一位数字组成的奇数个数为4个
    int j;
    for (j = 2; j <= 8; j++)
    {    
        printf("%d位数为奇数的个数%ld\n", j-1, s);
        if (j <= 2)
            s *= 7;
        else
            s *= 8;
        sum += s;    
    }
    printf("%d位数为奇数的个数%ld\n", j-1, s);
    printf("奇数的总个数为：%ld\n", sum);
    // system("pause");
    return 0;
}