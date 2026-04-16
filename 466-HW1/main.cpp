#include <iostream>
#include <limits>
#include "Cryptanalysis.h"

using namespace std;

int main() {
	bool exitFlag{ false };

	while (!exitFlag) {
		cout << "Welcome! \n\n";
		cout << "Please select one of the following options: \n";

		cout << "1. Encrypt plaintext with a key \n";
		cout << "2. Decrypt ciphertext with a key \n";
		cout << "3. Perform cryptanalysis on cipertext \n";
		cout << "4. Exit \n";

		int selection{};
		
		if (!(cin >> selection)) {
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "Error, please enter only a positive integer from 1 to 4.\n";
		}

		switch (selection) {
		case 1: break;//Encrypt
		case 2: break;//Decrypt
		case 3: Cryptanalysis::analyze(); break;//Cryptanalysis
		case 4: exitFlag = true; break;
		default: cout << "Invalid option, please enter an option from 1 to 4.\n";
		}
	}
}