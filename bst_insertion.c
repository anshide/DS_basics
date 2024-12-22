#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * left;
	struct Node * right;
};

struct Node * create(int number){
	struct Node * n = (struct Node *)malloc(sizeof(struct Node));
	n->data = number;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void inorder(struct Node * root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

void insert(struct Node * root,int index){
	struct Node * prev = NULL;
	while(root!=NULL){
	prev = root;
	if(root->data == index)
	{
		printf("cannot insert\n");
		return;
	}
	if(root->data>index)
	{
		root = root->left;
	}
	else
	{
		root=root->right;
	}
}

struct Node * New = create(index);
if(prev->data>index)
{
	prev->right = New;
}
else
{
	prev->left = New;
}
}

int main(){
	
	struct Node * N = create(56);
	struct Node * N1 = create(45);
	struct Node * N2 = create(67);
	struct Node * N3 = create(34);
	struct Node * N6 = create(89);
	
	N->left = N1;
	N->right = N2;
	N2->left = N3;
	N2->right = N6;
	
	inorder(N);
	printf("\n");
	insert(N,90);
	inorder(N);
	
	
	return 0;
}