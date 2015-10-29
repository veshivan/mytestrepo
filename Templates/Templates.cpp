// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

////// Variadic Templates
template<typename... Types>
struct TupleSize;

template<typename Head, typename ... Tail>
struct TupleSize<Head, Tail ...>
{
	static const size_t value = sizeof(Head)+TupleSize<Tail...>::value;
};

template<>
struct TupleSize<>
{
	static const size_t value = 0;
};

void foo_variadic_template_packs()
{
	cout << "TupleSize<>::value = " << TupleSize<>::value << endl;
	cout << "TupleSize<char, int, double>::value = " << TupleSize<char, int, double>::value << endl;
}
//////

//////Constraining parameter packs to one type
template<typename... Strings>
void output_string(const string& s, Strings& ...strings)
{
	cout << s << endl;
	output_string(strings...);
}

void output_string(const string& s)
{
	cout << s << endl;
}

void foo_constrained_parameter_packs()
{
	output_string("one", "two", "three", "four", "five");
}

/////Template Aliases

template<typename Stream>
struct StreamDeleter
{
	void operator()(Stream* os) const
	{
		os->close();
		delete os;
	}
};

template<typename Stream>
using StreamPtr = unique_ptr<Stream, StreamDeleter<Stream>>;

template<typename T>
using StMap = map<string, T>;

void foo_Templt_Aliases()
{
	StMap<int> st_int;
	st_int["one"] = 1;
	st_int["two"] = 2;

	StreamPtr<ofstream> ptr(new ofstream("log.log"));
	*ptr << "Hello ..." << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	foo_variadic_template_packs();

	foo_constrained_parameter_packs();

	foo_Templt_Aliases();

	getchar();
	return 0;
}

