class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int res = 0, suffixSum = 0;
        for (int s : satisfaction) {
            suffixSum += s;
            if (suffixSum <= 0) break;
            res += suffixSum;
        }
        return res;
    }
};