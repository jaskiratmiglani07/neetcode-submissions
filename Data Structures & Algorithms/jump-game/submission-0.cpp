class Solution {
public:
    bool solve(int i, vector<int> & nums){
        if(i == nums.size() - 1) return true;
        bool ans = false;
        for(int j = 1; j <= nums[i]; j++){
            ans = solve(i + j, nums);
            if(ans) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        bool ans = solve(0, nums);
        return ans;
    }
};
