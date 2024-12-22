#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};


void alldata(struct Node * ptr){
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}

void sorting(struct Node * head){
	struct Node * ptr = head;
	struct Node * p = head->next;
	int temp;
	while(ptr->next!= NULL)
	{
		p=ptr->next;
		while(p!=NULL)
		{
			if(ptr->data > p->data)
			{
				temp = ptr->data;
				ptr->data = p->data;
				p->data = temp;
			}
			p=p->next;
		}
		ptr=ptr->next;
	}
}



int main(){
	
	struct Node * head;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;
	struct Node * fifth;
	struct Node * sixth;
	
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	fourth = (struct Node *)malloc(sizeof(struct Node));
	fifth = (struct Node *)malloc(sizeof(struct Node));
	sixth = (struct Node *)malloc(sizeof(struct Node));
	
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
	
	alldata(head);
	sorting(head);
	alldata(head);	
	
	
	return 0;
}