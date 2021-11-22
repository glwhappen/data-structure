/**
 * @author glwhappen (1597721684@qq.com)
 * @brief 快速排序代码，经过了洛谷快速排序模板题测试
 * @version 0.1
 * @date 2021-11-19
 */
#include <stdio.h>
#include <stdlib.h>

int n;

int *B; // 辅助数组

void Merge(int A[], int low, int mid, int heigh) {
    for(int i = low; i <= heigh; i++) {
        B[i] = A[i];
    }
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= heigh) {
        if(B[i] <= B[j]) { // 比较i和j对应的数，谁大谁小
            A[k] = B[i++];
        } else {
            A[k] = B[j++];
        }
        k++;
    }
    while(i <= mid) A[k++] = B[i++];
    while(j <= heigh) A[k++] = B[j++];
}

void MergeSort(int A[], int low, int heigh) {
    if(low < heigh) {
        int mid = (low + heigh) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, heigh);
        Merge(A, low, mid, heigh);
    }
}

int a[100005];
int main() {
    scanf("%d", &n);
    B = (int *)malloc(n * sizeof(int)); // 辅助数组
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    MergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

// https://www.luogu.com.cn/problem/P1177