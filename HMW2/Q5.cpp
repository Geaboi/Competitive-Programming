class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
 int count = 0;
        int cumSum = 0;
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1; 
        
        for (int num : nums) {
            cumSum += num;
            
            if (sumFreq.find(cumSum - k) != sumFreq.end()) {
                count += sumFreq[cumSum - k];
            }
            
            sumFreq[cumSum]++;
        }
        
        return count;
    }
};