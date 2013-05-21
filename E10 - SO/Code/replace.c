#include <stdio.h>	
#include <stdlib.h>

int main (int argc, char **argv){
     int c;
     if(argc < 3) {
       printf("This program requires at least two parameters.");
       return 1;
     }
     while((c=fgetc(stdin))!=EOF){
     	 if (c==argv[1][0]) c=argv[2][0];
     	 fputc(c,stdout);
     }
     exit(0);
     return 0;
}