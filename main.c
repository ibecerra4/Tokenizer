#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void main(){
  short ans = 1;
  while(ans){
    char sentence[100];
    printf("Enter a sentence: \n");
    fgets(sentence,100, stdin);
    printf(">%s \n", sentence);
    printf("Length of string: %d\n", string_length(sentence));
    printf("is the first letter a valid character? %c\n" ,is_valid_character(sentence[0]));
    printf("find_word_start: %s\n", find_word_start(sentence));
    printf("find_word_end: %s\n", find_word_end(sentence));
    printf("count_words: %d\n", count_words(sentence));
    printf("tokenizing.....\n");
    char** tokens = tokenize(sentence);
    print_tokens(tokens);
    printf("it is going through");
    free_tokens(tokens);
    int dec;
    printf("Would you like to run the program again? 1 = yes, 0 = no\n");
    scanf("%d", dec);
    ans = dec;
  }
  printf("History: \n");
}
