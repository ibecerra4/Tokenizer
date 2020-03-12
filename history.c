#include <stdlib.h>
#include <stdio.h>
#include "history.h"

List* init_history(){
  List* history;
  history = (List*) malloc(sizeof(List));
  history->root = NULL;
  return history;
}

//Function to add element to end of list
void add_history(List* list, char* str){
  if(list->root == NULL){
    list->root = (Item*) malloc(sizeof(Item));
    list->root->id = 1;
    list->root->str = str;
    list->root->next = NULL;
  }
  else{
    Item* tmp;
    tmp = (list->root);
    while((tmp->next) != NULL){
      tmp = tmp->next;
    }
    tmp->next = (Item*)malloc(sizeof(Item));
    (*tmp).next->id = ((*tmp).id)+ 1;
    (*tmp).next->str = str;
    (*tmp).next->next = NULL;
  }
}

char* get_history(List* list, int id){
  Item* tmp;
  if(list->root == NULL){
    return "List is empty";
  }
  tmp = (list->root);
  while(tmp != NULL){
    if((*tmp).id == id){
	return (*tmp).str;
    }
    tmp = tmp->next;
  }
  return "ERROR: ID NOT FOUND";
}

void print_history(List* list){
  Item* tmp = (list->root);
  while(tmp != NULL){
    printf("ELEMENT %d: &s \n", tmp->id, tmp->str);
    tmp = tmp->next;
  }
}

void free_history(List* list){
  Item* tmp;
  Item* tmp2 = list->root; 
  while(tmp2 != NULL){
    tmp = tmp2;
    tmp2 = tmp2->next;
    free(tmp);
  }
  free(list);
}
