#include <iostream>
#include <optional>
#include <vector>

using namespace std;

template<typename T>
class RingBuffer {
    private:
    int head = 0;
    int tail = 0;
    int size;
    int max_capacity;
    vector<T> buffer;

    public:
    RingBuffer();
    RingBuffer(int max_c) : max_capacity(max_c), size(0), buffer(max_c) {};


    void push(T val){
        buffer[tail] = val;
        tail = (tail + 1) % max_capacity;

        if(size == max_capacity){
            head = (head + 1) % max_capacity;

        }else{
            size++;
        }
    };

    std::optional<T> pop(){
        if(size == 0) return nullopt;
        
        T val = buffer[head];

        size--;
        head = (head + 1) % max_capacity;
        
        return val;
    }



};