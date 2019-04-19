#include<iostream>
#include"itask.h"
#include"test1.h"
#include"TestBST.h"
using namespace std;

int main() {
	ITask * task;
	//task = new Test1();
	task = new TestBST;
	task->Run();
	system("pause");
	return 0;
}