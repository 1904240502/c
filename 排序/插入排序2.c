#include<stdio.h>
void insertion_sort(int arr[], int len);
int main()
{
    int i,n;
    printf("请输入元素个数：");
    scanf("%d",&n);
    int a[n];
    printf("请输入元素：");
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
        temp = a[i];                                //待插入值标记
        for (j=i;j>0 && a[j-1]>temp;j--)            //一直向前交换，直到出现不满足
        {
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}
