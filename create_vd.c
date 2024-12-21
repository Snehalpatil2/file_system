#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"
int main(int argc, char *argv[])
{
 	FILE *fp;
	printf("Input from command line %s\n", argv[1]);
	fp=fopen("vd","wb+");
	unsigned int vd_size= atoi(argv[1]);
	for(int i=0;i<vd_size;i++)
	{
		fwrite("0",1,1,fp);
	}
	unsigned short count = 0;
	fseek(fp, 0, SEEK_SET);
	fwrite(&count, 2, 1, fp);
	fclose(fp);
	return 0;
}
