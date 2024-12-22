#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node * left;
	struct Node * right;
};

struct Node * create(int data){
	struct Node * n = (struct Node *)malloc(sizeof(struct Node));
	n->data= data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

int isBST(struct Node * root){
static	struct Node * prev = NULL;
	if(root!=NULL){
		if(!isBST(root->left))
		{
			return 0;
		}
	if(prev!=NULL && root->data <= prev->data)
	{
		return 0;
	}
	prev=root;
	return isBST(root->right);
	}
	else {
		return 1;
	}
	
}

void inorder(struct Node * root){
	if(root!=0){
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

int main(){
	
	struct Node * N;
	struct Node * N1;
	struct Node * N2;	
	struct Node * N3;
	struct Node * N4;
	struct Node * N5;
	struct Node * N6;

	N = create(56);
	N1= create(44);
	N2 = create(78);
	N3 = create(39);
	N4 = create(45);
	N5 = create(67);
	N6 = create(89);
	
	N->left = N1;
	N->right = N2;
	N1->left = N3;
	N1->right = N4;
	N2->left = N5;
	N2->right = N6;
		
	inorder(N);
	printf("\n");
	printf("%d",isBST(N));
	
	return 0;
}