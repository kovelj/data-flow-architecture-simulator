#ifndef __COMPILER_H_
#define __COMPILER_H_
#include"Strategija.h"

#include<fstream>
#include<iomanip>
#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

class Compiler {

public:

	Compiler()=default;

	//Biranje strategije
	void strategijaBiranje(Strategija*);
	//Pozivanje strategije
	void kompajluj(const string&, int);
	void ispisiImfSimple(const string&);
	void ispisiImfAdvanced(const string&);
protected:
	//Moguca protected sekcija
private:
	
	void ocisti();

	vector<char> postfix_;//Postfix oblik izraza se cuva kao niz znakova. [0],[1],[2],[3],[4],[5]
	vector<int> konfiguracija_;//U ovom poredku se upisuju u vektor --    Ta, Tm, Te, Tw, Nw, compilation(simple=true)

	Strategija* strategija_= nullptr; //Strategija upis/ispis
};

#endif //! __COMPILER_H_