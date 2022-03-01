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
  printf("Tokenizing\n",0);

  char **tokens = tokenize(s);
  print_tokens(tokens);

  List* list = init_history();
  add_history(list, "testing");
  add_history(list, "multiple");
  add_history(list, "words");

  printf("ID 2: %s\n", get_history(list,2));

  print_history(list);
}
