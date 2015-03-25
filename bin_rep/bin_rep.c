#include<stdio.h>

void reverse(char * str ){

char temp;
int i, j;

for ( i = 0 , j = strlen(str)-1; i < j; j--, i++){

temp = str[i];
str[i] = str[j];
str[j] = temp;

}

}

int print_sign(char * str){

	if (str != NULL){

		if(str[0] == '-'){ 

			printf ("sign = -1\n"); 
			return -1;
		}
		else 
			printf("sign = +1\n");
			return 1;
	}

}

int  print_int(char * str, char * value){


	if (str == NULL) return 0;

	
	*str == '-' ? ++str  : 0;
	
	while (*str != '.' && *str != '\0' ){ 
		*value++ = *str;
		printf("%c",*str++);
		
	}
	printf("\n");
	*value = '\0';
}

int print_frac(char * str, char * value){


	if (str == NULL ) return 0;

	while (*str != '.'){
		*str == '\0' ? printf("no fraction\n") : 0 ;	
		++str;
	}
	str++;
	printf(".");
	while (*str != '\0'){
		*value++ = *str; 
		printf("%c", *str++);
	}
	printf("\n");
	*value = '\0';
}


int print_bin(char * intgr, char * frac){

	char blah [100];
	char * temp = blah; 
	int int_val = 0;
	int i = 0;
	float f_frac = 0 ;
	float pos = .1;

	int_val += *intgr - '0';
	while (*++intgr != '\0'){
		int_val *= 10;
		int_val += *intgr - '0';
	}
	
	while ( i < 32 && int_val != 0){
	int_val & 0x1 ? blah[i] = '1': (blah[i] = '0');
	int_val = int_val >> 1; 
	i++;
	}
	blah[i]='\0';
	reverse(blah);
	printf("%s", temp); 
	printf(".");
	
	while(*frac != '\0' ){
	f_frac += ((float) (*frac++ - '0') * pos);
	pos *= .1; 
	}
	//printf("%f\n",f_frac);
	
	while( f_frac * 2 != 0 ){

	f_frac *= 2;
	
	if (f_frac >= 1){
		printf("1");
		f_frac -= 1;
	}
	else 
		printf("0");
	}

	printf("\n");
}



int main(void){

	char  intgr[100];
	char  frac[100];
	char * value = "-123.75";
	print_sign(value);
	print_int(value, intgr);
 	print_frac(value, frac);
	print_bin(intgr, frac);
	
	return 1;


}






