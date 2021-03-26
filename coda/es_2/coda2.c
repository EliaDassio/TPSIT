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
        printf("Vuoi vontinuare a inserire valori(se si digitare 1):");
        scanf("%d",&risp);
    }

    Node *tmp = head;
    Node *var;
    int varr[100];
    int lung=0;
    while(tmp!=NULL){
        var=dequeue(&head,&tail);
        varr[lung]=var->valore;
        tmp=tmp->next;
        lung++;
    }
    
    for (int i = lung-1; i >= 0; i--)
    {
        printf("%d ",varr[i]);
    }
    
    return 0;
}
