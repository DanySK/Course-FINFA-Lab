#include <stdio.h>

void swap(int *i1,int *i2){
	int temp=*i1;
	*i1=*i2;
	*i2=temp;
}

    
int main(void){
	int a=10;
	int b=20;
	swap(&a,&b);
	printf("a=%d, b=%d\n",a,b);
	return 0;
}
    
    

