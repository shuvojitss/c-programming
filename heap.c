#include<stdio.h>
int i,x;
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
void delete_root(int a[],int n){
	if(n<=0){
		printf("Heap is empty");
		return;
	a[0]=a[n-1];
	n--;
	heapify(a,n,0);
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
    buildHeap(a,n);
    printf("The heap is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
        while(!x){
        	printf("Do you want to delete the heap:");
        	scanf("%d",&x);
        	delete_root(a,n);
        	heapify(a,n,0);
        	for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
		}
    return 0;
}
