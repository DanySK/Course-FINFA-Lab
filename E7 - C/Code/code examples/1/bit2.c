// bit2.c
#include <stdio.h>

void printset(int set){
    int i=sizeof(int)*8;
    for (;i>=0;){
       printf("%d",(set & 1 << --i)!=0);
    }
    printf("\n");
}

int main(){
    int set1 = 1 << 5 | 1 << 10 | 1 << 21;	// set {5,10,21}
    int set2 = 1 << 5 | 1 << 12;		      	// set {5,12}
    int set3 = set1 & set2;                          	// set {5}
    int set4 = set1 | set2;                           	// set {5,10,12,21}
    printf("set1: ");  printset(set1);
    printf("set2: ");  printset(set2);
    printf("set3: ");  printset(set3);
    printf("set4: ");  printset(set4);
}