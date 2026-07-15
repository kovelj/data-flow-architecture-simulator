#include"Compiler.h"
#include"Machine.h"
#include"Memory.h"
#include"Strategija.h"

int main() {
	
	    bool nastavi = true;
		while (nastavi) 
		{
			Compiler* cmp = new Compiler();

			std::string imeFajla;
			std::cout << "Unesite ime konfiguracionog fajla." << std::endl;
			
			std::cin >> imeFajla;

			cmp->strategijaBiranje(new Konfiguracija());
            cmp->kompajluj(imeFajla,0);

			std::cout << "Unesite ime programa." << std::endl;
			std::cin >> imeFajla;
	
			cmp->strategijaBiranje(new Program());
			cmp->kompajluj(imeFajla,1);
	
			delete cmp;
			
			std::cout << "Zelite li da nastavite?  D/N" << std::endl;
	
			char c;
			std::cin >> c;
			if (c == 'n' || c == 'N') nastavi = false;
		}

	return 0;
}