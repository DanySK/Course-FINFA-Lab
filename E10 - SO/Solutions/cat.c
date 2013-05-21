#include <stdio.h>
#include <stdlib.h>

/*
 * This function computes the size of a file. The strategy is:
 * 1) Go to the end of the file
 * 2) See how many bytes have been read
 * 3) Go to the start of the file, so the file is ready for others
 * 4) Return the number of read bytes
 */
unsigned long compute_size(FILE *file) {
  // to obtain file size:
  fseek(file , 0 , SEEK_END); // go to the end
  unsigned long lSize = ftell(file); // see where you are
  rewind(file); // go back
  return lSize;
}

void printFile(char *filepath) {
  FILE *file = fopen(filepath, "r");
  if (file == NULL ) {
    printf("Error reading file %s\n", filepath);
  }
  
  unsigned long lSize = compute_size(file);
  
  // Build a buffer to store the file
  char *buffer = (char *) malloc(lSize * sizeof(char));
  
  // Read the file into the buffer
  fread (buffer,1,lSize,file);
  
  int i;
  for(i = 0; i < lSize; i++) {
    printf("%c", buffer[i]);
  }
    
  free(buffer);
  fclose(file);
}

int main(int argc, char **argv) {
  if(argc < 2) {
    printf("Not enough parameters.\n");
    return 1;
  }
  
  int i;
  for(i = 1; i < argc; i++) {
    printFile(argv[i]);
  }
  
  return 0;
}
