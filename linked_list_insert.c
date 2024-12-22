#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

//print the insertion 
void alldata(struct Node *ptr)
{
	while(ptr!= NULL)
	{
		printf("%d\n",ptr->data);
		ptr = ptr->next;
	}
}  

// case 1 insert at starting
struct Node * insertatfirst(struct Node * head,int data){
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->next = head;
	ptr->data = data;
	return ptr;
}

// case 2 insert in between
struct Node * insertatindex(struct Node * head,int data,int index){
		struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
		struct Node *p = head;
		int i = 0;
		while(i!=index-1)
		{
			p = p->next;
			i++;
		}
		ptr-> data = data;
		ptr-> next = p->next;
		p->next = ptr;
		return head;
}

// case 3 insert at the end
struct Node * insertatend(struct Node * head,int data){
		struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
		struct Node * p = head;
		ptr->data = data;
		while(p->next!=NULL)
		{
			p = p->next;
		}
	p->next = ptr;
	ptr->next = NULL;
	return head;
}

// case 4 insert at previous node
struct Node * insertatprev(struct Node * head,struct Node * prevNode,int data){
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->data = data;
	ptr->next = prevNode->next;
	prevNode->next = ptr;
	return head;
}

int main(){
	
	struct Node * head;
	struct Node * second;
	struct Node * third;
	struct Node * Fourth;
	
	head = (struct Node *) malloc(sizeof(struct Node));
	second = (struct Node *) malloc(sizeof(struct Node));
	third = (struct Node *) malloc(sizeof(struct Node));
	Fourth = (struct  Node *)malloc(sizeof(struct Node));
	
	head->data = 10;
	head->next = second;

	second->data = 20;
	second->next = third;
	
	third->data = 34;
	third->next = Fourth;

	Fourth->data = 54;
	Fourth->next = NULL;
	
	alldata(head);
    printf("\n");
	head = insertatfirst(head,45);
	alldata(head);
    printf("\n");
	head = insertatindex(head,45,3);
	alldata(head);
	
}