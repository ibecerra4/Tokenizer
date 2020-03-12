#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

void main(){
  char sentence[1000];
  printf("Enter a sentence :\n");
  scanf("%[^\n]s", sentence);
  printf("> %s \n", sentence);
}

int string_length(char* str){
  int count = 0;
  for (int i=0; str[i]; i++){
    if (str[i] != ' '){
      count++;
    }
  }
  return count;
}

char is_valid_character(char c){
  if(c >= 33 && c <= 126){
    return '1';}
  else{ return '0';}
}

char* find_word_start(char* str){
  if(is_valid_character(str[0]) == '0'){
      while(is_valid_character(str[0]) != '1'){
	*str++;
      }
  }
  return str;  
}

char* find_word_end(char* str){
  if(is_valid_character(str[0]) == '1'){
    while(is_valid_character(str[0]) != '0'){
      *str++;
    }
  }
  return str;
}

int count_words(char* str){
  int count = 0;
  char* p = str;
  while(*p != '\0'){
    p = find_word_start(p);
    count++;
    p = find_word_end(p);
  }
  return count;
}

char* copy_word(char* str){
  char* start = find_word_start(str);
  char* end = find_word_end(str);
  int numChar = (end-start) +1;
  char* copy = malloc((sizeof(char))*numChar);
  for (int i=0; i<numChar-1;i++){
    copy[i] = start[i];
  }
  copy[numChar-1] = '\0';
  return copy;
}

char** tokenize(char* str){
  int size = count_words(str);
  char** tokens = (char**)malloc((sizeof(char*)) * (size+1));

  char* p = str;
  char* word;
  for (int i=0; i<size; i++){
    p = find_word_start(p);
    word = copy_word(p);
    tokens[i] = word;
    p = find_word_end(p);
  }
  tokens[size] = '\0';
  
  return tokens;

}

void print_tokens(char** tokens){
  while(*tokens){
    printf("--> %s \n", *tokens);
    tokens++;
  }
}

void free_tokens(char** tokens){
  while(*tokens){
    free(*tokens);
    tokens++;
  }
  free(tokens);
}
