 #include <stdio.h>
 #include <stdlib.h>
 
 main(){
 	 int righe=10;
 	 for (;righe>0;righe--){
 	 	 int colonne=21;
 	 	 for (;colonne>0;colonne--){
 	 	 	 if (colonne>righe && 20-colonne>righe) printf("*"); 
 	 	 	 else printf(" ");
 	 	 }
 	 	 printf("\n");
 	 }
 }
