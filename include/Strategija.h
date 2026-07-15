#ifndef _STRATEGIJA_H_
#define _STRATEGIJA_H_

#include<fstream>
#include<iomanip>
#include<stack>
#include<string>
#include<vector>

//Poslednji ispisani red da bih pamtio dokle sam stigao sa ispisom
static int IDReda = 1;
static int IDTokena = 1;

class Strategija {
public:
	//Za citanje konfiguracije
	virtual void citajKonf(const std::string&, std::vector<int>&) { };
	//Za citanje programa
	virtual void citajProg(std::fstream&, std::vector<char>&) { }

	//Za odabrani nacin stvaranja .imf fajla.
	virtual void pisi(std::fstream&, std::vector<char>&) { };

	//Da proveri da li je znak operand ili operator
	virtual bool isOperator(const char) const;
	virtual bool isOperand(const char)const;
};

class Program :public Strategija {
public:

	virtual void citajProg(std::fstream&, std::vector<char>&) override;
	int prioritet(const char) const;
	void infixPostfix(std::fstream&);
	void citajOperand(std::fstream&, std::string&);
	void citajOperator();
	void prepisi(std::vector<char>&) const;
	void slikaOgledalo(std::string&);
	void citajStack();

private:
	char c;
	bool vec_citao_ = false;
	bool prvo_citanje_ = true;

	std::stack<char> stack_;
	std::vector<char> postfix_;
};

class Konfiguracija : public Strategija {
public:

	virtual void citajKonf(const std::string&, std::vector<int>&) override;
	int citajVrednosti(std::fstream&) const;
	void citajKasnjenje(std::fstream&, std::vector<int>&);
	void citajTipKonf(std::fstream&, std::vector<int>&);
};

static int token = 1;

class NojmanIspis : public Strategija {
public:
	virtual void pisi(std::fstream&, std::vector<char>&) override;
	void ispisiPoFormatu(std::fstream&, char, std::string&, std::string&, std::string&);
	void ispisiStek(std::string&);
	//void ispisi();
private:
	
	std::stack<char> stack_; //Stek koji ce mi pomoci da vrsim ispis!!!
};

class ProtocniIspis : public Strategija {
public:
};
#endif//! _STRATEGIJA_H_