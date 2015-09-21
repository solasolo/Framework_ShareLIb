#pragma once


namespace GLEO 
{
	enum
	{
		shaSuccess = 0,
		shaNull,            
		shaInputTooLong,
		shaStateError      
	};

	#define SHA1_HASH_SIZE 20

	class _declspec(dllexport) SHA1
	{
	private:
		unsigned int IntermediateHash[SHA1_HASH_SIZE / 4]; 
		unsigned char MessageBlock[64];      

		unsigned long Position;         
		int MessageBlockIndex;
	
		void Reset();
		void Process();
		void Pad();   

		inline unsigned int CircularShift (int bits, unsigned int word);

	public:
		SHA1();

		void Input(const unsigned char *, unsigned int);
		void Result(unsigned char Message_Digest[SHA1_HASH_SIZE]);
	};
}