#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(){
    
    char string[MAX];
    char title[MAX];
    char autor[MAX];
    char title_autor[MAX][2];
    int index = 0, i = 4, j = 0, k = 0;
    FILE *fp;

    fp = fopen ("music.csv", "r");

    if (fp != NULL){
        while (!feof(fp)){
            fgets(string, MAX, fp);
            index = string[0];
            while (string[i] != ','){
                title[k] == string[i];
                i++;
                k++;
            }

            i++;

            while (string[i] != '\n'){
                autor[j] == string[i];
                i++;
                j++;
            }
            
            }
        }
    }
    else{
        printf("error during file reading");
    }
    return 0;
}