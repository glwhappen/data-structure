#include <stdio.h>

void InsertSort(int A[], int len) {
    int i, j, t;
    for(int i = 1; i < len; i++) { // 数组是从0开始的，但是要从1开始比较
        if(A[i - 1] > A[i]) { // 如果前面元素大于当前的，则进行插入排序
            t = A[i]; // 用临时变量存一下当前的元素，这样在后面的移动过程中就可以直接覆盖这个位置了
            for(j = i; j > 0 && A[j - 1] > t; j--) {  // 如果前面的元素大于当前的，让前面的往后挪； 注意: 一定要和临时变量t比较，A[j - 1] 不能和A[j] 比较
                A[j] = A[j - 1];
            }
            A[j] = t;
        }
    }
}

int a[100005];
int n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    InsertSort(a, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

/*
代码正确性测评：https://www.luogu.com.cn/problem/P1177
因为直接插入排序的时间复杂度为O(n^2) 所以会有两组数据超时 本题数据的超时时间是3.2秒
*/
