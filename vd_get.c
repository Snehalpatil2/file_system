#include<stdio.h>
#include<stdlib.h>
#include "header.h"
int main( int argc ,char* argv[])
{
	FILE *fp,*fp1;
	unsigned int fileSize,vdSize;
	if((fp=fopen(argv[1], "rb"))==NULL){
		printf("Error opening %s\n", argv[1]);
		return 0;
	}
	
	unsigned short count = atoi(argv[2]);
	fp1=fopen(argv[3], "wb+");
	unsigned int cnt_written_files =0;	
	unsigned int tot_size=0;
	fseek(fp,2,SEEK_SET);
	for(int i = 0; i < count; i++)
	{
		unsigned char* lenStr = decode_file(fp);
		lenStr = decode_file(fp);
		
		cnt_written_files = atoi(lenStr);
		tot_size += cnt_written_files;
	}
	
	fseek(fp,0,SEEK_END);
	vdSize= ftell(fp);
	fseek(fp,(vdSize -  tot_size), SEEK_SET);
	unsigned char buffer;
	for(int i=0;i<cnt_written_files;i++)
	{	
		fread(&buffer,1,1,fp);
		fwrite(&buffer,1,1,fp1);
	}
	return 0;
}
