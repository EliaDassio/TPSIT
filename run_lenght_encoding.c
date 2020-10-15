#include <stdio.h>
#include <string.h>

int main (){
    
    char word[100]; //creation of the array that will ontain the word to encode or decode
    int ed;    //creation of a variabol that will determing if the uer chouse to decode or encode
    int n;
    int num, sum;
    
     printf("do you wanto to decode [0] or encode [1] ? "); //ask the user if they want to decode or encode
     scanf("%d", &ed);

     if (ed != 1 && ed != 0){ // if the answer is not accettable I'll re ask the question untill it's right
         do{
             printf ("\nplease insert a valid answer [1] [0]: ");
             scanf("%c", &ed);
         }while (ed != 1 && ed != 0);
     }

     printf("\ninput string: ");
     scanf("%s", word);



     //--------------------------------DECODING--------------------------------

     if (ed == 0){
         printf("\nprint the decoding\n\n");
         for (int i = 0; i < strlen(word); i++){               // a loop for scan every cell of the array
             if (word[i] >= '0' && word[i] <= '9'){   // chek if the cell contain a number and convert thet number from achii to int
                num = word[i] - '0';
                 for (int j = 0; j < num; j++){    //print the next cell num times
                     printf("%c", word[i+1]);
                 }
                 i++;                               //jump to the next cell
             }
             else{
                 printf("%s", word[i]);             //if it's a charcter it will print the letter onece
             }
         }
    }

     //--------------------------------ENCODING--------------------------------

     if (ed == 1){
         printf("\nprint the encoding\n\n");
         
         num = 1;
         
         for (int i = 0; i < strlen(word); i++){
             if (word[i] == word[i+1]){
                 num++;
             }
             else{
                 printf("%d%c", num, word[i]);
                 num = 1;
             }
         }
     }
    
    printf("\n");
    
    return 0;
} 
