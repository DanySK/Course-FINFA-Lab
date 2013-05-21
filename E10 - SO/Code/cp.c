#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFDIM 1000

int main (int argc, char **argv){
  FILE *in, *out;
  char buffer[BUFDIM];
  if (argc != 3){
    printf (" Args: <from> <to> \n");
    exit(1);
  }
  if ((in=fopen(argv[1], "r")) <0) {
    perror("Errore nel file sorgente. ");
    exit(1);
  }
  if ((out=fopen(argv[2], "w" )) <0) {
    perror("Errore nel file destinazione. ");
    fclose(in);
    exit(1);
  }
  int nread;
  while((nread=fread(buffer, sizeof(char), BUFDIM, in)) >0 && fwrite(buffer, sizeof(char), nread, out)==nread);
  fclose(in);
  fclose(out);
  exit(0);
}
