#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string query, word1, word2, word;
    int Q;
    cin >> Q;
    std::map<string, std::set<string>> synonyms;

    for (int i = 0; i < Q; i++) {
        cin >> query;
        if (query == "ADD") {
            cin >> word1 >> word2;

            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }
        else if (query == "CHECK") {
            cin >> word1 >> word2;
            
            bool isSynonyms = false;
            auto it = synonyms.find(word1);
            if (it != synonyms.end())
                if (it->second.find(word2) != it->second.end()) {
                    isSynonyms = true;
                }
            cout << (isSynonyms ? "YES" : "NO") << endl;
        }
        else if (query == "COUNT") {
            cin >> word;
            size_t count;

            auto it = synonyms.find(word);
            if (it != synonyms.end()) {
                count = it->second.size();
            }
            else {
                count = 0;
            }
            cout << count << endl;
        }
    }
    return 0;
}