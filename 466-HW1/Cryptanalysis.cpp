#include "Cryptanalysis.h"
#include <iostream>
#include <fstream>
#include <sstream>


void Cryptanalysis::analyze() {
	std::cout << "Enter file path for ciphertext: ";
	std::string path{};
	std::cin >> path;

	std::ifstream file(path);
	if (!file.is_open()) {
		std::cout << "Error: could not open file.\n";
		return;
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string ciphertext = buffer.str();

	file.close();
}


void Cryptanalysis::performAnalysis(const std::string& ciphertext) {
	//Word list - try each key and for each one check for 50 most common words

	//the, be, to, of, and, a, in, that, have, I, it, for, not, on, with, he, as,
	//you, do, at, this, but, his, by, from, they, we, say, her, she, or, an, will,
	//my, one, all, would, there, their, what, so, up, out, if, about, who, get, which
	//go, me

	//score by total matches, present top 3 scorers and print to decoded.txt
	
}

