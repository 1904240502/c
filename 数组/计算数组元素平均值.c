#include <stdio.h>
 
int main()
{
    int n, i;
    float num[100], sum = 0.0, average;
 
    printf("����Ԫ�ظ���: ");
    scanf("%d", &n);
 
    while (n > 100 || n <= 0)
    {
        printf("Error! ������Ҫ��1 �� 100 ֮�䡣\n");
        printf("�ٴ�����: ");
        scanf("%d", &n);
    }
 
    for(i = 0; i < n; ++i)
    {
        printf("%d. ��������: ", i+1);
        scanf("%f", &num[i]);
        sum += num[i];
    }
 
    average = sum / n;
    printf("ƽ��ֵ = %.2f", average);
 
    return 0;
}