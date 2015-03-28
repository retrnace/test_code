#include<stdio.h>
#include<comp_neg.h>
static void print_twoscomplement(int num){

char  str[32]; 
int temp = num;
int i =0;
printf(" num = %d\n", num);

if (num >= 0){

printf("wrong inp\n");
return 0;

}

num = -num;

do {

str[i++] = num % 2 + '0';

}while(num /= 2);
str[i] = '\0'; 

reverse(str);

printf ("string = %s\n", str);


for (i = 0 ; i < 32; i++){

str[i] =  (temp & 0x1) + '0';
temp = temp >> 1; 
printf("char = %c\n", str[i]);
} 
str[i] = '\0';

reverse (str);

printf ("string = %s\n", str);




}

void reverse(char * str ){

char temp;
int i, j;

for ( i = 0 , j = strlen(str)-1; i < j; j--, i++){

temp = str[i];
str[i] = str[j];
str[j] = temp; 

}

}


int main(void){


	
	print_twoscomplement(-10);



	return 1;

}

