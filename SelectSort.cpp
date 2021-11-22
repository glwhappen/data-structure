#include <stdio.h>

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void SelectSort(int A[], int len) {
    int i, j, min;
    for(i = 0; i < len; i++) {
        min = i;
        for(j = i + 1; j < len; j++) {
            if(A[min] > A[j]) {
                min = j;
            }
        }
        if(min != i) {
            swap(A[min], A[i]);
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
    SelectSort(a, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

/*
代码正确性测评：https://www.luogu.com.cn/problem/P1177
因为简单选择排序的时间复杂度为O(n^2) 比较次数还很多 所以会有四组数据超时
*/
