#include <stdio.h>

int Partition(int A[], int low, int high) {
    int pivot = A[low]; // n. 枢轴, 中心点;
    while(low < high) {
        while(low < high && A[high] >= pivot) high--;
        // 此时high指向的位置比pivot小，并且low这个位置的数字已经存到pivot里面了，可以直接覆盖
        A[low] = A[high];
        while(low < high && A[low] <= pivot) low++;
        // 此时low指向的位置比pivotda，需要放到最右边需要的位置，high这个位置刚刚好
        A[high] = A[low];
    }
    A[low] = pivot; // 将枢轴元素放到中间
    return low; // 返回中间的值，以便二分查找使用
}

void QuickSort(int A[], int low, int high) {
    if(low < high) {
        int mid = Partition(A, low, high); // 和二分查找很像，只不过不需要计算中间值了，而是通过Partition函数来划分
        QuickSort(A, low, mid - 1); // 中间的mid已经是正确的位置了，所以可以直接不管中间的mid
        QuickSort(A, mid + 1, high);
    }
}

int a[100005];
int n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    QuickSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

/*
代码正确性测评：https://www.luogu.com.cn/problem/P1177
快速排序的平均时间复杂度为O(nlogn)，但是如果数组基本有序，则会降到O(n^2)，原因是每次划分的时候，选择的枢纽太不平均，可能每次都是最小的，这样就会划分成一个只有左孩子或右孩子的树，导致效率降低
这个代码时间太慢就是因为pivot每次都选择的第一个下标里面的数字，可能测试数据有基本排好序的情况
*/
