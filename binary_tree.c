#include<stdio.h>
#include<stdlib.h>


struct Node{
	int data;
	struct Node * left;
	struct Node * right;
	
};

struct Node * create(int data){
	struct Node * n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
	
}



int main(){
	struct Node * N =  create(56);
	struct Node * N1 = create(76);
	struct Node * N2 = create(78);
	
	N->left = N1;
	N->right = N2;
	
	
	return 0;
}
