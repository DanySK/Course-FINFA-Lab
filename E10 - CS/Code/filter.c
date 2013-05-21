#include <stdio.h>
#include <string.h>
#define BUFDIM 10000
int main (int argc, char **argv){
  char buffer[BUFDIM];
  char *exit = "exit\n";
  char *res;
  do{
    res = fgets(buffer, BUFDIM, stdin);
    if(res == buffer) {
      fputs(res, stdout);
    }
  } while(res == buffer && strcmp(res, exit) != 0);
  return 0;
}
