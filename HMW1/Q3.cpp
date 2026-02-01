#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

int main(){
    int testCases;
    std::cin >> testCases;

    while(testCases--){
        int n,k;
        std::cin >> n >> k;
        std::vector<int> ac(k);
        std::vector<int> temp(k);
        for(int i = 0; i < k; ++i){
            std::cin >> ac[i];
        }

        std::unordered_map<int, int> acMap;
        
        for(int i = 0; i < k; ++i){
            std::cin >> temp[i];
            acMap[ac[i]] = temp[i];
        }


        std::vector<int> leftBest(n+2,2e9);
        std::vector<int> rightBest(n+2,2e9);
        
        for(int i = 1; i <= n; i++){
            if(acMap.find(i) != acMap.end()){
                leftBest[i] = std::min(leftBest[i - 1] + 1, acMap[i]);
            } else{
                leftBest[i] = leftBest[i - 1] + 1;
            }
        }

        for(int i = n; i >= 1; i--){
            if(acMap.find(i) != acMap.end()){
                rightBest[i] = std::min(rightBest[i + 1] + 1, acMap[i]);
            } else{
                rightBest[i] = rightBest[i + 1] + 1;
            }
        }

        for(int i = 1; i <= n; i++){
            std::cout << std::min(leftBest[i], rightBest[i]) << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}