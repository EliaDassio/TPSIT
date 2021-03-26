#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int value;
    struct node* next;
}Stack;


typedef struct node{
    int stack;
    struct node* next;
}Pile;

Pile* dequeue(Pile **head,Pile **tail){
    Pile *ret=*head;

	if(*head == NULL){
		return NULL;
	}
	else
		(*head)=ret->next;
	if(*head == NULL)
		*tail=NULL;
	return ret;
}

void enqueue(Pile **head, Pile **tail,Pile *element){
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
    Pile *head;
    Pile *tail;

    return 0;
}