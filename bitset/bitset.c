#include<stdio.h>


int set_bits (int n, int mask, int index1, int index2){
	
	unsigned int temp = 1;
	unsigned int temp2 = 1;
	
	if (index1 > 31 || index2 > 32){
		printf("index out of bounds!\n");
		return 0;

	}
	
	while (index2 > 0){
		temp *= 2;
		--index2;  
	}
	--temp;
	
	while (index1 > 0){
		temp2 *= 2;
		--index1;
	}
	--temp2;

	temp = temp ^ temp2;
	mask = temp & mask;
	n = n & ~temp;
	return n | mask;
}


void print_bin(int n){

	unsigned int mask = 0x80000000;
	while (mask){
	
	if (n & mask)
		printf("1");
	else 				
		printf("0");
	mask >>= 1;
	

	}
	printf("\n");

}

int main (void) {


	
	int n = 1555;
	int mask = 30002;
	int res;
 	int index1 = 4;
	int index2 = 10;
	printf ("index1 = %d , index2 = %d  \n", index1, index2 );        	
	printf(" 6 = ");
	print_bin(6);

	printf(" %10d = ", n);
	print_bin(n);
	printf(" %10d = ", mask);
	print_bin(mask);
	
	res = set_bits(n,mask, index1, index2);
	printf ( " %10d = ", res);
	print_bin(res);

	return 0;


}






