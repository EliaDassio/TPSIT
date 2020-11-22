#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000
#define WORDS 5

int main(){
    
    char string[MAX];                                   /* initialisation of every variable in the code */
    char title[MAX];
    char autor[MAX];
    char song;
    int index[MAX];
    int index_title_autor[MAX][WORDS];
    int song_prec, song_now, n_song, num;
    int i, a, t, j = 0, k = 0, l = 0, h = 0, o = 0;
    int off_t, off_a;
    FILE *fp;

    fp = fopen ("music.csv", "r");                  /* opening of the file and if done correctly it keeps on with the code */

    if (fp != NULL){
        while (fgets(string, MAX, fp)){
            printf("%s", string);
            
            i = 0;

            while (string[i] != ','){               /* memorize the index of the song */
                if (i == 0){
                    index[l] = string[i];
                }
                if (i == 1){
                    index[l] += string[i] * 10;
                }
                if (i == 2){
                    index[l] += string[i] * 100;
                }
                if (i == 3){
                    index[l] += string[i] * 1000;
                }
                i++;
            }

            i++;

            t = k;
            off_t = 0;

            while (string[i] != ','){                      /* obtain the title of the song */
                title[k] = string[i];
                i++;
                k++;
                off_t++;
            }

            i++;

            a = j;
            off_a = 0;

            while (string[i] != '\n'){                  /* obtain the autor/grup of the song */
                autor[j] = string[i];
                i++;
                j++;
                off_a++;
            }

            index_title_autor[h][0] = index[l];         /* store in ine 2d matrix all the initial points fo the varius perts of the song and their lenght */
            index_title_autor[h][1] = title[t];
            index_title_autor[h][2] = (char)off_t;
            index_title_autor[h][3] = autor[a];
            index_title_autor[h][4] = (char)off_a;

            l++;
            h++;
        }

        n_song = h +1;

        do{
            printf("\n\ndo you want to listen to a song ? (yes [y], no [n]) : ");
            scanf("%c", &song);
                                                                                /* randomising the song and verfy that is different than the previus one */
            while (song != 'y' && song != 'Y' && song != 'n' && song != 'N'){
                printf("\n\nplease answer correctly: ");
                scanf("%c", &song);
            }

            if (song == 'y' || song == 'Y'){
                
                do{
                    song_now = rand() % n_song;                                         /* print the song selected */
                }while (song_now == song_prec);
                
                printf("\n\nnumber of the song: %c", index_title_autor[song_now][0]);
                printf("\n\ntitle:");
                for (int e = 0; e < index_title_autor[song_now][2]; e++){
                    num = index_title_autor[song_now][1];
                    printf("%c", title[num + e]);
                }
                printf("\n\nautor/grup:");
                for (int e = 0; e < index_title_autor[song_now][4]; e++){
                    num = index_title_autor[song_now][3];
                    printf("%c", title[num + e]);
                }

                song_prec = song_now;
            }

        }while (song != 'n' && song != 'N');

    }
    else{
        printf("error during file reading");
    }
    fclose(fp);
    return 0;
}