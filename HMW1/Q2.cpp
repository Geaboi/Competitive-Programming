#include <iostream>
#include <string>
#include <queue>

int main() {
    int testCases;
    std::cin >> testCases;
    while(testCases--) {
        std::priority_queue<int> maxHeap;
        int n;
        std::cin >> n;
        long long power = 0;
        for(int i = 0; i < n; ++i) {
            int num;
            std::cin >> num;
            if(num == 0){
                if(!maxHeap.empty()){
                    power += maxHeap.top();
                    maxHeap.pop();
                }
            }else{
                maxHeap.push(num);
            }
        }
        std::cout << power << std::endl;

    }

    return 0;
}