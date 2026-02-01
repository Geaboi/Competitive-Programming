#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

void handleTestCase(const std::unordered_set<std::string>& map, const std::vector<std::string>& list) {
    for(const auto& word : list){
        bool found = false;
        for(int i = 1; i < word.size(); i++){
            if(map.find(word.substr(0, i)) != map.end() && map.find(word.substr(i, word.size() - i)) != map.end()){
                std::cout << "1";
                found = true;
                break;
            }
        }
        if(!found){
            std::cout << "0";
        }
    }
}

int main() {
    int testCases;
    int n;

    std::cin >> testCases;
    while(testCases--) {
        std::unordered_set<std::string> map;
        std::vector<std::string> list;
        std::cin >> n;
        for(int i = 0; i < n; ++i) {
            std::string word;
            std::cin >> word;
            list.push_back(word);

            map.insert(word);
        }
        handleTestCase(map,list);
        std::cout << '\n';
    }


    return 0;
}