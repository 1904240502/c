#include<stdio.h>
int exchange(int a[],int n,int m);
int main()
{
    int i,n,m,x;
    printf("������Ԫ�ظ�����");
    scanf("%d",&n);
    int a[n];
    printf("������Ԫ�أ�");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("������Ҫ����Ԫ�أ�");
    scanf("%d",&m);
    x=exchange(a,n,m);
    if(x==-1)
    {
        printf("û�в��ҵ�");
    }
    else
    {
        printf("%d�ڵ�%dλ",m,x+1);
    }
    
    return 0;
}
int exchange(int a[],int n,int m)
{
    int begin,end,mid;
    end=n;
    begin=0;
    while(end>begin)                          //����ҿ�[begin,end) begin==endʱ�ǲ���λ��
    {
        mid=(end+begin)/2;
        if(a[mid]>m)
        {
            end=mid;
        }
        else if(a[mid]<m)
        {
            begin=mid;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
