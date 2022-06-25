#pragma once

#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "WinException.h"
#include "CommonFuncs.h"

#include <Unknwn.h>
#include <atlbase.h>

//#define COMPtr(intf) typedef CComPtr<intf> intf##Ptr 

#define COMPtr(intf) typedef COMSmartPointer<intf> intf##Ptr 

using namespace Win32Lib;

namespace GLEO
{
	inline void SafeRelease(IUnknown* pInterface);

	template<class T>
	class SmartPointer
	{
		class ReferenceCountObject
		{
			friend class SmartPointer;

		private:
			int RefCount;
			T* pObject;

			void CheckReference();

		public:
			ReferenceCountObject(T* ptr);

			inline void AddRef();
			inline void Release();
		};

	private:
		ReferenceCountObject* InnerRef;

		void Assign(SmartPointer<T>& sp);

	protected:
		inline void _AddRef();
		inline void _Release();

	public:
		SmartPointer();	
		SmartPointer(T* ptr);	
		SmartPointer(const SmartPointer<T>& sp);

		~SmartPointer();	

		inline T* get();

		inline SmartPointer<T>& operator =(const SmartPointer<T>& sp);
		inline T* operator ->();
		inline operator bool();
		inline bool operator !();	
		inline T& operator *();
		inline T* operator &();
	};

	template<class T>
	class COMSmartPointer 
	{
	private: 
		void Assign(T* pi);

	protected:
		T* pInterface;

		inline void _AddRef();
		inline void _Release();

	public:
		COMSmartPointer();
		COMSmartPointer(T* pi);	
		COMSmartPointer(const COMSmartPointer<T>& sp);	

		~COMSmartPointer();

		template<class P> COMSmartPointer<P> Query(GUID id);

		inline COMSmartPointer<T>& operator <<(T* pi);
		inline COMSmartPointer<T>& operator =(const COMSmartPointer<T>& sp);
		inline COMSmartPointer<T>& operator =(T* pi);

		inline T* operator ->();
		inline operator bool();
		inline bool operator !();	

		inline T& operator *();
		inline T* operator &();
	};

	template<class T>
	class AutoSmartPointer : public COMSmartPointer<T>
	{
	private:
		static GUID ID;

		template<class P> void Assign(P* pi);

	public:
		AutoSmartPointer();
		AutoSmartPointer(T* pi);	
		AutoSmartPointer(const AutoSmartPointer<T>& sp);	
	};
}

namespace GLEO
{
	//---------------------------------------------------------------------------
#pragma region ReferenceCountObject

	template<class T>
	SmartPointer<T>::ReferenceCountObject::ReferenceCountObject(T* ptr)
	{
		RefCount = 1;
		pObject = ptr;
	};

	//template<class T>
	//inline SmartPointer<T>::ReferenceCountObject::operator bool()
	//{
	//	CheckReference();

	//	return (pObject != NULL);
	//}

	template<class T>
	inline void SmartPointer<T>::ReferenceCountObject::CheckReference()
	{
		if(RefCount <= 0) 
		{
			DESTROY(pObject);
			RefCount = 0;
		}
	}

	template<class T>
	inline void SmartPointer<T>::ReferenceCountObject::AddRef()
	{
		InterlockedIncrement((unsigned long*)&RefCount);
	};

	template<class T>
	inline void SmartPointer<T>::ReferenceCountObject::Release()
	{
		InterlockedDecrement((unsigned long*)&RefCount);

		CheckReference();
	};

#pragma endregion

	//---------------------------------------------------------------------------
#pragma region SmartPointer

	template<class T>
	void SmartPointer<T>::_AddRef()
	{
		if(this->InnerRef)
		{
			this->InnerRef->AddRef();
		}
	}

	template<class T>
	void SmartPointer<T>::_Release()
	{
		if(this->InnerRef)
		{
			this->InnerRef->Release();

			if(!this->InnerRef)
			{
				DESTROY(this->InnerRef);
			}
		}
	}

	template<class T>
	SmartPointer<T>::SmartPointer()
	{
		InnerRef = NULL;
	}

	template<class T>
	SmartPointer<T>::SmartPointer(T* ptr)
	{
		this->InnerRef = NULL;

		if(ptr)
		{
			InnerRef = new ReferenceCountObject(ptr);
		}
	}

	template<class T>
	SmartPointer<T>::SmartPointer(const SmartPointer<T>& sp)
	{
		this->InnerRef = NULL;

		this->Assign((SmartPointer<T>&)sp);
	}

	template<class T>
	SmartPointer<T>::~SmartPointer()
	{
		this->_Release();
	}

	template<class T>
	inline void SmartPointer<T>::Assign(SmartPointer<T>& sp)
	{
		if(sp && sp.InnerRef != this->InnerRef)
		{
			sp._AddRef();
			this->_Release();

			InnerRef = sp.InnerRef;
		}
	}

	template<class T>
	inline T* SmartPointer<T>::get()
	{
		return  &(*this);
	}

