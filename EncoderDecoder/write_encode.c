#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct printbits {
	unsigned char *out;
	int no_of_bytes;
};

struct printbits encode(int x);

long f_size(const char* file_name)
{
	FILE* file =fopen(file_name,"r");
        if(file == NULL)
        {
                 printf("error in opening file\n");
                 return 1;
         }
	fseek(file,0,SEEK_END);
        long file_size = ftell(file);

        fclose(file);
    
    return file_size;
}


int main(int argc , char* argv[])
{
	if (argc ==3)
	{
		struct printbits s;
		int x = f_size(argv[1]);
		printf("file size is :%ld bytes\n",x);
           
                //scanf("%d",&x);
                s = encode(x);
		FILE* file2 = fopen(argv[2],"wb");
		if(file2 ==NULL)
		{
			printf("error in opening file\n");
			return 1;
		}
		int byte_position =4;
		fseek(file2,byte_position,SEEK_SET);
                for(int i=0;i<s.no_of_bytes;i++)
                {
			fwrite(&s.out[i],sizeof(unsigned char),1,file2);
			
                      //  printf("%b\n",s.out[i]);
                }
		fclose(file2);
		printf("binary sequence of %ld is written in binary file after 4 bytes successfully",x);
	}
	return 0;
}
