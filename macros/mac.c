#include <stdio.h>


#define IS_GREATER(A,B)  A > B 
#define MIN(A,B) ((A) <=  (B) ? (A) : (B))


int main(void){

	int a = 3; 
	int b = 5;
	int c;
	int *  ptr = (int *) malloc (sizeof(int)*2) ;
	ptr[0] = 1;
	ptr[1] = 5;
	if (IS_GREATER(a,b)){
	printf ("a greater than b\n");

	}

	c =  MIN(*ptr++, a);
	printf("%d\n", c );

	return 0;

}







