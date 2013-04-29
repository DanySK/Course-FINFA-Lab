// bit3.c
#include <stdio.h>

#define UNO 1
#define ZERO 0
#define BIT_GET(s,i) (set & UNO << i)!=ZERO

void printset(int set){
    int i=sizeof(int)*8;
    for (;i-->=0;){
       printf("%d",BIT_GET(set,i));
    }
    printf("\n");
}

int main(){
    int set1 = UNO << 5 | UNO << 10 | UNO << 21;	// set {5,10,21}
    int set2 = UNO << 5 | UNO << 12;	      	// set {5,12}
    int set3 = set1 & set2;                          	// set {5}
    int set4 = set1 | set2;                           	// set {5,10,12,21}
    printf("set1: ");  printset(set1);
    printf("set2: ");  printset(set2);
    printf("set3: ");  printset(set3);
    printf("set4: ");  printset(set4);
}