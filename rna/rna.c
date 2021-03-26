#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000 // I initialize a global variable for the length of the array

int main(){
    FILE* fp;                       // I initialize all the other variables starting from the file pointer pointer 
    char string[MAX];               // the string
    int a = 0, c = 0, g = 0, t = 0; // and all the counters for eatch letter

    fp = fopen("rna.txt", "r");     // I open the file 

    if (fp != NULL){                // I verify if the file vas opened correctly 
        while (!feof(fp)){          // I cycle until the and of the file
            fgets(string, MAX, fp); // I put the entire line in the string
            for (int i = 0; i < strlen(string); i++){ // I cycle for every letter and update eatch counter for every time it reconize a letter
                if (string[i] == 'a'){
                    a++;
                }
                if (string[i] == 'c'){
                    c++;
                }
                if (string[i] == 'g'){
                    g++;
                }
                if (string[i] == 't'){
                    t++;
                }
            }
        }
        printf("\n\nthe numbers of a are: %d", a);      // I print every couter for eatch letter 
        printf("\n\nthe numbers of c are: %d", c);
        printf("\n\nthe numbers of g are: %d", g);
        printf("\n\nthe numbers of t are: %d\n\n", t);
    }
    else{
        printf("\n\nerror during opening of file\n\n"); // if the file didn't open correctly the program will print this
    }

    fclose(fp);     // I close the file 
    return 0;
}