#include <stdio.h>
#include <string.h>
#define BUFDIM 142
int main (int argc, char **argv){
  char buffer[BUFDIM];
  char *exit = "yxyt\n";
  char *res;
  do{
    res = fgets(buffer, BUFDIM, stdin);
    int i;
    if(res == buffer) {
      for(i = strlen(res)-1; i >= 0; i--){
        if(res[i] == 'A' || res[i] == 'E' || res[i] == 'I' || res[i] == 'O' || res[i] == 'U') {
          res[i] = 'Y';
        } else if(res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u') {
          res[i] = 'y';
        }
      }
      fputs(res, stdout);
    }
  } while(res == buffer && strcmp(res, exit) != 0);
  return 0;
}
