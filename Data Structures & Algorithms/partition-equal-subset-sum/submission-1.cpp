class Solution {
public:
    bool solve(int i, int target, vector<int>& nums){
//i have two choices for every index, i can either choose it for creating my target sum or not choose it
        if(target == 0) return true;
        if(target < 0) return false;
        if(i >= nums.size()) return false;
        if(solve(i + 1, target - nums[i], nums) || solve(i + 1, target, nums)) return true;
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &x : nums){
            sum += x;
        }
        if(sum % 2 != 0) return false;
        int target = sum/2;
        return solve(0, target, nums);
    }
};
