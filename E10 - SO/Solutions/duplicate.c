#include <stdio.h>	
#include <stdlib.h>

int main (int argc, char **argv){
  int c;
  if(argc < 2) {
    printf("This program requires at least one parameter.");
    return 1;
  }
  while((c=fgetc(stdin))!=EOF){
    fputc(c,stdout);
    if (c==argv[1][0]) {
      fputc(c,stdout);
    }
  }
  exit(0);
  return 0;
}