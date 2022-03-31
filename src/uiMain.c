#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 300

int main(){
  char user_input[MAX], word[MAX];
  char **tokens;
  int count;
  List *history = init_history();
  while(user_input[0] != '3'){
    printf("1. Tokenizer String\n");
    printf("2. Print history\n");
    printf("3. Exit\n");
    fgets(user_input, MAX, stdin);
    if(user_input[0] == '1'){
      printf("Enter string to tokenize: \n");
      fgets(user_input, MAX, stdin);
      tokens = tokenize(user_input);
      print_tokens(tokens);
      add_history(history, user_input);
      free_tokens(tokens);
    }
    else if(user_input[0] == '2'){
      printf("Printing History: \n");
      print_history(history);
    }
    else if(user_input[0] == '3'){
      printf("Thank you for tokenizing!\n");
      break;
    }
  }
}
