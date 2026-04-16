#include "CaesarUtil.h"
#include <string>

std::string CaesarUtil::Decrypt(const std::string cipherText, const int key) {
	std::string decodedText{};
	for (char c : cipherText) {
		if (c == ' ') decodedText.push_back(c);
		else  decodedText.push_back((c - 'a' - key + 26) % 26 + 'a');
	}
	return decodedText;
}
