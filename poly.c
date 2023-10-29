#include<stdio.h>
#include<stdlib.h>
struct poly{
	int coeff;
	int expo_x;
	int expo_y;
	struct poly *next;
};
struct poly *ptr,*temp,*new_poly,*head=NULL;
struct poly*createpoly(int a, int b, int data){
	new_poly=(struct poly*)malloc(sizeof(struct poly));
	new_poly->coeff=data;
	new_poly->expo_x=a;
	new_poly->expo_y=b;
	new_poly->next=NULL;
	return new_poly;
}
void insert(int a, int b, int data){
	new_poly=createpoly(a,b,data);
	if(head==NULL){
		head=new_poly;
		return;
	}
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_poly;
}
void display(){
	if(head==NULL){
		printf("Empty list");
		return;
	}
	ptr=head;
	printf("The polynomial is:");
	while(ptr!=NULL){
		if(ptr->coeff>0)
			printf(" + ");	
		printf("%d*x^%d*y^%d",ptr->coeff,ptr->expo_x,ptr->expo_y);
		ptr=ptr->next;
	}
}
int main(){
	int option,coef,exp_x,exp_y;
	do{
		printf("\n 1.INSERT");
		printf("\n 2.DISPLAY");
		printf("\n 3.EXIT");
		printf("\n Enter your choice:");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter coeff:");
				scanf("%d",&coef);
				printf("Enter exponent of x:");
				scanf("%d",&exp_x);
				printf("Enter exponent of y:");
				scanf("%d",&exp_y);
				insert(exp_x,exp_y,coef);
				break;
			case 2:
				display();
				break;
			}
		}while(option!=3);
		return 0;
	}
