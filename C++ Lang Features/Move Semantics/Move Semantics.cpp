// Move Semantics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class A
{
public:
	A()
	{
		cout << " A's constructor" << endl;
	}
	A(const A&)
	{
		cout << " A's copy constructor" << endl;
	}
	A(A&&)
	{
		cout << " A's move constructor" << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<A> v;
	cout << "==> push_back A" << endl;
	v.push_back(A());
	cout << "==> push_back A" << endl;
	v.push_back(A());
	cout << __alignof(double);
	getchar();
	return 0;
}

