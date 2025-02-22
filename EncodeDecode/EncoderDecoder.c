#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct printbits {
	unsigned char *out;
	int no_of_bytes;
};

struct printbits encode(int x);
int decoder(unsigned char *out); 

int main()
{
	struct printbits s;
        int x;
	while(1){
        	printf("Enter number of your choice : \n");
        	scanf("%d",&x);
        	s = encode(x);
		for(int i=0;i<s.no_of_bytes;i++)
		{
			printf("%b\n",s.out[i]);
		}
		printf("decoded value is %d",decoder(s.out));
	}
	return 0;
        
}

