#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};
struct node *tree,*parsucc,*succ,*child,*ptr,*par,*root = NULL;
struct node *createnode(int item) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
struct node *insert(struct node *node, int item) {
    if (node == NULL)
        return createnode(item);
    if (item < node->data) {
        node->left = insert(node->left, item);
    } else if (item > node->data) {
        node->right = insert(node->right, item);
    }
    return node;
}
struct node *NCDelete(struct node *root,struct node *par,struct node *ptr){
	if(par==NULL)
		root=NULL;
	else if(ptr==par->left)
		par->left=NULL;
	else
		par->right=NULL;
	free(ptr);
	return root;
}
struct node *OCDelete(struct node *root,struct node *par,struct node *ptr){
	if(ptr->left!=NULL)
		child=ptr->left;
	else
		child=ptr->right;
	if(par==NULL)
		root=child;
	else if(par==ptr->left)
		par->left=child;
	else
		par->right=child;
	free(ptr);
	return root;
}
struct node *TCDelete(struct node *root,struct node *par,struct node *ptr){
	parsucc=ptr;
	succ=ptr->right;
	while(succ->left!=NULL){
		parsucc=succ;
		succ=succ->left;
	}
	ptr->data=succ->data;
	if(succ->left==NULL && succ->right==NULL)
		root=NCDelete(root,parsucc,succ);
	else
		root=OCDelete(root,parsucc,succ);
	return root;
}
struct node *delete_node(struct node *root,int item){
	ptr=root;
	par=NULL;
	while(ptr!=NULL){
		if(item==ptr->data){
			break;
		}
		par=ptr;
		if(item<ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}
	if(ptr==NULL)
		printf("Node is not present in the tree");
	else if(ptr->left!=NULL && ptr->right!=NULL)
		root=TCDelete(root,par,ptr);
	else if(ptr->left!=NULL)
		root=OCDelete(root,par,ptr);
	else if(ptr->right!=NULL)
		root=OCDelete(root,par,ptr);
	else
		root=NCDelete(root,par,ptr);
	return root;
}
void inorder(struct node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right); 
}
int main(){
	int option, item;
    do {
        printf("\n\n****MAIN MENU****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. INORDER");
        printf("\n 4. EXIT");
        printf("\n Enter the option:");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter the element:");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
            	printf("Enter the element to be deleted:");
            	scanf("%d",&item);
            	root = delete_node(root,item);
            	break;
            case 3:
		printf("Inorder traversal is given by:");
		inorder(root);
		break;
	    default:
		printf("Invalid input");
		break;
		}
     }while(option!=4);
     return 0;
 }

		
