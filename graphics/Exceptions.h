#pragma once

#include<string>

class Exceptions {
public:
	virtual std::string getMessage() = 0;
};

class PoliNotInVector : public Exceptions {
public:
	virtual std::string getMessage() {
		std::string s = "Wrong index of polinom!\nPolinom is not in vector";
		return s;
	}
};
