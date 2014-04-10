/* Hello World program */

#include<stdio.h>
#include<math.h>

double frexp_double(double x);
double convert(const char binary[]);
long convertLong(char x[64]);

main()
{
	
    	//frexp_double(8.0);
	char bin[64];
	long num;
	printf("Enter in a double bit pattern: \n");
	scanf("%s", bin);
	printf("Entered: %s \n", bin);
	printf("Decimal number is :: %f \n",convert(bin));
	frexp_double(convert(bin));
	
	printf("Enter in a long bit patter: \n");


}


long convertLong(char x[64]){
	int i;
	int len;
	int r;
	
	for(i = 0; i < len; i++)
    {
        r = r * 2 + (x[i] == '1' ? 1 : 0);
    }
	
}

double frexp_double(double x){
	
	int exp = 0;

	while (x >= 1){

		x = x/2;
		exp++;

	}
	printf("Mantissa: %f\n", x);
	printf("Exponents: %d\n", exp);


}

double convert(const char binary[]){
  	int bi,i;
  	int len = 0;
  	int dot = -1;
  	double result = 0;

  	for(bi = 0; binary[bi] != '\0'; bi++){
    		if(binary[bi] == '.'){
      			dot = bi;
    		}
    		len++;
	}
	if(dot == -1)
		dot=len;

	  for(i = dot; i >= 0 ; i--){
	    if (binary[i] == '1'){
	      result += (double) pow(2,(dot-i-1));
	    }
	  }
	  for(i=dot; binary[i] != '\0'; i++){
	    if (binary[i] == '1'){
	      result += 1.0/(double) pow(2.0,(double)(i-dot));
	    }
	  }
	  return result;
}
