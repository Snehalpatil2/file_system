#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

struct output{
	unsigned char* outarray;
	unsigned int written_bits;

};

unsigned char *decode_file(FILE *fp)
{
	unsigned long bit_to_read = 2;
	unsigned char out;
	fread(&out, 1, 1, fp);
	char flag = 0;
	unsigned int i = 1;
	short bit = 8;
	unsigned long read_bit = 0;
	unsigned long read_bits = 0;

	while (flag != 1)
	{
		if (bit > 0)
		{
			if (i <= bit_to_read)
			{

				read_bit = read_bit | ((out >> (bit - 1)) & 1);
				read_bits = read_bit | (read_bits << 1);
				i++;
				bit--;
				read_bit = 0;
			}
			else
			{
				i = 1;
				bit_to_read = read_bits;
				read_bit = 0;
				flag = (out >> (bit - 1)) & 1;
				read_bits = 0;
				bit--;
			}
		}
		else
		{
			fread(&out, 1, 1, fp);
			bit = 8;
		}
	}

	unsigned int size = bit_to_read;
	unsigned char *out_array = (unsigned char *)malloc(ceil((double)bit_to_read / 8));
	unsigned int j = 1;
	unsigned int array_byte = 0;
	unsigned int array_bit = 8;
	out_array[array_byte] = 0;
	while (j <= size)
	{
		if (array_bit > 0)
		{
			if (bit > 0)
			{
				read_bit = read_bit | ((out >> (bit - 1)) & 1);
				out_array[array_byte] = out_array[array_byte] | (read_bit << (array_bit - 1));
				bit--;
				j++;
				read_bit = 0;
				array_bit--;
			}
			else
			{
				bit = 8;
				fread(&out, 1, 1, fp);
			}
		}
		else
		{
			array_bit = 8;
			array_byte++;
		}
	}
	
	return out_array;
}
