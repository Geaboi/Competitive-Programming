class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return countAndMergeSort(sums, 0, n + 1, lower, upper);
    }

private:
    int countAndMergeSort(vector<long long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        
        int mid = start + (end - start) / 2;
        int count = countAndMergeSort(sums, start, mid, lower, upper) +
                    countAndMergeSort(sums, mid, end, lower, upper);
        
        // Count the valid ranges crossing the midpoint
        int j = mid, k = mid, t = mid;
        vector<long long> cache(end - start);
        int r = 0;
        
        for (int i = start; i < mid; ++i) {
            // Find the window [j, k) in the right half that satisfies the condition
            while (k < end && sums[k] - sums[i] < lower) k++;
            while (j < end && sums[j] - sums[i] <= upper) j++;
            count += (j - k);
            
            // Standard merge sort part: filling the cache
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r++] = sums[i];
        }
        
        // Copy the sorted elements back
        for (int i = 0; i < r; ++i) {
            sums[start + i] = cache[i];
        }
        return count;
    }
};