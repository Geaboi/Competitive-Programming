#include <iostream>
#include <deque>
#include <vector>


int main(){
    int testCases;

    std::cin >> testCases;
    while(testCases--){
        std::deque<int> dq;
        int n;
        std::cin >> n;
        for(int i = 0; i < n; ++i){
            int x;
            std::cin >> x;

            if(dq.empty()){
                dq.push_back(x);
            }else if(x > dq.front()){
                dq.push_back(x);
            }else if(x < dq.front()){
                dq.push_front(x);
            } else{
    bool addToFront = false;
    for(int j = 1; j < dq.size(); j++) {
        if(x < dq[j]) {
            addToFront = true;
            break;
        } else if(x > dq[j]) {
            addToFront = false;
            break;
        }
    }
    
    if(addToFront) {
        dq.push_front(x);
    } else {
        dq.push_back(x);
    }

            }

        }
        for(int val : dq) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    
    return 0;
}