#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Partition(int A[], int low, int high) {
    int pos = low + rand() % (high - low); // 产生一个low到high的随机数
    
    int t = A[low]; // 直接与low位置的数字交换位置，这样以后的情况就和正常的快速排序一样了
    A[low] = A[pos];
    A[pos] = t;

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
    srand((unsigned)time(NULL));
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
添加了随机选取枢纽的快速排序，只有开启O2优化才能通过，快速排序的写法很多，可能严蔚敏数据结构里面的这种写法比较适合理解，不适合实践，我用三色旗的写法写的快速排序是可以完美通过的
*/
