#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(){
    
    char title[MAX];
    char autr[MAX];
    int index = 0;
    FILE *fp;

    fp = fopen ("music.csv", "r");

    if (fp != NULL){
        while (!feof(fp)){
            for (int i = 0; i < MAX, i++){
                
            }
        }
    }
    else{
        printf("error during file reading");
    }
    return 0;
}