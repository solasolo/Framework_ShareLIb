#include "stdafx.h"
#include "SHA.h"

namespace GLEO 
{
	SHA1::SHA1()
	{
		this->Reset();
	}

	inline unsigned int SHA1::CircularShift (int bits, unsigned int word)
	{
		return (word << bits) | (word >> (32-bits));
	}

	void SHA1::Process()
	{
		const unsigned int K[] =    {       /* Constants defined in SHA-1   */
			0x5A827999,
			0x6ED9EBA1,
			0x8F1BBCDC,
			0xCA62C1D6
		};

		unsigned int      temp;              /* 临时缓存 */
		unsigned int      W[80];             /* 字顺序   */
		unsigned int      A, B, C, D, E;     /* 设置系统磁盘缓存块 */

		/*
		*  以下为初始化在W队列中的头16字数据
		*/
		for(int t = 0; t < 16; t++)
		{
			W[t] = this->MessageBlock[t * 4] << 24;
			W[t] |= this->MessageBlock[t * 4 + 1] << 16;
			W[t] |= this->MessageBlock[t * 4 + 2] << 8;
			W[t] |= this->MessageBlock[t * 4 + 3];
		}

		for(int t = 16; t < 80; t++)
		{
			W[t] = CircularShift(1, W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]);
		}

		A = this->IntermediateHash[0];
		B = this->IntermediateHash[1];
		C = this->IntermediateHash[2];
		D = this->IntermediateHash[3];
		E = this->IntermediateHash[4];

		/*  
		*  以下为定义算法所用之数学函数及其迭代算法描述  
		*/
		for(int t = 0; t < 20; t++)
		{
			temp = CircularShift(5, A) +
				((B & C) | ((~B) & D)) + E + W[t] + K[0];
			E = D;
			D = C;
			C = CircularShift(30,B);
			B = A;
			A = temp;
		}

		for(int t = 20; t < 40; t++)
		{
			temp = CircularShift(5, A) + (B ^ C ^ D) + E + W[t] + K[1];
			E = D;
			D = C;
			C = CircularShift(30,B);
			B = A;
			A = temp;
		}

		for(int t = 40; t < 60; t++)
		{
			temp = CircularShift(5,A) +
				((B & C) | (B & D) | (C & D)) + E + W[t] + K[2];
			E = D;
			D = C;
			C = CircularShift(30,B);
			B = A;
			A = temp;
		}

		for(int t = 60; t < 80; t++)
		{
			temp = CircularShift(5,A) + (B ^ C ^ D) + E + W[t] + K[3];
			E = D;
			D = C;
			C = CircularShift(30,B);
			B = A;
			A = temp;
		}

		/*  
		*  以下为迭代算法第80步（最后一步）描述
		*/
		this->IntermediateHash[0] += A;
		this->IntermediateHash[1] += B;
		this->IntermediateHash[2] += C;
		this->IntermediateHash[3] += D;
		this->IntermediateHash[4] += E;

		this->MessageBlockIndex = 0;
	}

	void SHA1::Pad()
	{
		if (this->MessageBlockIndex > 55)
		{
			this->MessageBlock[this->MessageBlockIndex++] = 0x80;

			while(this->MessageBlockIndex < 64)
			{
				this->MessageBlock[this->MessageBlockIndex++] = 0;
			}

			this->Process();

			while(this->MessageBlockIndex < 56)
			{
				this->MessageBlock[this->MessageBlockIndex++] = 0;
			}
		}
		else
		{
			this->MessageBlock[this->MessageBlockIndex++] = 0x80;

			while(this->MessageBlockIndex < 56)
			{
				this->MessageBlock[this->MessageBlockIndex++] = 0;
			}
		}

		/*
		*  把最后64位保存为数据长度
		*/

		unsigned char* PosBytes = (unsigned char*)&this->Position;
		for(int t = 0; t < 8; t++)
		{
			this->MessageBlock[63 - t] = PosBytes[t];	
		}

		this->Process();
	}

	void SHA1::Reset()
	{
		this->Position = 0;
		this->MessageBlockIndex    = 0;

		this->IntermediateHash[0]   = 0x67452301;
		this->IntermediateHash[1]   = 0xEFCDAB89;
		this->IntermediateHash[2]   = 0x98BADCFE;
		this->IntermediateHash[3]   = 0x10325476;
		this->IntermediateHash[4]   = 0xC3D2E1F0;

		for(int i = 0; i < 64; ++i)
		{
			this->MessageBlock[i] = 0;
		}
	}

	void SHA1::Input(const unsigned char* buffer, unsigned int length)
	{
		if (length && buffer)
		{
			while(length--)
			{
				this->MessageBlock[this->MessageBlockIndex++] = (*buffer & 0xFF);

				this->Position += 8;

				if (this->MessageBlockIndex == 64)
				{
					this->Process();
				}

				buffer++;
			}
		}
	}

	void SHA1::Result(unsigned char Message_Digest[SHA1_HASH_SIZE])
	{
		if (Message_Digest)
		{
			if (this->Position)
			{
				this->Pad();
			}

			for(int i = 0; i < SHA1_HASH_SIZE; ++i)
			{
				Message_Digest[i] = this->IntermediateHash[i >> 2] >> 8 * ( 3 - ( i & 0x03 ) );
			}

			this->Reset();
		}
	}
}