#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>


int space_char(char c){  
  if(c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(c == ' ' || c == '\t' || c == '\0'){
    return 0;
  }
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  /*iterate through the string until the beginning of the
  next word is found*/
  while(space_char(*str) == 1){
    str++;
  }
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  /*iterates through a string till the word ends*/
  while(non_space_char(*word) == 1){
    word++;
  }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  int words = 1;
  /*declares the beginning of the word*/
  str = word_start(str);
  /*while its not null*/
  while(*str != '\0'){
  /*if there's a space in the word count the word*/
    if(space_char(*str) == 1){
      words++;
    }
    /*next word in the string*/
    str++;
}
  return words;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  /*new string, allocating memory(malloc) for every char in string*/
  char *str = (char*) malloc(sizeof(char) * (len+1));
  int i;
  for(i = 0; i < len; i++){
  /*copy a letter to new string for every letter in old string*/
    str[i] = inStr[i];
  }
  str[i] = '\0';
  /*return new string*/
  return str;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
  char **tokenize(char* str){
    int words = count_words(str);
    char *word_e; /*end of the word pointer*/
    //allocated memory for tokens
    char **tokens = (char**) malloc((words+1) * sizeof(char*));
    /*iterates through every word in the string*/
    int i;
    for(i = 0; i < words; i++){
  /*start of the word*/
      str = word_start(str);
      /*end of the word*/
      word_e = word_terminator(str);
      /*stores a current copy of the word*/
      tokens[i] = copy_str(str, (word_e - str));
      /*updates the string*/
      str = word_terminator(str);
    }
    /*ends the array with null*/
    tokens[i] = NULL;
    return tokens;
  }
/* Prints all tokens. */
  void print_tokens(char **tokens){
    int i = 0;
    while(*tokens != 0){
      printf("Tokens[%d] = %s\n", i, *tokens);
      i++;
      tokens++;
    }
  }

/* Frees all tokens and the vector containing themx. */
  void free_tokens(char **tokens){
    int i = 0;
    while(tokens[i]){
      free(tokens[i]);
      i++;
    }
    free(tokens);
  }
