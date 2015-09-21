// SmartPointerTest.cpp : Defines the entry point for the console application.
//

#include "SmartPointer.h"

#include <iostream>
#include <unknwn.h>

#include "WinFuncs.h"

using namespace std;
using namespace GLEO;
using namespace Win32Lib;

class A
{
protected:
	string Name;

public:
	void Who() 
	{ 
		cout << "I'm " << this->Name << endl; 
	};

	A(string name) 
	{
		this->Name = name;
		cout << this->Name << " is borned" << endl; 
	}
	
	virtual ~A() 
	{
		cout << this->Name << " is died" << endl; 
	};
};

class B : public A
{
private:
	int rc;

public:
	B(string name)
		: A(name)
	{
		rc = 1;
	}

	void AddRef()
	{
		rc++;
		cout << this->Name << " Cloned" << endl;
	}


	void Release()
	{
		rc--;
		cout << this->Name << " Release" << endl;

		if(rc <= 0)
		{
			delete this;
		}
	}
};

SmartPointer<A> X()
{
	return SmartPointer<A>(new A("smart"));
}

COMSmartPointer<B> Y()
{
	B* p = new B("com1");
	COMSmartPointer<B> r(p);
	p->Release();

	return r;
}

COMSmartPointer<B> Z1()
{
	B* b = new B("com2");
	COMSmartPointer<B> r = b;
	b->Release();

	return r;
}

COMSmartPointer<B> Z2()
{
	B* b = new B("com3");
	COMSmartPointer<B> r;
	r = b;
	b->Release();

	return r;
}

COMSmartPointer<B> Z3()
{
	B* b = new B("com4");
	COMSmartPointer<B> r;
	r << b;

	return r;
}

void AutoPtrTest()
{
	cout << "=== Auto Test Start ===" << endl;

	A* va = new A("AutoPtr1");
	A* vb = new B("AutoPtr2");

	SmartPointer<A> pva(va);
	SmartPointer<A> pvb(vb);

	cout << "=== Auto Test Turn Over ===" << endl;

	pva = pvb;

	cout << "=== Auto Test End ===" << endl;
}

void Test()
{
	SmartPointer<A> SA = X(); 
	SmartPointer<A> SAA = SA;

	COMSmartPointer<B> SB = Y();
	COMSmartPointer<B> SBB = SB;

	COMSmartPointer<B> SC = Z1();
	COMSmartPointer<B> SCC = SC;

	COMSmartPointer<B> SD = Z2();
	COMSmartPointer<B> SDD = SD;

	COMSmartPointer<B> SE = Z3();
	COMSmartPointer<B> SEE = SE;

	SA->Who();
	SAA->Who();

	SB->Who();
	SBB->Who();

	SC->Who();
	SCC->Who();

	AutoPtrTest();


	for(int i = 0; i < 10000; i++)
	{
		COMSmartPointer<IUnknown> t = CreateCOMObject<IUnknown>(wstring(L"Scripting.Dictionary"));
		COMSmartPointer<IUnknown> t1 = t;
		COMSmartPointer<IUnknown> t2 = t;
	}

	for(int i = 0; i < 10000; i++)
	{
		COMSmartPointer<IUnknown> t;
		t = CreateCOMObject<IUnknown>(wstring(L"Scripting.Dictionary"));
		COMSmartPointer<IUnknown> t1 = t;
		COMSmartPointer<IUnknown> t2 = t;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);

	Test();

	CoUninitialize();

	cin.get();

	return 0;
}

