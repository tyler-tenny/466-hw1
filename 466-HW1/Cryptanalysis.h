#pragma once
#include <string>

class Cryptanalysis
{
public:
	static void analyze();

private:
	static void performAnalysis(const std::string& ciphertext);
};

