#include <stdio.h>
#include <stdlib.h>

struct El{
int valore;
struct El* next;
};

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
            else{ /* se non è NULL si passa qui */

                /* si inizializza lo spazio di memoria al prossimo nodo della lista e si fa scorrere il puntatore */

                l->next = (struct El*) malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n; /* si assegna il valore all'interno del nodo  */
            l->next = NULL; /* si inizializza il puntatore al prossimo nodo a NULL */
        }
    } while (n>=0);

    l=lista; /* si reimposta il valore di l al primo punto della lista */
    printf("numeri inseriti: ");
    while (l!=NULL){
        printf("%d - %p \n",l->valore, l->next);
        l=l->next; /* si passa al prossimo nodo della lista */
    }
    printf("\n");
    return 0;
}