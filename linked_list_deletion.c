#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node * next;
};

void alldata(struct Node * ptr){
	while(ptr!=0)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}

// case 1 deleting first
struct Node * deletefirst(struct Node * head){

	struct Node * ptr = head;
	head = head->next;
	free(ptr);
	return head;
}
// case 2 deleting in between
struct Node * deleteatindex(struct Node * head,int index){
	struct Node * p = head;
	int i=0;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	
	struct Node * q = p->next;
	p->next = q->next;
	free(q);
	return head;
}

// case 3 deleting end
struct Node * deleteatend(struct Node * head){
	struct Node * p = head;
	struct Node * q = head->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
		
	}
	
	p->next = NULL;
	free(q);
	return head;
}

// case 4 deleteatdata
struct Node * deleteatdata(struct Node * head,int data){
	struct Node * p = head;
	struct Node * q = head->next;
	while(q->data!=data)
	{
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	return head;
}

int main(){
	
	struct Node * head;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;
	
	
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	fourth = (struct Node *)malloc(sizeof(struct Node));
	
	head->data = 10;
	head->next = second;
	
	second->data = 20;
	second->next = third;
	
	third->data = 34;
	third->next = fourth;
	
	fourth->data = 54;
	fourth->next = NULL;
	
	alldata(head);
	head = deletefirst(head);
	printf("\n");
	alldata(head);
	head = deleteatindex(head,2);
	printf("\n");
	alldata(head);
	head = deleteatend(head);
	printf("\n");
	alldata(head);
	// head = deleteatdata(head,36);
	// alldata(head); 
	 
	return 0;
}
