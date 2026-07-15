#ifndef _MEMORY_H_
#define _MEMORY_H_

#include<iostream>
#include<string>
#include<vector>

class Memory {

public:
	double get(std::string varName);
	void   set(std::string varName, double val);

private:
	std::vector<char> promenljive_;
	std::vector<float> vrednost_;
};

#endif//! _MEMORY_H_
