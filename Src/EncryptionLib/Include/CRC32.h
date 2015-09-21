#pragma once

//---------------------------------------------------------------------------

#ifndef CRCH
#define CRCH
//---------------------------------------------------------------------------

namespace GLEO 
{
	template <class T>
	T ByteReverse(T value)
	{
		T Result;

	  for(int i = 0; i < sizeof(T); i++)
	  {
  		*( ((char*)&Result) + i ) = *( ((char*)&value) + sizeof(T) - 1 - i );
	  }

	  return Result;
	}

	//---------------------------------------------------------------------------
	template <class T>
	class BaseCRC
	{
	protected:
	  T CRCGx;
	  T HighBit;
		T LookupTable[256];

		virtual void InitLookupTable() = 0;

	public:
		BaseCRC(T gen_poly);

		virtual T ClassCheck(void* buf, int len, T check_sum = 0) = 0;
	  virtual T Check(void* buf, int len, T check_sum = 0) = 0;
	};

	template <class T>
	BaseCRC<T>::BaseCRC(T gen_poly)
	{
	  CRCGx = gen_poly;
		HighBit = 1;
	  HighBit <<= sizeof(T) * 8 - 1;
	}

	//---------------------------------------------------------------------------
	template <class T>
	class CRC : public BaseCRC<T>
	{
	protected:
		void InitLookupTable();

	public:
		CRC(T gen_poly);

		T ClassCheck(void* buf, int len, T check_sum = 0);
	  T Check(void* buf, int len, T check_sum = 0);
	};

	template<class T>
	CRC<T>::CRC(T gen_poly)
			: BaseCRC<T>(gen_poly)
	{
		InitLookupTable();
	}

	template<class T>
	void CRC<T>::InitLookupTable()
	{
		T CRCWord;
		for(int i = 0; i < 256; i++)
	  {
  		T BaseWord = i;
		CRCWord = ClassCheck(&BaseWord, 1);

  		LookupTable[i] = CRCWord;
	  }
	}

	template<class T>
	T CRC<T>::ClassCheck(void* buf, int len, T check_sum)
	{
		T Flag;
		unsigned char aChar;
	  T Result = check_sum;

		for(int i = 0; i < len; i++)
	  {
			aChar = ((unsigned char*)buf)[i];
			for(int j = 0; j < 8; j++)
			{
				Flag = Result & HighBit;
				Result <<= 1;
				Result |= (aChar & 0x80) ? 0x01 : 0x00;
				aChar <<= 1;

				if (Flag)	Result ^= CRCGx;
			}
		}

	  for(int j = 0; j < sizeof(T) * 8; j++)
	  {
				Flag = Result & HighBit;
				Result <<= 1;

				if (Flag)	Result ^= CRCGx;
	  }

		return Result;
	}

	template<class T>
	T CRC<T>::Check(void* buf, int len, T check_sum)
	{
	  T Result = check_sum;
		int i;

		for(i = 0; i < len; i++)
	  {
  		Result = (Result << 8) ^ LookupTable[((unsigned char*)buf)[i] ^ ((Result >> ((sizeof(T) - 1) * 8)))];
	  }

	  return Result;
	}
	//---------------------------------------------------------------------------
	template <class T>
	class CRCRev : public BaseCRC<T>
	{
	protected:
		void InitLookupTable();

	public:
		CRCRev(T gen_poly);

		T ClassCheck(void* buf, int len, T check_sum = 0);
	  T Check(void* buf, int len, T check_sum = 0);
	};

	template<class T>
	CRCRev<T>::CRCRev(T gen_poly)
			: BaseCRC<T>(gen_poly)
	{
		InitLookupTable();
	}

	template<class T>
	void CRCRev<T>::InitLookupTable()
	{
		T CRCWord;
		for(int i = 0; i < 256; i++)
	  {
  		T BaseWord = i;
		BaseWord <<= (sizeof(T) - 1 ) * 8;
		CRCWord = ClassCheck(&BaseWord, sizeof(T));

  		LookupTable[i] = CRCWord;
	  }
	}

	template<class T>
	T CRCRev<T>::ClassCheck(void* buf, int len, T check_sum)
	{
		T Flag;
		unsigned char aChar;
	  T Result = check_sum;

		for(int i = 0; i < len; i++)
	  {
			aChar = ((unsigned char*)buf)[i];
			for(int j = 0; j < 8; j++)
			{
				Flag = (Result ^ aChar) & 1;
				Result >>= 1;
				aChar >>= 1;

				if (Flag) Result ^= CRCGx;
			}
		}

		return Result;
	}

	template<class T>
	T CRCRev<T>::Check(void* buf, int len, T check_sum)
	{
	  T Result = check_sum;
		int i;

		for(i = 0; i < len; i++)
	  {
  		unsigned int ind = ((unsigned char*)buf)[i] ^ (Result & 0x0ff);
  		Result = (Result >> 8) ^ LookupTable[ind];
	  }

	  return Result;
	}

	//---------------------------------------------------------------------------

	#endif

	class CRC16 : public CRCRev<unsigned short>
	{
	public:
		CRC16();
	};


	class CRC32 : public CRCRev<unsigned int>
	{
	public:
		CRC32();
	};
}