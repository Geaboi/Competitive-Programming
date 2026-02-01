#include <iostream>

int main() {
    int lines;
    std::cin >> lines;

    int spectator = 3;
    int player1 = 1;
    int player2 = 2;
    int winner;
    bool valid = true;

    for(int i = 0; i < lines; ++i) {
        std::cin >> winner;
        
        if(winner == spectator){
            std::cout << "NO" << '\n';
            return 0;
        }else{
            if(winner == player1){
                std::swap(spectator, player2);
            }
            if(winner == player2){
                std::swap(spectator, player1);
            }
    }
}

    std::cout << "YES" << '\n';    
    return 0;
}