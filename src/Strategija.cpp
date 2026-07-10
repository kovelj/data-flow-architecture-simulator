#include "Strategija.h"
#include<iostream>

bool Strategija::isOperator(const char c) const
{
	if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
		return true;
	return false;
}

bool Strategija::isOperand(const char c) const
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return true;
	return false;
}


void Program::citajProg(fstream& program,vector<char>& postfix)
{
	char dodeli;
	char c;
	//Cita se ona prom. u koju se upise vr. celog izraza sa desne strane.
	program >>dodeli>> c;
	postfix_.push_back(dodeli);
	//Specijalni slucaaj kada je potrebno da se ubaci negacija broja

	infixPostfix(program);

	//Da ne bih vukao po referenci ja cu na kraju samo izvrsiti prepisivanje iz lokalnog izraza
	prepisi(postfix);
	
}


int Program::prioritet(const char c) const
{
	if (stack_.empty())
		return 0;
	else if (c == '(')
		return 4;
	else if (c == '^')
		return 3;
	else if (c == '*' || c=='/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
}

void Program::infixPostfix(fstream& program)
{
	vec_citao_ = false;
	prvo_citanje_ = true;

	while (program.peek() != '\n' && program.peek()!=EOF)
	{
		if (!vec_citao_)
		{
			//Ako se dalje u programu bude nailazilo na opcije koje ne zahtevaju da se cita znak unapred da bi se znao uslov za njihov izlazak!!!
			program >> c;
		}
	
		//Ako je operand recimo {A,B,C.. 1,2,3..} samo se stavi u vektor.
		//Medjutim sta ako mi je operand visecifreni broj{X=123+B}? Zbog togo moram da napravim sliku u ogledalu. Takodje moram i da citam sve dok se ne dodje do operatora.
		if (isOperand(c) || (prvo_citanje_ && c=='-' ))
		{
			if (c == '-')
				prvo_citanje_ = false;
			string operand;
			citajOperand(program,operand);
			slikaOgledalo(operand);
		}
		
		//Ako se naidje na operator treba da se proveri sledece. Ako je veceg prioriteta
		else if (isOperator(c))
		{
			if (c == '(')
			{
				stack_.push(c);
				vec_citao_ = false;
			}
			else if (stack_.empty() || stack_.top()=='(')
			{
				stack_.push(c);
				vec_citao_ = false;
			}
			else if (c == ')') 
			{
				bool nasao = false;
				while ((!(stack_.empty())) && stack_.top()!='(')
				{
					citajStack();
					if (stack_.top() == '(') 
				    {
						nasao = true;
						stack_.pop();
					}
				}
				if (!nasao)
					cout<<"Postoji greska jer nije nadjena ( program ne garantuje tacnost rezultata ako se uopste izvrsi !!!"<<endl;
				vec_citao_ = false;
			}
			else if (prioritet(c) > prioritet(stack_.top()))
			{
				stack_.push(c);
				vec_citao_ = false;
			}
			else if ( prioritet(c) < prioritet(stack_.top()))
			{
				citajStack();
				
				while (!stack_.empty() && prioritet(c) < prioritet(stack_.top())) 
				{
					citajStack();
				}
			}
			else if (prioritet(c) == prioritet(stack_.top()))
			{
				//Asocijativnost. Ako je sleva na desno stampam top() i pop-ujem. Ako je sa desna na levo onda push(){Sto je samo slucaj sa ^}
				if (c == '^')
				{
					stack_.push(c);
					vec_citao_ = false;
				}
					//Asocijativnost je sleva na desno stampam i izbrisem  vrh steka pa dodam novi procitani operator.
				else
				{
					citajStack();
					stack_.push(c);
					vec_citao_ = false;
				}
			}
		}
	}
	//Ispisuje sve operatore koji su ostali na stack-u ako ih ima 
	while (!stack_.empty()) 
	{
		citajStack();
	}
}

void Program::citajOperand(fstream& program, string& operand)
{
	operand += c;

	if (program.peek() != '\n' && program.peek() != EOF)
	{
		program >> c;
		vec_citao_ = true;

		while ((program.peek() != '\n') && !(isOperator(c)) && (program.peek()!=EOF))
		{
			operand += c;
			program >> c;
		}
		if (!isOperator(c))
			operand += c;
	}
}

void Program::prepisi(vector<char>& postfix) const
{
	//Svrha metode je da prepise ovo jer me mrzi da svud u metodama prenosim ovaj vektor iz Compiler-a, a zbog prava pristupa cu koristiti lokalni za ovu klasu!!!
	for (int i = 0; i < postfix_.size(); i++)
		postfix.push_back(postfix_[i]);

	//Znak koji ce mi reci da sam dosao do kraja vektora je znak za dodelu vrednosti '='
	postfix.push_back(' ');
	postfix.push_back('=');
}

void Program::slikaOgledalo(string& operand)
{
	//Hocu da mi se izmedu bilo koja dva da li operanda nalazi razmak ' '.Ali ako je prvi operand koji se upisuje ispred njega mi nije potreban razmak.

	postfix_.push_back(' ');

	int l = operand.length();
	for (int i = l - 1; i >= 0; i--)
		postfix_.push_back(operand[i]);
}

void Program::citajStack()
{
	postfix_.push_back(' ');
	postfix_.push_back(stack_.top());
	stack_.pop();
}

void Konfiguracija::citajKonf(const string& ime_fajla,vector<int>& konfiguracija)
{
	fstream konf_fajl(ime_fajla, ios::in);
	while (konf_fajl.peek() != EOF) 
	{
		char t;
		konf_fajl >> t;
		
			if (t == 'T')
			{
				citajKasnjenje(konf_fajl,konfiguracija);
				
			}
			else if (t=='N') 
			{
				konf_fajl >> t>>t;
				konfiguracija.push_back(citajVrednosti(konf_fajl));
				
			}
			else if (t == 'c') 
			{
				citajTipKonf(konf_fajl,konfiguracija);
			}
			
		
	}
	for (int i = 0; i < 6; i++)
		std::cout << konfiguracija[i];
	std::cout << endl;
	konf_fajl.close();
}


int Konfiguracija::citajVrednosti(fstream& ulazni_fajl) const
{
	string broj;
	char c;
	while (ulazni_fajl.peek() != '\n')
	{
		ulazni_fajl >> c;
		broj += c;
	}
	int vrati = 0;
	int stepen = 1; int l = broj.length();
	for (int i = 0; i < broj.length(); i++) 
	{
		vrati += (broj[l-i-1] - '0')*stepen;
		stepen *= 10;
	}
	return vrati;
}

void Konfiguracija::citajKasnjenje(fstream& ulazni_fajl, vector<int>& konfiguracija)
{
	char operacija;
	char t;
	//Citanje operacije i znaka '='
	ulazni_fajl >> operacija >> t;

	int b = citajVrednosti(ulazni_fajl);
	konfiguracija.push_back(b);
}

void Konfiguracija::citajTipKonf(fstream& fajl,vector<int>& konfiguracija)
{
	bool desno = false, simple = true;
	string kompilacija;
	char t;
	fajl >> t;

	while (fajl.peek() != EOF)
	{
		if (t == '=') desno = true;
		if (!desno)
			fajl >> t;
		else
		{
			fajl >> t;
			kompilacija += t;
			if (kompilacija == "advanced")
				simple = false;
		}
	}
	konfiguracija.push_back(int(simple));
}

static int i = 0;

void NojmanIspis::pisi(fstream& imf, vector<char>& podaci)
{
	//U ovom vektoru se u sledecem formatu naleze podaci --[posl. token u koji se upisuje nesto]'blanko'[Ako je prvi oerand negiran{-}Moze biti, a i nemora]'blanko'[operadni[blanko]operatori[blanko]....]

	i =2 ;

	string dodeli;
	dodeli += podaci[0];

	string prvi, drugi;
	string ne_pisi = "nema tokena";


	while (podaci[i] != '=') 
	{
		//Ako je operand
		if (!isOperator(podaci[i])) 
		{
			if (!stack_.empty())
				stack_.push(' ');
		
			while (podaci[i] != ' ') 
				stack_.push(podaci[i++]);
			i++;
		}
		//Ako je operator
		else if(isOperator(podaci[i]))
		{
			char operacija = podaci[i];
			i += 2;
			
			string token = "t";
			token += to_string(IDTokena);
			IDTokena++;
			
			ispisiStek(drugi);
			ispisiStek(prvi);
			ispisiPoFormatu(imf,operacija,token,prvi,drugi);
			prvi.clear();
			drugi.clear();

			int l = token.length();
			stack_.push(' ');

			for (int i = l - 1; i >= 0; i--)
				stack_.push(token[i]);
		}

	}
	ispisiStek(drugi);
	ispisiPoFormatu(imf,'=',dodeli,drugi,ne_pisi);

}

void NojmanIspis::ispisiPoFormatu(fstream& fajl, char operacija, string& prviToken, string& drugiToken, string& treciToken)
{
	if (treciToken == "nema tokena")

		fajl << '[' << IDReda << ']' << ' ' << operacija << ' ' << prviToken << ' ' << drugiToken << endl;
	else
		fajl << '[' << IDReda << ']' << ' ' << operacija << ' ' << prviToken << ' ' << drugiToken << ' ' << treciToken << endl;

	IDReda++;
}

void NojmanIspis::ispisiStek(string& token)
{
	while (!stack_.empty() && stack_.top() != ' ')
	{
		token += stack_.top();
		stack_.pop();
	}
	if (!stack_.empty())
		stack_.pop();
}
