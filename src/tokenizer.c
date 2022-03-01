#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c==' ' || c == '\t' || c =='\n'){
    return 1;
  }
  return 0;

}

/* making my own string length method*/
int string_length(char *str){
  int char_count = 0;
  while(str[char_count] != '\0')
    {
      char_count++;
    }
  return char_count;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(c==' ' || c == '\t' || c =='\n'){
    return 0;
  }
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  int index = 0;

  if(str[0] == '\0'){
    return 0;
  }

  while(space_char(str[index])){
    index++;
  }
  return &str[index];
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  int i = 0;

  if(word == ""){
    return word;
  }
  if(space_char(word[0])){
    while(space_char(word[i])){
      i++;
    }
  }
  while(non_space_char(word[i])){
    if(word[i] == '\0'){
      return 0;
    }
    i++;
  }
  return &word[i];
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  int wc = 0;
  int len = string_length(str);
  char i = 0;
  char* temp = str;
  int j = len;

  while(i<j){
    temp = word_terminator(str+i);
    if(temp == 0){
      break;
    }
    i = (temp - str)+1;
    wc++;
    j++;
    len -= i;
  }
  return ++wc;
}

/* Returns a freshly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  int l = 0;
  char *copy_str = (char*)calloc(len+1,sizeof(char));
  int index = 0;
  while(non_space_char(inStr[index])){
    copy_str[index] = inStr[index];
    index++;
  }
  return copy_str;
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
  int wc = count_words(str);
  char** tokenized = (char**)calloc(wc,sizeof(char*));
  char* start = word_start(str);
  char* end;
  int i;

  for(int j = 0; j<wc; j++){
    end = word_terminator(start);
    if(end != 0){
      i = (end - start)+1;
    }
    else{
      i = string_length(start) +1;
    }

    tokenized[j] = (char*)malloc(i*sizeof(char));    
    tokenized[j] = copy_str(start,i);
    start = end+1;
  }

  return tokenized;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  size_t size = sizeof(*tokens) / sizeof(*tokens[0]);
  for(int i = 0; tokens[i] != 0; i++){
    printf("%s\n", tokens[i]);
  }

}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  free(tokens);
}
