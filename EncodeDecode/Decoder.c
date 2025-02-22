#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int decoder(unsigned char* out)
{
	int total_of_bits =0;
	int log_bits;
	int delimeter = 0;
	int log_value;
	int no_of_bits_to_write=2;
	int i=0;
	while(delimeter!=1)
	{


		while(no_of_bits_to_write!=0)
		{
			if((out[total_of_bits/8] & (1<<(7-i))) != 0)
			{
				log_bits |= (1<<(no_of_bits_to_write-1));
			}
			i++;
			if(i==8)
			{
				i=0;
			}
			total_of_bits++;
			no_of_bits_to_write--;
		}
		log_value = log_bits;
		printf("log value is %d\n",log_value);
		no_of_bits_to_write = log_value;
		log_bits =0;
		if((out[total_of_bits/8] & (1<<(7-i))) != 0 )
		{
			delimeter = 1;
		}
		else
		{
			delimeter = 0;
		}
		printf("delimeter is %d\n", delimeter);
		i++;
		if(i==8)
		{
			i=0;
		}
		total_of_bits++;

	}
	return log_value;
}




		



