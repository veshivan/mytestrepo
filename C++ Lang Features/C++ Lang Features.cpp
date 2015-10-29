// C++ Lang Features.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template<typename X, typename Y>
void foo_auto_1(const X& x, const Y& y)
{
	auto z = x * y;
	cout << z << endl;
}

void foo_auto_2()
{
	auto a = 4.5, b = 5.6;
	auto c = 7.0, *p = &c, &r = *p;
	// auto d = 8, str = "error"; //Comiler Error

	const auto e = c;
	const auto& f = b;
	const auto* g = &b;
}

void foo_decltype()
{
	auto i = 10; // int
	cout << typeid(decltype(i + 1.0)).name() << endl; //prints "double"

	vector<int> a;
	decltype(a) b;
	b.push_back(10);
	b.push_back(20);
	decltype(b)::iterator iterB = b.begin(),
		                  iterE = b.end();

	while (iterB != iterE)
	{
		cout << *iterB << endl;
		iterB++;
	}
}

template<typename X, typename Y>
auto foo_multiply(X x, Y y) ->decltype(x*y)
{
	return x * y;
}

class function_store
{
	function<bool(double)> m_func;
public:
	function<int(int)> get_abs()
	{
		return [](int i){ return abs(i); };
	}

	void set_func(const function<bool(double)>& func)
	{
		m_func = func;
	}
};

void foo_lamda1()
{
	function_store fs;

	fs.set_func([](double d){ return d > 0.0; });

	auto fabs = fs.get_abs();
	cout << fabs(-10) << endl;
}

function<int()> foo_f()
{
	int a = 5, b = 7;
	
	return [a,b](){ return a + b; };
}

void foo_lamda2()
{
	auto lamda_func = foo_f();

	cout << lamda_func() << endl;
}

void foo_lamda3(int NthFib)
{
	function<int(int)> fibonacci = [&](int n)->int 
	{
		if (n < 0) 
			return -1;
		else if (n == 1 || n == 2)
			return n;
		else
			return fibonacci(n - 1) + fibonacci(n - 2);
	};

	cout << NthFib << "th fibonacci is " << fibonacci(NthFib) << endl;
}

void foo_lamda4()
{
	typedef int(*func)();

	func f = [](){ return 101; };

	f(); //store lamda function in function pointer if it does not capture any variables
	     //If its capturing variables then use std::function<> to store lamdas.
}

//<<TODO>>: nested lamdas

// [capture_list](parameter_list) mutable exception_spec -> return_type { body }
int _tmain(int argc, _TCHAR* argv[])
{
	foo_auto_1<int,int>(5, 7);
	foo_auto_1<int,double>(2, 1.7);

	foo_decltype();

	cout << foo_multiply<float, float>(1.0, 5.5) << endl;

	foo_lamda1();
	foo_lamda2();
	foo_lamda3(10); //Recursion
	foo_lamda4();   //Store lamda in function pointer

	getchar();
	return 0;
}

