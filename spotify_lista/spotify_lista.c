#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct list
{
    int index;
    char title[MAX];
    char author[MAX];
    struct list* next;
}slist;

void push(slist* head, int index, char title[MAX], char author[MAX]);
void find_song(slist* head, int val);



int main(){
    char string[MAX];
    char* string_tem;
    char song;
    slist* list;
    slist* ind;
    slist* tit;
    slist* aut;
    int song_prec, song_now, n_song = 0;
    int index;
    char* title;
    char* author;
    FILE *fp;
    int cont = 0;

    fp = fopen ("music.csv", "r");

    if (fp != NULL){
        while (fgets(string, MAX, fp)){
           if(cont == 0){
            list=(slist*)malloc(sizeof(slist));
            list->next=NULL;
            cont++;
           }
            index = atoi(strtok(string,","));
            title = strtok(NULL,",");
            author = strtok(NULL,",");
            push(list, index, title, author);
            n_song++;
        }

         printf("\n\ndo you want to listen to a song ? (yes [y], no [n]) : ");
            scanf("%c", &song);
            while (song != 'y' && song != 'Y' && song != 'n' && song != 'N'){
                printf("\n\nplease answer correctly: ");
                scanf("%c", &song);
            }

        while (song != 'n' && song != 'N'){
            do{
                song_now = rand() % n_song;
            }while (song_now == song_prec);
            find_song(list, song_now);
            song_prec = song_now;

            printf("\n\ndo you want to listen to another song ? (yes [y], no [n]) : ");
            scanf("%c", &song);
            while (song != 'y' && song != 'Y' && song != 'n' && song != 'N'){
                printf("\n\nplease answer correctly: ");
                scanf("%c", &song);
            }

        }

    }
    else{
        printf("error during file reading");
    }
    fclose(fp);
    return 0;
}

void push(slist* head, int index, char title[MAX], char author[MAX]){
    slist* p_app=head;
    while (p_app->next!=NULL)
    {
        p_app=p_app->next;
    }
    p_app->next=(slist*)malloc(sizeof(slist));
    p_app->next->index = index;
    strcpy(p_app->next->title, title);
    strcpy(p_app->next->author, author);
    p_app->next->next=NULL;
}


void find_song(slist* head, int val){
    slist* temp = head;
    while(temp != NULL){
        if (temp->index == val){
            printf("%d ", temp->index);
            printf("%s ", temp->title);
            printf("%s", temp->author);
        }
        temp = temp->next;
    }
}