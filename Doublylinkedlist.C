//WAP to implement doubly Linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *previous;
	struct node *next;
};
struct node *head,*tail=NULL;
int addNode(int data){
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	if(head==NULL){
		head=tail=newNode;
		head->previous=NULL;
		tail->next=NULL;
	}
	else{
		tail->next=newNode;
		newNode->previous=tail;
		tail=newNode;
		tail->next=NULL;
	}
}
int display(){
	struct node*current=head;
	if(head==NULL){
		printf("List is empty\n");
		return 0;
	}
	printf("Nodes of doubly Linked list:\n");
	while(current!=NULL){
		printf("%d",current->data);
		current=current->next;
	}
}
int insertFront(struct node** head,int data){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=(*head);
	newNode->previous=NULL;
	if((*head)!=NULL)
	(*head)->previous=newNode;
	(*head)=newNode;
}
int insertEnd(struct node** head,int data){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	struct node *temp=*head;
	if(*head==NULL){
		newNode->previous=NULL;
		*head=newNode;
		return 0;
	}
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=newNode;
	newNode->previous=temp;
}
int deleteNode(struct node** head,struct node* del_node){
	if(*head==NULL||del_node==NULL)
	return 0;
	if(*head==del_node)
	*head=del_node->next;
	if(del_node->next!=NULL)
	del_node->next->previous=del_node->previous;
	if(del_node->previous!=NULL)
	del_node->previous->next=del_node->next;
	free(del_node);
	
}
int insertAfter(struct node* previous_node,int data){
	if(previous_node==NULL){
		printf("previous node cannot be null");
		return 0;
	}
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=previous_node->next;
	previous_node->next=newNode;
	newNode->previous=previous_node;
	if(newNode->next!=NULL)
	newNode->next->previous=newNode;
	
}
int main()
{
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);
	display();
	insertAfter(head->next,9);
	display();
	return 0;
}
