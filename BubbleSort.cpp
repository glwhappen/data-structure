#include <stdio.h>

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void BubbleSort(int A[], int len) {
    int i, j;
    bool flag;
    for(i = 0; i < len - 1; i++) {
        flag = false; // 表示本趟是否发生交换
        for(j = 0; j < len - i - 1; j++) { // 一趟冒泡排序，将最大的冒到最后面
            if(A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                flag = true;
            }
        }
        if(flag == false) {
            return ; // 本趟遍历后没有发生交换，说明已经有序了
        }
    }
}

void BubbleSort2(int A[], int len) {
    int i, j;
    bool flag;
    for(i = 0; i < len - 1; i++) {
        flag = false; // 表示本趟是否发生交换
        for(j = len - 1; j > i; j--) { // 一趟冒泡排序，将最小的冒到最前面
            if(A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = true;
            }
        }
        if(flag == false) {
            return ; // 本趟遍历后没有发生交换，说明已经有序了
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
    BubbleSort(a, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

/*
代码正确性测评：https://www.luogu.com.cn/problem/P1177
因为冒泡排序的时间复杂度为O(n^2) 所以肯定会超时，至少在一般的情况下没有快速排序快
冒泡排序可以加一个flag标志位来进行优化，这样在好的情况下就能达到O(n)的时间复杂度
经过测试，不加flag的代码只能通过上面题目的1组测试数据，加上flag可以通过3组，明显快了很多
*/