#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

int main(int argc,char* argv[])
{
	FILE *fp;
	if((fp=fopen(argv[1], "rb+"))==NULL){
		printf("Error opening %s\n", argv[1]);
		return 0;
	}
	unsigned short count;
	fread(&count,2,1,fp);
	fseek(fp,2,SEEK_SET);
	for(int i = 0; i < count; i++)
	{
		
		unsigned char* filenm = decode_file(fp);
		unsigned char *filesize = decode_file(fp);
		printf("%d\t%s\t%d\n",i+1, filenm, atoi(filesize));
	}
	fclose(fp);

}

