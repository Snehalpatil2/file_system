// argv[1] == vdpath, argv[2] == filepath
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

int main(int argc, char *argv[])
{
	FILE *fp, *fp1;
	unsigned short count;
	unsigned int fileSize, vdSize, remSize, usedvd;
	usedvd = 0;
	if ((fp = fopen(argv[1], "rb+")) == NULL)
	{
		printf("Error opening %s\n", argv[1]);
		return 0;
	}
	if ((fp1 = fopen(argv[2], "rb")) == NULL)
	{
		printf("Error opening %s\n", argv[2]);
		return 0;
	}
	fseek(fp, 0, SEEK_END);
	vdSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	fread(&count, 2, 1, fp);

	fseek(fp1, 0, SEEK_END);
	fileSize = ftell(fp1);

	unsigned char buff[50];
	sprintf(buff, "%d", fileSize);

	unsigned int tot_size = 0;
	for (int i = 0; i < count; i++)
	{
		// decode file name and file size
		unsigned char *lenStr = decode_file(fp);
		lenStr = decode_file(fp);
		unsigned int cnt_written_files = atoi(lenStr);
		tot_size += cnt_written_files;
	}
	usedvd += tot_size;
	unsigned int len = ftell(fp);
	usedvd += len;
	printf("len:%d\n", len);
	remSize = vdSize - usedvd;
	if (remSize >= fileSize)
	{
		unsigned char *encoded_text;
		encoded_text = encode(argv[2], strlen(argv[2]));
		fwrite(encoded_text, 1, strlen(encoded_text), fp);

		encoded_text = encode(buff, strlen(buff));
		fwrite(encoded_text, 1, strlen(encoded_text), fp);
		count++;

		fseek(fp, 0, SEEK_SET);
		fwrite(&count, sizeof(count), 1, fp);
		// fseek(fp, 0, SEEK_END);
		// vdSize = ftell(fp);
		fseek(fp, (vdSize - (fileSize + tot_size)), SEEK_SET);

		unsigned char buffer;
		unsigned int byte_reads = 0;
		fseek(fp1, 0, SEEK_SET);
		while (byte_reads < fileSize)
		{
			fread(&buffer, 1, 1, fp1);
			fwrite(&buffer, 1, 1, fp);
			byte_reads++;
		}
	}
	else
	{
		printf("Remaining size of virtual disk is: %d \n Given file size is: %d \n File cannot added in virtual disk\n", remSize, fileSize);
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
