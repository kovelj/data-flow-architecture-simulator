#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include<exception>

#include<iostream>

class Exception : public std::exception {
public:
	Exception(const char* msg) : std::exception(msg) {}
protected:
	//Moguca protected sekcija!
private:
	//Moguca private sekcija!
};

class VarNotAvailableException : public Exception {
public:
	VarNotAvailableException(const char* erroDesc) : Exception(erroDesc) {}
protected:
	//Moguca protected sekcija!
private:
	//Moguca private sekcija!
};
#endif//! _EXCEPTIONS_H_