#include <stdio.h>


void swap(int *i1,int *i2){
	int temp=*i1;
	*i1=*i2;
	*i2=temp;
}

    
int main(void){
	int a[] = {10,20,30,40};
	printf("a[0]=%d, a[1]=%d, a[2]=%d, a[3]=%d\n",a[0], a[1], a[2], a[3]); 
	swap(a,&a[1]); // a is equivalent to &a[0]!
	printf("a[0]=%d, a[1]=%d, a[2]=%d, a[3]=%d\n",a[0], a[1], a[2], a[3]);
	return 0;
}
    
    

