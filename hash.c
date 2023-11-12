#include<stdio.h>
int hash[10],key,flag,i,n,found;
void insert(int item){
	int f=0;
	key=(item%10)-1;
	if(hash[key]==-1)
		hash[key]=item;
		else{
			if(key<9){
				for(i=key+1;i<10;i++){
					if(hash[i]==-1){
						hash[i]=item;
						f=1;
						break;
					}
				}
			}
			if(!f){
			for(i=0;i<key;i++){
				if(hash[i]==-1){
					hash[i]=item;
					break;
				}
			}
		}
	}
}
		void search(int item){
			key=(item%10)-1;
			flag=0;
			if(hash[key]==item)
				flag=1;
			else{
				for(i=key+1;i<10;i++)
				{
					if(hash[i]==item){
						flag=1;
						key=i;
						break;
					}
				}
			}
			if(flag==0){
				for(i=0;i<key;i++){
					if(hash[i]==item){
						flag=1;
						key=i;
						break;
					}
				}
			}
			if(flag==1){
				found=1;
				printf("Item serached was found at position %d !",key+1);
			}
			else{
				key=-1;
				printf("Item searched was not found in the hash table");
			}
		}
		void display(){
			for(i=0;i<10;i++)
				printf("\t%d",hash[i]);
			}
		int main(){
			int element,option;
			for(i=0;i<10;i++)
				hash[i]=-1;
			do{
				printf("\n 1. INSERT");
				printf("\n 2. SERACH");
				printf("\n 3. DISPLAY");
				printf("\n 4. EXIT");
				printf("\n Enter your choice:");
				scanf("%d",&option);
				switch(option){
					case 1:
						printf(" Enter the element to be inserted: ");
						scanf("%d",&element);
						insert(element);
						break;
					case 2:
						printf(" Enter element to be searched:");
						scanf("%d",&element);
						search(element);
						break;
					case 3:
						display();
						break;
					default:
						printf("Invalid option");
						break;
				}
			}while(option!=4);
			return 0;
		}