	template<class T>
	inline SmartPointer<T>& SmartPointer<T>::operator =(const SmartPointer<T>& sp)
	{
		this->Assign((SmartPointer<T>&)sp);

		return *this;
	}

	template<class T>
	inline T* SmartPointer<T>::operator ->()
	{
		T* Result = NULL;

		if(this->InnerRef && this->InnerRef->pObject)
		{
			Result = this->InnerRef->pObject;
		}
		else
		{
			throw Exception("Null in Smart Poiner");
		}

		return Result;
	}

	template<class T>
	inline bool SmartPointer<T>::operator !()
	{
		return !bool(*this);
	}

	template<class T>
	inline SmartPointer<T>::operator bool()
	{
		return ( this->InnerRef && this->InnerRef->pObject );
	}

	template<class T>
	inline T* SmartPointer<T>::operator &()
	{
		T* Result = NULL;
		if(this->InnerRef)
		{
			Result = this->InnerRef->pObject;
		}

		return Result;
	}

	template<class T>
	inline T& SmartPointer<T>::operator *()
	{
		if(!this->InnerRef) throw Exception("Null in Smart Poiner");

		return this->InnerRef->pObject;
	}

#pragma endregion

	//---------------------------------------------------------------------------
#pragma region COMSmartPointer

	template<class T>
	inline void COMSmartPointer<T>::_AddRef()
	{
		if(pInterface)
		{
			pInterface->AddRef();
		}
	}

	template<class T>
	inline void COMSmartPointer<T>::_Release()
	{
		if(this->pInterface)
		{
			this->pInterface->Release();
			this->pInterface = NULL;
		}
	}

	template<class T>
	void COMSmartPointer<T>::Assign(T* pi)
	{
		if(this->pInterface != pi) 
		{
			this->_Release();

			this->pInterface = pi;

			this->_AddRef();
		}
	}

	template<class T>
	COMSmartPointer<T>::COMSmartPointer()
	{
		this->pInterface = NULL;
	}

	template<class T>
	COMSmartPointer<T>::COMSmartPointer(T* pi)
	{
		this->pInterface = NULL;

		this->Assign(pi);
	}

	template<class T>
	COMSmartPointer<T>::COMSmartPointer(const COMSmartPointer<T>& sp)
	{
		this->pInterface = NULL;

		this->Assign(sp.pInterface);
	}

	template<class T>
	COMSmartPointer<T>::~COMSmartPointer()  
	{
		this->_Release();
	}

	template<class T> 
	template<class P>
	COMSmartPointer<P> COMSmartPointer<T>::Query(GUID id)
	{
		P* pIntf;
		COMSmartPointer<P> Result;

		HRESULT hr = (*this)->QueryInterface(id, (void**)&pIntf);
		WinException::COMCheck(hr, "Query Interface");

		Result << pIntf;

		return Result;
	}

	template<class T> 
	inline COMSmartPointer<T>& COMSmartPointer<T>::operator <<(T* pi)
	{
		this->_Release();

		if(pi)
		{
			this->pInterface = pi;
		}

		return *this;
	}

	template<class T>
	inline COMSmartPointer<T>& COMSmartPointer<T>::operator =(const COMSmartPointer<T>& sp)
	{
		this->Assign(sp.pInterface);

		return *this;
	}

	template<class T>
	inline COMSmartPointer<T>& COMSmartPointer<T>::operator =(T* pi)
	{	
		this->Assign(pi);

		return *this;
	}

	template<class T>
	inline T* COMSmartPointer<T>::operator ->()
	{
		return pInterface;	
	}

	template<class T>
	inline COMSmartPointer<T>::operator bool()
	{
		return (this->pInterface != NULL);	
	}

	template<class T>
	inline bool COMSmartPointer<T>::operator !()
	{
		return (this->pInterface == NULL);	
	}

	template<class T>
	inline T* COMSmartPointer<T>::operator &()
	{
		return this->pInterface;	
	}

#pragma endregion

#pragma region AutoSmartPointer
	template<class T>
	GUID AutoSmartPointer<T>::ID = __uuidof(T);


	template<class T>
	template<class P>
	void AutoSmartPointer<T>::Assign(P* pi)
	{
		T* pNew;

		if(pi && this->pInterface != pi) 
		{
			this->_Release();

			HRESULT hr = pi->QueryInterface(ID, (void**)&pNew);
			WinException::COMCheck(hr, "Query Interface");		

			this->pInterface = pNew;
		}
	}

	template<class T>
	AutoSmartPointer<T>::AutoSmartPointer()
	{
		this->pInterface = NULL;
	}

	template<class T>
	AutoSmartPointer<T>::AutoSmartPointer(T* pi)
	{
		this->pInterface = NULL;

		this->Assign(pi);
	}

	template<class T>
	AutoSmartPointer<T>::AutoSmartPointer(const AutoSmartPointer<T>& sp)
	{
		this->pInterface = NULL;

		this->Assign(sp.pInterface);
	}


#pragma endregion


	inline void SafeRelease(IUnknown* pInterface)
	{
		if(pInterface)
		{
			pInterface->Release();
			pInterface = NULL;
		}
	}

}

#endif 