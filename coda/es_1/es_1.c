#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

Node* dequeue(Node **head,Node **tail){
    Node *ret=*head;

	if(*head == NULL){
		return NULL;
	}
	else
		(*head)=ret->next;
	if(*head == NULL)
		*tail=NULL;
	return ret;
}

void enqueue(Node **head, Node **tail,Node *element){
	if(*head==NULL){
		*head=element;
	}
	else {
        (*tail)->next=element;
    }

	*tail=element;
	element->next=NULL;
}

int main(){
    Node *head;
    Node *tail;
    Node *element;
    Node *tmp = head;
    Node *var;
    int val;
    int rp=1;

    head=NULL;
    tail=NULL;
    element=(Node*)malloc(sizeof(Node));
    while(rp==1){
        element=(Node*)malloc(sizeof(Node));
        printf("input a number: ");
        scanf("%d",&val);
        element->value=val;
        enqueue(&head,&tail,element);
        printf("\ndo you want to continue (if yes press 1):");
        scanf("%d",&rp);
    }

    while(tmp!=NULL){
        var=dequeue(&head,&tail);
        printf("%d ", var->value);
        tmp=tmp->next;
    }


    return 0;
}