#include <stdio.h>
#include <stdlib.h>

struct El{
int valore;
struct El* next;
};

void push(struct El* lista, int val);
void print(struct El* lista);

int main(){
    int n;
    struct El* lista;
    struct El* l;
    lista=NULL; /* si inizializza il puntatore al primo elemento della lista a NULL */

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d",&n);
        if (n>=0){
            if (lista==NULL){ /* se l'elemento corrente della lista è uguale a NULL entra nel if */
                /* questo if alloca lo spazio di memoria alla lista */

                lista = (struct El*) malloc(sizeof(struct El));

                l = lista;
            }
            push(l, n);
        }
    } while (n>=0);

    l=lista; /* si reimposta il valore di l al primo punto della lista */
    print(l);
    printf("\n");
    return 0;
}

void push(struct El* lista, int val){
    struct El* p_app=lista;
    while (p_app->next!=NULL)
    {
        p_app=p_app->next;
    }
    p_app->next=(struct El*)malloc(sizeof(struct El));
    p_app->next->valore = val;

}

void print(struct El* lista){
    struct El* temp = lista;
    printf("numeri inseriti: ");
    while(temp != NULL){
        printf("%d ", temp->valore);
        temp = temp->next;
    }
}