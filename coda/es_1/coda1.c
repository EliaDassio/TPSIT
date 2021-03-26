#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int valore;
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
    int val;
    int risp=1;

    head=NULL;
    tail=NULL;
    element=(Node*)malloc(sizeof(Node));
    while(risp==1){
        element=(Node*)malloc(sizeof(Node));
        printf("inserire un numero naturale");
        scanf("%d",&val);
        element->valore=val;
        enqueue(&head,&tail,element);
        printf("\nVuoi vontinuare a inserire valori(se si digitare 1):");
        scanf("%d",&risp);
    }

    Node *tmp = head;
    Node *var;
    while(tmp!=NULL){
        var=dequeue(&head,&tail);
        printf("%d ", var->valore);
        tmp=tmp->next;
    }


    return 0;
}