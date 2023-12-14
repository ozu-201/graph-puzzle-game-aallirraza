#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
class Dictionary {
private:
    std::vector<std::string> words;
    std::unordered_map<int, std::vector<std::string>> lengthGroups;

public:
    void readDictionary(const std::string& filename) {
        std::ifstream file(Dictionary1);
        if (file.is_open()) {
            std::string word;
            while (file >> word) {
                words.push_back(word);
            }
            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    void groupWordsByLength() {
        for (const auto& word : words) {
            int length = word.length();
            lengthGroups[length].push_back(word);
        }
    }

    const std::unordered_map<int, std::vector<std::string>>& getLengthGroups() const {
        return lengthGroups;
    }
};