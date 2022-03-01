#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List* histList = (List*)malloc(sizeof(Item)*2);
  histList->root = calloc(sizeof(Item), 1);
  histList->root->id = 1;
  histList->root->str = NULL;
  histList->root->next = NULL;

  return histList;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  int id = 2;

  if(list->root->str == NULL){
    list->root->str = calloc(sizeof(str),sizeof(char));
    list->root->str = strcpy(list->root->str, str);
    list->root->next = calloc(sizeof(Item),1);
    list->root->next = NULL;
  }
  else{
    list = realloc(list, (sizeof(list)+sizeof(Item)));
    Item* last_ptr = list->root;

    while(last_ptr->next != NULL){
      id++;
      last_ptr = last_ptr->next;
    }
    Item* test;
    test = calloc(sizeof(Item),1);
    test->id = id;
    test->str = calloc(sizeof(str),sizeof(char));
    test->next =calloc(sizeof(Item),1);
    test->next = NULL;
    test->str = strcpy(test->str,str);
    (*last_ptr).next = test;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item* dummy = list->root;

  while(id>1){
    dummy = dummy->next;
    id-=1;
  }
  return (*dummy).str;
}

/*Print the entire contents of the list. */
 void print_history(List *list){
   Item* dummy = list->root;
   
   while(dummy != NULL){
     printf("%s\n", dummy->str);
     dummy = dummy->next;
   }
 }

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *dummy = list->root;
  Item *temp;
  while(dummy != NULL){
    temp = dummy->next;
    free(dummy);
    dummy = temp;
    
  }
}
