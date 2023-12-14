#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Graph {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjacencyList;

public:
    void buildGraph(const std::vector<std::string>& words) {
        for (const auto& word : words) {
            for (const auto& otherWord : words) {
                if (isValidConnection(word, otherWord)) {
                    adjacencyList[word].insert(otherWord);
                }
            }
        }
    }

    bool isValidConnection(const std::string& word1, const std::string& word2) const {
        return word1.length() == word2.length() && /* Add your condition here */;
    }

    const std::unordered_map<std::string, std::unordered_set<std::string>>& getAdjacencyList() const {
        return adjacencyList;
    }
};

int main() {
    Dictionary dictionary;
    Graph graph;

    dictionary.readDictionary("dictionary.txt");

    dictionary.groupWordsByLength();

    const auto& lengthGroups = dictionary.getLengthGroups();

    for (const auto& group : lengthGroups) {
        Graph subgraph;
        subgraph.buildGraph(group.second);

        const auto& adjacencyList = subgraph.getAdjacencyList();
    }

    return 0;
}