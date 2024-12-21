#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(int argc,char* argv[])
{
	FILE *fp;
	fp = fopen("vd","rb");
	unsigned short count_size=0;
	fread(&count_size,sizeof(count_size),1,fp);
	printf("%d",count_size);
	fclose(fp);
	return 0;
}
