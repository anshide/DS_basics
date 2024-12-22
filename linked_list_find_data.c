#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

void alldata(struct Node * ptr){
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
}

struct Node * finddata(struct Node *head,int data){
	struct Node * p =head;
	int i=1;
	while(p->data!=data)
	{
		p=p->next;
		i=i+1;
	}
	printf("%d",i);
    return head;
}

int main(){
	
	struct Node * head = (struct Node *)malloc(sizeof(struct Node));
	struct Node * second= (struct Node *)malloc(sizeof(struct Node));
	struct Node * third= (struct Node *)malloc(sizeof(struct Node));
	struct Node * fourth= (struct Node *)malloc(sizeof(struct Node));
	struct Node * fifth= (struct Node *)malloc(sizeof(struct Node));
	struct Node * sixth= (struct Node *)malloc(sizeof(struct Node));
	
	head->data = 97;
	head->next = second;
	
	second->data = 56;
	second->next = third;
	
	third->data = 87;
	third->next = fourth;
	
	fourth->data = 67;
	fourth->next = fifth;
	
	fifth->data = 85;
	fifth->next = sixth;
	
	sixth->data = 68;
	sixth->next = NULL;
	
	finddata(head,56);
	
	
	
	return 0;
}

