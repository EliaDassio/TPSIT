#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100                                         /* define a global variable */

typedef struct data{                                    /* define a struct for every pice in the varius csv file */
    char month[MAX];
    int day;
    int id_post;
    int num_like;
} data;

int main(){
    FILE* fp;                                           /* define all the variables */
    data data[MAX];
    char in_month[MAX];
    char string[MAX];
    char* string_tem;
    int i = 0;
    int sum_p = 0, sum_l = 0;
    
    fp = fopen ("instagram.csv", "r");                  /* opening of the file and if done correctly it keeps on with the code */

    if (fp != NULL){
        while (fgets(string, MAX, fp)){                 /* sorting of the string in the different parts of the struct */
            string_tem = strtok(string, ",");
            strcpy((data + i)->month, string_tem);

            string_tem = strtok(string, ",");
            (data + i)->day = atoi(string_tem);

            string_tem = strtok(string, ",");
            (data + i)->id_post = atoi(string_tem);

            string_tem = strtok(string, ",");
            (data + i)->num_like = atoi(string_tem);

            i++;

        }

        printf("\n\ninput the month you want to check: ");  /* ask the month to check and put it in the variable in_month */
        gets(in_month);

        for(int j = 0; j < i; i++){                    /* the cycle will check if the month correspond with the month in the data struct */
            if (in_month == (data + j)->month){        /* if the month is the same, the number of post increce by one and the likes are summed */
                sum_p++;
                sum_l += (data + j)->num_like;
            }
        }

        printf("in the month of %s you have %d post and %d likes", in_month, sum_p, sum_l); /* print the number of likes and posts in the month */
    }
    else{
        printf("error during file reading");            /* if the file didn't open correctly the program will send an error message */ 
    }
    fclose(fp);                                         /* closure of the file */
    return 0;
}