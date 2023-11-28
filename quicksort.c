#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int left, right,pivot,loc;
int partition(int a[50],int lb,int ub){
	pivot=a[lb];
	left=lb;
	right=ub;
	while(left<right){
		while(pivot<a[right])
			right--;
		swap(&pivot,&a[right]);
		loc=right;
		while(pivot>a[left])
			left++;
		swap(&pivot,&a[left]);
		loc=left;
		}
		return loc;
}
void quicksort(int a[50],int lb,int ub){
	if(lb<ub){
		pivot=partition(a,lb,ub);
		quicksort(a,lb,pivot-1);
		quicksort(a,pivot+1,ub);
}
}
int main(){
	int a[50],i,n;
	printf("Enter the no. of items:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The array is:");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
	quicksort(a,0,n-1);
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
		printf(" %d",a[i]);
	return 0;
}	
