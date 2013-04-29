 #include <stdio.h>
 #include <stdlib.h>
 
 main(){
 	 int i=0;
 	 for (;i<100;i++){
 	 	 printf("%04d\t%04d\t%04d\n",rand()%1000,rand()%1000,rand()%1000);
 	 }
 }
