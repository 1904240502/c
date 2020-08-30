//迭代法
#include<stdio.h>
void exchange(int a[],int n);
void swap(int *x, int *y);
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
        return; // 避免len等为负值时引发段错误（Segment Fault）
    // r[]模拟列表,p为数量,r[p++]为push,r[--p]为pop且取得元素
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        int mid = arr[(range.start + range.end) / 2]; // 获取中间点为基准点
        int left = range.start, right = range.end;
        do
        {
            while (arr[left] < mid) ++left;   // 检测基准点左侧是否符合要求
            while (arr[right] > mid) --right; //检测基准点右侧是否符合要求
 
            if (left <= right)
            {
                swap(&arr[left],&arr[right]);
                left++;right--;               // 移动指针以继续
            }
        } while (left <= right);
 
        if (range.start < right) r[p++] = new_Range(range.start, right);
        if (range.end > left) r[p++] = new_Range(left, range.end);
    }
}