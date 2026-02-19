class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int far = 0;
        int jumps = 0;

        while(far < nums.size() - 1){
            int farthest = 0;
            for(int i = cur; i <= far; i++){
                farthest = max(farthest, nums[i] + i);
            }
            cur = far + 1;
            far = farthest;
            jumps++;
        }

        return jumps;
    }
};