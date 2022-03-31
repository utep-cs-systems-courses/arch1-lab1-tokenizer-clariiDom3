#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
/* Initialize the linked list to keep the history. */
List* init_history(){
  /*allocates memory for the list*/
  List* head = (List*) malloc(sizeof(List));
  head->root = NULL;
  
  return head;
}
  

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  /*allocates memory for the history*/
  Item *data = (Item*) malloc(sizeof(Item));
  Item *current_node = list -> root; //creates a node
  /*find the length of str*/
  int item_Id = 0;
  int str_len = 0;
  while(str[str_len] != '\0'){
    str_len++;
  }
  /*set item to copy a string*/
  data -> str = copy_str(str, str_len);
  data -> next = NULL;
  if(current_node == NULL){
    data -> id = item_Id;
    list -> root = data;
    return;
  }
  while(current_node -> next != NULL){
    item_Id++;
    current_node = current_node;
  }
  item_Id++;
  data->id = item_Id;
  current_node -> next = data;
}


/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *temp = list->root;
  char *word = list->root->str;
  int i = 0;
  if( id < 0){
    printf("Invalid Id");
    return "Error!";
  }
  while(temp != NULL){
    if(temp -> id == id){
      return temp -> str;
       }
    temp = temp -> next;
  }
  return "error!!";
}
/*Print the entire contents of the list. */
void print_history(List *list){
  Item *temp = list->root;
  int i = 0;
  while(temp != NULL){
    printf("%s\n", temp->str);
    temp= temp->next;
    i++;
  }
  printf("done printing history!");
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *temp = list->root;
  while(temp != NULL){
    temp = list->root->next;
    free(temp->str);
    free(temp);
    temp = list->root;
  }
  free(list);
}
