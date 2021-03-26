#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct nodo{
    char elemento;
    struct nodo* next;
}Nodo;

int is_empty(Nodo *head){
    if(head == NULL) return 1;
    else return 0;
}

void push(Nodo **head, Nodo* elemento){
    if(is_empty(*head)){
        *head = elemento;
        elemento -> next = NULL;
    }
    else{
        elemento -> next = *head;
        *head = elemento;
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret -> next;
    }
    return ret;
}

int main(){
    char str[MAX];
    char val;
    int cont = 0;

    Nodo* elemento;
    Nodo* head = NULL;

    printf("\nenter the number to invert(press ENTER to end): ");
    scanf("%c", &val);
    while(val != '\n'){
        scanf("%c", &val);
        *elemento = val;
        push(*head, elemento);
        scanf("%c", &val);
        str[cont] = val
    }

    for(int i = 0; i < strlen(str); i++){
        val = pop(*head);
        printf("%c", val);
    }    

}