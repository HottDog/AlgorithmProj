#include"test1.h"
#include<iostream>
using namespace std;

class Base
{
public:
	Base(){}
	virtual void Fun() {};
	virtual void Fun1() final {};
};

class A :public Base
{
public:
	int a;
	char b;
	long long int c;
	Base aaa;
	void Fun()override {};
};

bool Test1::Run() {
	//cout << "¹þ¹þ" << endl;
	//TestByte();
	//TestLambda();
	TestSize();
	return true;
}

void Test1::TestArray()
{
	int**p = new int *[3];
	int * p1 = new int[10];
	p1[0] = 1;
	p1[1] = 2;
	p[0] = p1;
}

void Test1::TestByte()
{
	cout << (0x01<<2)<<endl;
}


void Test1::TestLambda()
{
	int b = 3;
	auto fun = [&b](int a) { 
		a++;
		b++;
		return a + 1; 
	};
	cout << fun(b)<<",b:"<<b<<endl;
}

void Test1::TestSize()
{
	int * i = 0;
	cout << "*i : " << sizeof(i)<<endl;
	cout << "A::b : "<<sizeof(A::b) << endl;
	cout << "A::c : " << sizeof(A::c) << endl;
	cout << "A::aaa : " << sizeof(A::aaa) << endl;
}