#include<stdio.h>
#include<stdlib.h>
int item,val;
struct node{
	struct node *left;
	int data;
	struct node *right;
};
struct node *createnode(int item){
	struct node *new_node =(struct node*)malloc(sizeof(struct node));
	new_node->data=item;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}
struct node *insert(struct node *node, int item){
	if(node==NULL)
		return createnode(item);
	if(item<node->data){
		node->left=insert(node->left,item);
	}
	else if(item>node->data){
		node->right=insert(node->right,item);
	}
	return node;
	}
void preorder(struct node *root){
	if(root==NULL){
		return;
	}
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
}
void inorder(struct node *root){
	if(root==NULL){
		return;
	}
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right); 
}
void postorder(struct node *root){
	if(root==NULL){
		return;
	}
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
}
int main(){
	int option,item;
	struct node *root=NULL;
	do{
		printf("\n\n****MAIN MENU****");
		printf("\n 1. INSERT");
		printf("\n 2. PREORDER");
		printf("\n 3. INORDER");
		printf("\n 4. POSTORDER");
		printf("\n 5. EXIT");
		printf("\n Enter the option:");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter the element:");
				scanf("%d",&item);
				root=insert(root,item);
				break;
			case 2:
				printf("Preorder traversal is given by:");
				preorder(root);
				break;
			case 3:
				printf("Inorder traversal is given by:");
				inorder(root);
				break;
			case 4:
				printf("Postorder traversal is given by:");
				postorder(root);
				break;
		}
		
	}while(option!=5);
    return 0;
}
