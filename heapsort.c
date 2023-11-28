#include<stdio.h>
void heapify(int a[], int n, int i) {
    int left, right, largest, temp;
    left = 2 * i + 1;
    right = 2 * i + 2;
    largest = i;    
    if (left <= n - 1 && a[left] > a[largest])
        largest = left;
    if (right <= n - 1 && a[right] > a[largest])
        largest = right;
    if (i != largest) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}
void buildHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}
void heapSort(int a[], int n) {
    buildHeap(a, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
int main() {
    int n;
    printf("Enter the size of the heap: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the heap: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("The heap is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    heapSort(a, n);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
