#include <iostream>
#include <vector>

using namespace std;

int hanoi(int n, int src, int dst, int aux){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }


    return hanoi(n - 1, src, dst, aux);

}

int main(){
    int n;
    cin >> n;


    //Explore all possible ways?
    //Find a heuristic and then code it out
    //put the biggest in the rightmost stack

    /*
        case 1:  0. 0. 1

        Case 2:
                1
                2

                2 1 0

                0 1 2

                    1
                0 0 2

        Case 3:

                1
                2
                3

                2
                3. 0 1

                3  2. 1

                   1
                3. 2. 0

                   1
                0  2. 3
                
                
                1 2 3

                 
                    2
                1 0 3

                    1
                    2
                0 0 3
       
    */
}