#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Count number of bits required
unsigned int countbit(unsigned int num)
{
    unsigned int count = 0;
    while (num > 0) {
        num >>= 1;
        count++;
    }
    return count;
}

unsigned char* encode(unsigned char* in, unsigned int count)
{
        
        unsigned int input_bits=count*8;
        unsigned int total_bits=input_bits;
        unsigned int current;
        unsigned char levels = 1;
        current=input_bits;

        //how many levels required
        while(current>2 )
         {
                current = countbit(current);
                total_bits += current + 1;
                levels++;
        }

        current=input_bits;
        unsigned int* bitvalue_array=(unsigned int*)malloc(levels);
        unsigned char x = 0;

        //store countbit value in levels array
        while(x<levels){
                bitvalue_array[x]=current;
                current = countbit(current);
                x++;
        }

         // allocate memory
        unsigned int total_bytes;
        total_bytes=ceil((double)total_bits/8);
        unsigned char* bitarray=(unsigned char *)malloc(total_bytes);


        unsigned int val = 0;
        unsigned int a = 0;   //array index
        unsigned char bit = 8;
        unsigned char rem_bits = 0;   //remaining bits
        unsigned int b = levels-1;
        int y = b-1;
        bitarray[a]=0;

        //encode input
        while(y>=0)
        {
                val=bitvalue_array[y];

                if((rem_bits + bit) >= bitvalue_array[b])
                {
                        bitarray[a]=(bitarray[a] | (val << (bit - (bitvalue_array[b]-rem_bits))));
                        bit = (bit -(bitvalue_array[b]-rem_bits))-1;
                        y--;
                        b--;
                        rem_bits = 0;
                }
                else
                {
                        rem_bits=bit;
                        bitarray[a]=bitarray[a] | (val >> (bitvalue_array[b]-rem_bits));
			 bit=8;
                        a++;
                        bitarray[a]=0;
                }
        }

        bitarray[a]=(bitarray[a]| (((bitarray[a] >> bit) | 1)<<bit));
        rem_bits=bit;
        bit=8;

        //copy in after encode
        for(int z=0;z<count;z++)
        {
                 bitarray[a] = bitarray[a] | (in[z] >> (bit - rem_bits));
                 a++;
                bit=8;
                bitarray[a]=0;
                bitarray[a] = bitarray[a] | (in[z] <<(bit- (bit - rem_bits)));
        }
	return bitarray;
}



