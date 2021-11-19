/**
 * @author glwhappen (1597721684@qq.com)
 * @brief 堆排序代码，经过了洛谷快速排序模板题测试
 * @version 0.1
 * @date 2021-11-19
 */

#include <stdio.h>


// 堆向下调整
void HeapAdjust(int A[], int k, int len) {
    A[0] = A[k];
    for(int i = k * 2; i <= len; i *= 2) {
        if(i < len && A[i] < A[i + 1]) { // 比较左右子树节点 如果右边大，那么走右边
            i++;
        }
        if(A[0] >= A[i]) { // 父节点与孩子节点比较 父节点比较大，不需要处理
            break;
        } else { // 如果父节点比较小，则需要交换
            A[k] = A[i]; // 把孩子节点放到双亲
            k = i; // 空出来孩子节点的位置，看这个孩子的孩子节点需不需要处理
        }
    }
    A[k] = A[0]; // 都交换完了，直接跳出
}

// 建堆
void BuildMaxHeap(int A[], int len) {
    for(int i = len / 2; i > 0; i--) {
        HeapAdjust(A, i, len);
    }
}

void swap(int &a, int &b) {
    int k = a;
    a = b;
    b = k;
}

void HeapSort(int A[], int len) {
    BuildMaxHeap(A, len);
    for(int i = len; i > 1; i--) {
        swap(A[1], A[i]);
        HeapAdjust(A, 1, i - 1);
    }
}
const int INF = 1e6 + 5;
int a[INF];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    HeapSort(a, n);
    for(int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
}

// https://www.luogu.com.cn/record/63063634