//sequence a consisting of n integers.
//where the i-th eleemnt of the sequence is equal to a_i
//GIven the integers x and y
// A pair of integers is considered interesting if i and j in the range of 1 to n
//If you remove the elements at i and j from the sequence, the remaining sum is at least X and at most Y

//Can do a O(n^2) solution by checking all pairs of i and j, but that would be too slow for n up to 10^5
//Sort do a binary search to find the largest j for each i such that the sum of the remaining elements is at least X and at most Y

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        long long n, x, y;
        cin >> n >> x >> y;
        vector<long long> a(n);
        long long total_sum = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            total_sum += a[i];
        }

        long long target_min = total_sum - y;
        long long target_max = total_sum - x;


        sort(a.begin(), a.end());
        long long count = 0;
        for(int i = 0; i < n; i++){
            //Need to do a binary search to find the range of j such that the sum of the remaining elements is at least X and at most Y
            int left = i + 1, right = n -1;

            //Find the lower bound
            int l = left, r = right;
            int first_valid = -1;
            while(l <= r){
                int mid = l + (r- l) / 2;
                
                if(a[i] + a[mid] >= target_min && a[i] + a[mid] <= target_max){
                    first_valid = mid;
                    r = mid - 1;
                } else if(a[i] + a[mid] < target_min){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(first_valid == -1) continue;

            l = left, r = right;
            int last_valid = -1;

            while(l <= r){
                int mid = l + (r-l)/ 2;

                if(a[i] + a[mid] <= target_max && a[i] + a[mid] >= target_min){
                    last_valid = mid;
                    l = mid + 1;
                } else if(a[i] + a[mid] < target_min){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(last_valid == -1) continue;

            if(first_valid <= last_valid){
                count += (last_valid - first_valid + 1);
            }

        }

        cout << count << "\n";
    }


}