#include"ConfigReader.h"
#include"Compiler.h"
#include"Machine.h"
#include"Memory.h"
#include"Strategija.h"
#include<filesystem>

int main(int argc, char* argv[]) {

	if (argc < 3 ) {
		std::cout << "Usage: " << argv[0] << " <program_file.txt> <config_file.txt>" << std::endl;
		return 1;
	}

	const std::filesystem::path test_file(argv[1]);
	const std::filesystem::path config_file(argv[2]);

	std::cout << "Loading program file: " << test_file << std::endl;
	std::cout << "Loading config file: " << config_file << std::endl;

	ConfigReader config_reader;

	config_reader.read(config_file);

	// bool nastavi = true;
	// while (nastavi) {
	// 	Compiler* cmp = new Compiler();
	//
	// 	std::string imeFajla;
	// 	std::cout << "Unesite ime konfiguracionog fajla." << std::endl;
	//
	// 	std::cin >> imeFajla;
 //
	// 	cmp->strategijaBiranje(new Konfiguracija());
 //        cmp->kompajluj(imeFajla,0);
 //
	// 	std::cout << "Unesite ime programa." << std::endl;
	// 	std::cin >> imeFajla;
	//
	// 	cmp->strategijaBiranje(new Program());
	// 	cmp->kompajluj(imeFajla,1);
	//
	// 	delete cmp;
	//
	// 	std::cout << "Zelite li da nastavite?  D/N" << std::endl;
	// 	char c;
	// 	std::cin >> c;
	// 	if (c == 'n' || c == 'N') nastavi = false;
	// }

	return 0;
}