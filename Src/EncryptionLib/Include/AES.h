#pragma once

namespace GLEO 
{
	class __declspec(dllexport) AESBase
	{
	protected:
		static unsigned char Box[256]; 
		static unsigned char InvBox[256]; 

		unsigned char WorkBuffer[11][4][4];

		AESBase(void* key);

		void BlockToLine(unsigned char block[4][4], unsigned char* line);
		void LinetTOBlock(unsigned char block[4][4], unsigned char* line);

		unsigned char FFmul(unsigned char a, unsigned char b);
		void KeyExpansion(unsigned char* key, unsigned char w[][4][4]);
		void MixColumns(unsigned char state[4][4]);
		void AddRoundKey(unsigned char state[4][4], unsigned char k[4][4]);
		void SubBytes(unsigned char state[4][4], unsigned char box[256]);

		virtual unsigned char* Cipher(unsigned char* input) = 0;

	public:
			void* Calculate(void* buf, int size);
	};

	class __declspec(dllexport) AESEncoder : public AESBase
	{
	private:
		void ShiftRows(unsigned char state[4][4]);

	protected:
		virtual unsigned char* Cipher(unsigned char* input);

	public:
		AESEncoder(unsigned char* key);
	};

	class __declspec(dllexport) AESDecoder : public AESBase
	{
	private:
		void InvShiftRows(unsigned char state[4][4]);
		void InvMixColumns(unsigned char state[4][4]);

	protected:
		virtual unsigned char* Cipher(unsigned char* input);

	public:
		AESDecoder(unsigned char* key);
	};
}