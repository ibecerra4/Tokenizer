#include <stdlib.h>

#include <stdio.h>

#include "tokenizer.h"


int string_length(char* str){
  char* p = str;
  int count = 0;
  while(*p != '\0'){
      count++;
      p++;
  }
  return count-1;
}

char is_valid_character(char c){
  if(c > 33 && c < 126){
    return '1';}
  else{ return '0';}
}

char* find_word_start(char* str){
  char* p = str;
  while(is_valid_character(*p) == '0'){
    if(*p == '\0'){
      return p;
    }
    p++;
  }
  return p;
}

char* find_word_end(char* str){
  char* p = str;
  if(is_valid_character(*p) == '0'){
    return p;
  }
  else{
    while(is_valid_character(*p) == '1'){
      p++;
    }
    return p;
  }
}

int count_words(char* str){
  int count = 0;
  char* p = str;
  while(*p != '\0'){
    p = find_word_start(p);
    if(*p == '\0'){
      return count;
    }
    count++;
    p = find_word_end(p);
    if(*p == '\0'){
      return count;
    }
  }

  return count;

}

char* copy_word(char* str){
  char* start = find_word_start(str);

  char* end = find_word_end(str)+1;

  int numChar = (end-start);

  char* copy = (char*)malloc(sizeof(char*)*(numChar+1));

  for (int i=0; i<numChar;i++){

    copy[i] = start[i];

  }

  copy[numChar-1] = '\0';

  return copy;

}

char** tokenize(char* str){

  int size = count_words(str);

  char** tokens = (char**)malloc(sizeof(char*)*(size+1));

  char* p = str;

  char* word;

  for (int i=0; i<size; i++){

    p = find_word_start(p);

    word = copy_word(p);

    tokens[i] = word;

    p = find_word_end(p);

  }
  tokens[size+1] = '\0';
  return tokens;
}



void print_tokens(char** tokens){
  while(**tokens != '\0'){

    printf("--> %s \n", *tokens);

    tokens++;

  }

}



void free_tokens(char** tokens){

  while(**tokens != '\0'){

    free(*tokens);

    tokens++;

  }

  free(tokens);

}
  
