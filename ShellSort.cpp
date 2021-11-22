#include <stdio.h>

void ShellSort(int A[], int len) {
    int i, j, d, t;
    for(d = len / 2; d > 0; d /= 2) { // 步长变化
        for(i = 1; i < len; i += d) { // 下面跟直接插入排序一模一样，只是i每次加d
            if(A[i - 1] > A[i]) {
                t = A[i];
                for(j = i; j > 0 && A[j - 1] > t; j--) {
                    A[j] = A[j - 1];
                }
                A[j] = t;
            }
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
    ShellSort(a, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

/*
代码正确性测评：https://www.luogu.com.cn/problem/P1177
希尔排序的时间复杂度还没有解决，但是最坏的情况下是O(n^2) 当n在某个特定范围时，希尔排序的时间复杂度约为O(n^1.3) 所以会有两组数据超时
100,000 这个数据范围为需要执行相对时间 25,624,830
O(nlogn)的算法为  1,312,236 很明显差一个数量级
*/