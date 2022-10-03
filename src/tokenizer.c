#include<stdio>
#ifndef _TOKENIZER_
#define _TOKENIZER_

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if((c == '\t' || c == ' ') && c !='\0'){// zero is false, s || t is true i n c 
    return 1;

  }
     return 0;
}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if((c != '\t' || c != ' ') && c != \0){//true if is neither of t, s || 0
    return 1;
      }
  return 0;
    }
/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   
str does not contain any words. */
// if is space will keep moving until it findds a letter
char *word_start(char *str)
{
  while(space_char(*str)){
    str++;
  }
  return str;
}
/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)// if current is not a space then it will go forward
{
  while(non_space_char(*word)){
    word++;
  }
  return word;
}
/* Counts the number of words in the string argument. */
int count_words(char *str)
{// I used while because everytime a letter is found we increase by the counter
  int count = 0;
  while (str != '\0'{
      str++;
    }
    if (non_space_char(*str)){
      count++;
    }
    while(non_space_char(*str)){
      str++;
    }
    }
  return count;
}
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *copyStr = malloc((len + 1) * sizeof(char));
  int i = 0;
  for (i = 0; i < len; i++){
    copyStr[i] = inStr[i];
  }
  copyStr[len] = [\0];
  return copyStr;
}
char **tokenize(char* str)
{
  int num_words = count_words(str);
  char **tokens = (char**)malloc((num_words+1)*sizeof(char*));// Gets the

  int i = 0;
  for(i = 0; i < num_words; i++){
    char* first_letter = word_start(str);
    str = word_terminator(first_letter);
    tokens[i] = copy_str(first_letter, str - first_letter);
  }// making tokesns of words, and pointers from our str. 
  tokens[i] = NULL;
  return tokens;
}
/* Prints all tokens. */
void print_tokens(char **tokens)
{
  if(*tokens ==0){
    printf("\n");
    return;
  }
  char ** curr = tokens;
  while(*curr != 0)
    {
      printf("%s\n", *curr);
      curr++;
    }
  printf("\n");
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  chaar **curr = tokens;
  while(*curr != 0){
    free(*curr);
    curr++;
  }
  free(tokens);
}

#endif



