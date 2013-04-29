// bit.c
#include <stdio.h>

int get(int s,int i){
    return (s & 1 << i)!=0;
}

int main(){
    int s1 = 1 << 5 | 1 << 10 | 1 << 21;	// set {5,10,21}
    int s2 = 1 << 5 | 1 << 12;		      	// set {5,12}
    int s3 = s1 & s2;                          	// set {5}
    int s4 = s1 | s2;                           	// set {5,10,12,21}
    printf("s1, bit 10,11,12: %d%d%d\n",get(s1,10),get(s1,11),get(s1,12));
    printf("s2, bit 10,11,12: %d%d%d\n",get(s2,10),get(s2,11),get(s2,12));
    printf("s3, bit 10,11,12: %d%d%d\n",get(s3,10),get(s3,11),get(s3,12));
    printf("s4, bit 10,11,12: %d%d%d\n",get(s4,10),get(s4,11),get(s4,12));
}