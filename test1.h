#pragma once
#include"itask.h"
class Test1 :public ITask {
public:
	bool Run();
	void TestArray();
	void TestByte();
	void TestLambda();
	void TestSize();
};