/*Principe
Exemple: Preuve que  le mot "abc" du dictionnaire est une combinaison possible de "(ab)(bc)(ca)"

                    |  lettre[0]['a' - 'a']== lettre[0][0] == 1
         (ab)------>|  lettre[0]['b' - 'a']== lettre[0][1] == 1
                    --------------------------------------------
                    |  lettre[1]['b' - 'a']== lettre[1][1] == 1
         (bc)------>|  lettre[1]['c' - 'a']== lettre[1][2] == 1
                    --------------------------------------------
                    |  lettre[2]['c' - 'a']== lettre[2][1] == 1
         (ca)------>|  lettre[2]['a' - 'a']== lettre[2][0] == 1

           0     1     2    3    4    5    6...26

Lettre1    1     1     0    0    0    0    0

Lettre2    0     1     1    0    0    0    0

Lettre3    1     1     0    0    0    0    0

Et puisque:

        lettre[0]['a' - 'a']== lettre[0][0] == 1
        lettre[1]['b' - 'a']== lettre[0][1] == 1
        lettre[2]['c' - 'a']== lettre[2][1] == 1
=> le mot "abc" du dictionnaire est bien une combinaison possible de "(ab)(bc)(ca)"
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 10000




int main () {

    //Files Openning
    //FILE* input = fopen("A-small-practice.in", "r");
    //FILE* input = fopen("A-large-practice.in", "r");
    //FILE* output = fopen("OUTPUT.txt", "w");

    /***************************************************************/

    //Variable Declarations
    int L, D, N;
    scanf("%d %d %d\n", &L, &D, &N);
	//For files please use this function:
	//fscanf(input, "%d %d %d", &L, &D, &N);
	char** dictionnaire = (char**)malloc(D * sizeof(char*));
	int* numberofpossiblewords = malloc(N * sizeof(int));

	/***************************************************************/

	// Dictionary Input
	for (int i = 0; i < D; i++){
        dictionnaire[i] = (char*)malloc(L * sizeof(char));
        scanf("%s",dictionnaire[i]);
        //For files please use this function:
        //fscanf(input, " %s", dictionnaire[i]);
	}

	/***************************************************************/

	for (int i = 0; i < N; i++){
       // Local Variable Declaration
       int current_letter = 0, counter = 0, diff;
       // Possible Word Combination Input (Example: (ab)(bc)(ca)
	   char* combination = malloc(MAX_STRING_LENGTH * sizeof(char));
	   scanf("%s",combination);
	   //For files please use this function:
	   //fscanf(input, " %s", combination);
	   // Letters Matrix Declaration
	   int *letters = (int *)malloc(L * 26 * sizeof(int));
	   for (int m = 0; m < L; m++){
          for (int n = 0; n < 26; n++){
             *(letters + m*26 + n) = 0;
          }
	   }
	   for (int j = 0; j < strlen(combination); j++) {
		if (combination[j] == '(') {
			int k = j + 1;
			do {
                diff = combination[k] - 'a';
				*(letters + current_letter * 26 + diff)= 1;
				k++;
			} while (combination[k] != ')');
			j = k;
		} else{
		    diff = combination[j] - 'a';
		    *(letters + current_letter * 26 + diff ) = 1;
		}
		current_letter++;
	    }
	    for (int j = 0; j < D; j++) {
		  bool boolean = true;
          for (int k = 0; k < L; k++){
              diff = dictionnaire[j][k] - 'a';
              if (*(letters + k *26 + diff) == 0) {
			     boolean = false;
			     break;
		      }
          }
		  if (boolean){
             counter++;
		  }
	    }
	    numberofpossiblewords[i] = counter;
	    // Free the allocated memory
        free(combination);
        free(letters);
	}

	/*******************************************************************/

	// Printing the Output
	printf("\n");
	printf("Output\n");
	//printf("Open The OUTPUT file in the directory");
	for(int i = 0; i < N; i++){
        printf("Case #%d: %d\n", i+1, numberofpossiblewords[i]);
        //For files please use this function:*/
        //fprintf(output,"Case #%d: %d\n", i+1, numberofpossiblewords[i]);
    }

    /*******************************************************************/
    // Free the allocated memory
    //fclose(input);
    //fclose(output);
    free(numberofpossiblewords);
    free(dictionnaire);
    return 0;
}
