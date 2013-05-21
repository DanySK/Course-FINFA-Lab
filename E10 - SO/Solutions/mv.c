#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (int argc, char **argv){
  FILE *in, *out;
  if (argc != 3){
    printf (" Args: <from> <to> \n");
    exit(1);
  }
  if ((in=fopen(argv[1], "r")) <0) {
    perror("Errore nel file sorgente. ");
    exit(1);
  }
  
  fseek(in, 0, SEEK_END);
  unsigned long lSize = ftell(in);
  rewind(in);
  void *buffer = malloc(lSize * sizeof(char));
  
  if ((out=fopen(argv[2], "w" )) <0) {
    perror("Errore nel file destinazione. ");
    fclose(in);
    exit(1);
  }
  int nread;
  while((nread=fread(buffer, sizeof(char), lSize, in)) >0 && fwrite(buffer, sizeof(char), nread, out)==nread);
  fclose(in);
  remove(argv[1]);
  fclose(out);
  exit(0);
}
