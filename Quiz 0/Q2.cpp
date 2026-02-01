#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1000000007;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int testCases;
    std::cin >> testCases;

    while (testCases--) {
        int n, k;
        std::cin >> n >> k;
        
        long long curSum = 0;
        long long maxSum = 0;
        long long total = 0;
        
        for (int i = 0; i < n; ++i) {
            long long num;
            std::cin >> num;

            curSum = std::max(0LL, curSum + num);
            total += num;
            maxSum = std::max(maxSum, curSum);
        }
        
        // Compute: total + maxSum * (2^k - 1)
        long long multiplier = (power(2, k, MOD) - 1 + MOD) % MOD;
        long long contribution = (maxSum % MOD) * multiplier % MOD;
        
        long long result = ((total % MOD) + MOD + contribution) % MOD;
        std::cout << result << '\n';
    }

    return 0;
}