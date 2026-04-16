#include "Cryptanalysis.h"
#include "CaesarUtil.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <array>

static const std::unordered_set<std::string> COMMON_WORDS = {
	"the", "be", "to", "of", "and", "a", "in", "that", "have", "i", "it", "for", "not", "on", "with", "he", "as",
	"you", "do", "at", "this", "but", "his", "by", "from", "they", "we", "say", "her", "she", "or", "an", "will",
	"my", "one", "all", "would", "there", "their", "what", "so", "up", "out", "if", "about", "who", "get", "which",
	"go", "me"
};

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
	std::string cipherText = buffer.str();

	performAnalysis(cipherText);
	file.close();
}


void Cryptanalysis::performAnalysis(const std::string& cipherText) {
	//Word list - try each key and for each one check for 50 most common words
	//score by total matches, present top 3 scorers and print to screen
	//Assume cipherText contains spaces. assume cipherText is all lowercase letters
	
	std::vector<std::pair<int, int>> results; //score, key
	std::string testMethod{};

	if (cipherText.find(' ') != std::string::npos) {
		testMethod = "WORD FREQUENCY";
		for (int i{}; i < 26; i++) {
			std::string testCase = CaesarUtil::Decrypt(cipherText, i);
			int score{};
			std::istringstream stream(testCase); // stream operator for white space
			std::string word;
			while (stream >> word) {
				score += COMMON_WORDS.count(word);
			}
			std::pair result{ score, i };
			results.push_back(result);

		}
		std::sort(results.begin(), results.end(), std::greater<>());
	}

	else {
		testMethod = "LETTER FREQUENCY";
		std::array<int, 26> freqs{};
		for (char c : cipherText) {
			freqs[c - 'a']++;
		}
		for (int i{0}; i < 26; i++ ) {
			results.push_back({ freqs[i], i});
		}
		std::sort(results.begin(), results.end(), std::greater<>());
		for (int i{}; i < 3; i++) {
			results[i].second = ((results[i].second +26)- ('e' - 'a')) % 26;
		}
	}

	std::cout << "\n\nCRYPTANALYSIS RESULTS: \n\n";
	std::cout << "METHOD: " << testMethod << "\n\n";

	std::cout << "TOP RESULT: \n";
	std::cout << "SCORE: " << results[0].first << "\n";
	std::cout << "KEY: " << results[0].second << "\n\n";
	std::cout << CaesarUtil::Decrypt(cipherText, results[0].second) << "\n\n";

	std::cout << "SECOND RESULT: \n";
	std::cout << "SCORE: " << results[1].first << "\n";
	std::cout << "KEY: " << results[1].second << "\n\n";
	std::cout << CaesarUtil::Decrypt(cipherText, results[1].second) << "\n\n";

	std::cout << "THIRD RESULT: \n";
	std::cout << "SCORE: " << results[2].first << "\n";
	std::cout << "KEY: " << results[2].second << "\n\n";
	std::cout << CaesarUtil::Decrypt(cipherText, results[2].second) << "\n\n";
}

