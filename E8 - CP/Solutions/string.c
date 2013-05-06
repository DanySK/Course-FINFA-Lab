#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcat(const char *c1, const char *c2) {
  char *c=malloc((strlen(c1)+strlen(c2)+2)*sizeof(char));
  strcpy(c,c1);
  strcat(c," ");
  strcat(c,c2);
  return c;
}

char *scanToLast(char *s) {
  char *result;
  int i = 0;
  for(; s[i] != '\0'; i++) {
    result = &s[i];
  }
  return result;
}

/*
 * This solution is correct, but forbidden :)
 */
char *scanToLastStrlen(char *s) {
  return &s[strlen(s)-1];
}

int main(void) {
  char *s1 = "Looks like this exercise";
  char *s2 = "has been solved correctly";
  printf("%s\n", mystrcat(s1, s2));
  printf("The last character of \"%s\" is %c\n", s1, *scanToLast(s1));
  return 0;
}