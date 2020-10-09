#include <stdio.h>

int main (){
    
    char word[100]; //creation of the array that will ontain the word to encode or decode
    char ed;    //creation of a variabol that will determing if the uer chouse to decode or encode
    int n;
    int num, sum;
    
     printf("do you wanto to decode [d] or encode [e] ? "); //ask the user if they want to decode or encode
     scanf("%s", &ed);

     if (ed != 'e' && ed != 'd'){ // if the answer is not accettable I'll re ask the question untill it's right
         while (ed != 'e' && ed != 'd'){
             printf ("\nplease insert a valid answer [e] [d]: ");
             scanf("%s", &ed);
         }
     }

     printf("\ninput lenth of string: "); // ask the user to input the lenght of the string so that they can input the string with a for loop
     scanf("%d", &n);

     for(int i = 0; i < n; i++){
         scanf("%s", word[i]);
     }

     //--------------------------------DECODING--------------------------------

     if (ed == 'd'){
         printf("\nprint the decoding\n");
         for (int i = 0; i < n; i++){               // a loop for scan every cell of the array
             if (word[i] >= 48 && word[i] <= 57){   // chek if the cell contain a number and convert thet number from achii to int
                num = word[i] - 48;
                 for (int j = 0; j <= num; j++){    //print the next cell num times
                     printf("%s", word[i+1]);
                 }
                 i++;                               //jump to the next cell
             }
             else{
                 printf("%s", word[i]);             //if it's a charcter it will print the letter onece
             }
         }
    }

     //--------------------------------ENCODING--------------------------------

     if (ed == 'e'){

     }
    
     return 0;
} 