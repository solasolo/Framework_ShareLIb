// AESTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "AES.h"

using namespace GLEO;

void print(void* state, int len)
{
	unsigned char* buf = (unsigned char*) state; 

	for(int i = 0; i < len; i++)
	{
		printf("%s%X ", buf[i] > 15 ? "" : "0", buf[i]);
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned char input[] = 
	{
		0x32, 0x43, 0xf6, 0xa8, 
		0x88, 0x5a, 0x30, 0x8d, 
		0x31, 0x31, 0x98, 0xa2, 
		0xe0, 0x37, 0x07, 0x34
	};
	unsigned char key[] = 
	{
		0x2b, 0x7e, 0x15, 0x16, 
		0x28, 0xae, 0xd2, 0xa6, 
		0xab, 0xf7, 0x15, 0x88, 
		0x09, 0xcf, 0x4f, 0x3c
	};

	AESEncoder encoder(key);
	AESDecoder decoder(key);
	
	printf("Input:\n");
	print(input, sizeof(input));

	encoder.Calculate(input, sizeof(input));
	printf("After Cipher:\n");
	print(input, sizeof(input));

	decoder.Calculate(input, sizeof(input));
	printf("After InvCipher:\n");
	print(input, sizeof(input));

	int j;
	printf("\n");
	char str[32] = "Hello,My AES Cipher!";
	print(str, sizeof(str));

	encoder.Calculate((void *)str, sizeof(str));
	print(str, sizeof(str));

	decoder.Calculate((void *)str, sizeof(str));
	print(str, sizeof(str));

	char c;
	scanf_s("%c", &c);

	return 0;
}

