//������
#include<stdio.h>
void exchange(int a[],int n);
void swap(int *x, int *y);
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
    exchange(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
typedef struct _Range {
    int start, end;
} Range;
Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void exchange(int arr[], const int len) {
    if (len <= 0)
        return; // ����len��Ϊ��ֵʱ�����δ���Segment Fault��
    // r[]ģ���б�,pΪ����,r[p++]Ϊpush,r[--p]Ϊpop��ȡ��Ԫ��
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        int mid = arr[(range.start + range.end) / 2]; // ��ȡ�м��Ϊ��׼��
        int left = range.start, right = range.end;
        do
        {
            while (arr[left] < mid) ++left;   // ����׼������Ƿ����Ҫ��
            while (arr[right] > mid) --right; //����׼���Ҳ��Ƿ����Ҫ��
 
            if (left <= right)
            {
                swap(&arr[left],&arr[right]);
                left++;right--;               // �ƶ�ָ���Լ���
            }
        } while (left <= right);
 
        if (range.start < right) r[p++] = new_Range(range.start, right);
        if (range.end > left) r[p++] = new_Range(left, range.end);
    }
}