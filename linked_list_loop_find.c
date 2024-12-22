#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * prev;
	struct Node * next;
};

void alldata(struct Node * ptr){
	struct Node * tail = NULL;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		tail = ptr;
		ptr=ptr->next;
		
	}
		ptr=tail;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->prev;
	}
}

void findloop(struct Node * ptr){
	struct Node * p = ptr;
	struct Node * q = ptr->next;
	
	while(p!=NULL)
	{
		while(q!=NULL)
		{ 
			if(p==q)
			{
				printf("TRUE");
				return;
			}
			else
			{
				q=q->next;
			}
			
		}
	p=p->next;
	}
		printf("FALSE");
}

int main(){
	
	struct Node * N1 = (struct Node *)malloc(sizeof(struct Node));
	struct Node * N2 = (struct Node *)malloc(sizeof(struct Node));
	struct Node * N3 = (struct Node *)malloc(sizeof(struct Node));
	struct Node * N4 = (struct Node *)malloc(sizeof(struct Node));
	struct Node * N5 = (struct Node *)malloc(sizeof(struct Node));
	struct Node * N6 = (struct Node *)malloc(sizeof(struct Node));	
	
	N1->data = 45;
	N1->prev = N6;
	N1->next = N2;
	
	N2->data = 56;
	N2->prev = N1;
	N2->next = N3;
	
	N3->data = 87;
	N3->prev = N2;
	N3->next = N4;
	
	N4->data = 89;
	N4->prev = N3;
	N4->next = N5;
	
	N5->data = 92;
	N5->prev = N4;
	N5->next = N6;
	
	N6->data = 94;
	N6->prev = N5;
	N6->next = N1;
	
	
	findloop(N1);
	
	return 0;
}