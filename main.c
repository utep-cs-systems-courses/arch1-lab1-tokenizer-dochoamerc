#include <stdio.h>
#include "src/tokenizer.h"
#include "src/history.h"

void main(){
  char str[100];
  char *s = str;
  size_t bufsize = 100;
  
  fputs("> ", stdout);
  getline(&s, &bufsize, stdin);
  fputs("You have entered: ",stdout);
  printf("%s",s);
  printf("\n\n*****Tokenizing*****\n\n",0);
  char **tokens = tokenize(s);
  printf("**PRINT TOKENS**\n");
  print_tokens(tokens);
  
  printf("\n\n*****TESTING HISTORY*****\n\n");

  List* list = init_history();
  for(int i =0; i < count_words(s);i++){
    add_history(list, tokens[i]);
  }
  
  printf("ID 2: %s\n", get_history(list,2));
  printf("\n**PRINT HISTORY**\n",0);
  print_history(list);
}
