#ifndef _TOKEN_H_
#define _TOKEN_H_

#include<string>

class Token {

public:

	Token() = default;

private:

	double value_;
	std::string name_;
	char id_;

};
#endif _TOKEN_H_