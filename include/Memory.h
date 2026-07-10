#ifndef _MEMORY_H_
#define _MEMORY_H_

#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Memory {

public:
	double get(string varName);
	void   set(string varName, double val);
protected:

private:
	//
	vector<char> promenljive_;
	vector<float> vrednost_;
};

#endif//! _MEMORY_H_
