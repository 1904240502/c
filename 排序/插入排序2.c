#include<stdio.h>
void insertion_sort(int arr[], int len);
int main()
{
    int i,n;
    printf("������Ԫ�ظ�����");
    scanf("%d",&n);
    int a[n];
    printf("������Ԫ�أ�");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertion_sort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
void insertion_sort(int a[], int n)
{
    int i,j,temp;
    for (i=1;i<n;i++)
    {
        temp = a[i];                                //������ֵ���
        for (j=i;j>0 && a[j-1]>temp;j--)            //һֱ��ǰ������ֱ�����ֲ�����
        {
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}
