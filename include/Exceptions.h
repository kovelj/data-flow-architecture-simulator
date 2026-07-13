#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include<exception>

#include<iostream>

using namespace std;
class Exception:public exception {
public:
	Exception(const char* msg) :exception(msg) {}
protected:
	//Moguca protected sekcija!
private:
	//Moguca private sekcija!
};

class VarNotAvailableException :public Exception {
public:
	VarNotAvailableException(const char* erroDesc) :Exception(erroDesc) {}
protected:
	//Moguca protected sekcija!
private:
	//Moguca private sekcija!
};

#endif//! _EXCEPTIONS_H_