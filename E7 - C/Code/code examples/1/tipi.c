#include <stdio.h>

main(){
    int n=100;
    char c='a';
    char c2=20;
    float f=1.5;
    double d=150.3;
    int s1=sizeof(char);
    int s2=sizeof(int);
    int s3=sizeof(float);
    int s4=sizeof(double);
    printf("La dimensione di char è %d\n",s1); //1
    printf("La dimensione di int è %d\n",s2);   //4
    printf("La dimensione di float è %d\n",s3); //4
    printf("La dimensione di double è %d\n",s4); //8
}
