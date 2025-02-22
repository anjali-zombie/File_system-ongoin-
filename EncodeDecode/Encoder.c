#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int log_n(int number)
{
	return ceil(log2(number+1));
}
struct printbits {
	unsigned char *out;
	int no_of_bytes;
};
struct printbits encode(int number)
{
	struct printbits s;
	int total_of_bits =0;
	s.no_of_bytes=0;
	int no_of_bits=number;
	while(no_of_bits> 2)
	{
		no_of_bits = log_n(no_of_bits);
		total_of_bits+=no_of_bits+1;
	}
	printf("%d\n",total_of_bits);
	s.no_of_bytes=ceil((float)total_of_bits/8);
	printf("%d\n",s.no_of_bytes);
	s.out=(unsigned char*)malloc(s.no_of_bytes *sizeof(unsigned char));
	int flag=1;
	int anjali = 1,injali = 0;
	int log_bits_to_write;
	int helpme;
	while(total_of_bits > 0)
	{
		//(a/b)==2?"you are lucky":(a/b)==3?"very lucky":"good";
		if(flag==1)
		{
			s.out[((total_of_bits%8) == 0)?((total_of_bits/8)-1):(total_of_bits/8)] |= 1 << ((8-(total_of_bits%8))==8?0:(8-(total_of_bits%8)));
			total_of_bits--;
			flag=0;
		}
		else
		{
	
			log_bits_to_write = log_n(number);
			helpme = log_bits_to_write;
			while(log_bits_to_write){

				if((number & (anjali << injali)) != 0){
					s.out[total_of_bits/8] |= 1 << (7 - (total_of_bits % 8));

				}
				total_of_bits -= 1;
				log_bits_to_write -= 1;
				injali += 1;
			}
			number=helpme;
		
	        }
		total_of_bits -= 1;
		injali=0;
	}

 	return s;
						
}
