#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10000

int main(int argc, char **argv) {
   if(argc < 2) {
      printf("Not enough parameters.\n");
      return 1;
   }
   if(argc > 2) {
      printf("WARNING: The following arguments were ignored: \n");
      int i;
      for(i = 2; i < argc; i++) {
         printf("%d) %s\n", i-1, argv[i]);
      }
      printf("\n");
   }
   
   // Open the file
   FILE *file = fopen(argv[1], "r");
   
   if (file == NULL ) {
      printf("Error reading file %s\n", argv[1]);
      return 2;
   }
   
   // Build a buffer to store the file
   char *buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
   
   // Read the file into the buffer
   unsigned int numRead = fread(buffer, 1, BUFFER_SIZE, file);

   int i;
   for(i = 0; i < numRead; i++) {
      printf("%c", buffer[i]);
   }
      
   free(buffer);
   fclose(file);
   return 0;
}
