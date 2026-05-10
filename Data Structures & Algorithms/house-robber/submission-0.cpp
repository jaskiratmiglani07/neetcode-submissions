class Solution {
public:
    int solve(vector<int>&nums, int i, vector<int>&t){
        if(i >= nums.size())
            return 0;
        if(t[i] != -1)
            return t[i];
        int skip = 0, take = 0;
        skip = solve(nums, i+1, t);
        take = nums[i] + solve(nums, i+2, t);
        return t[i] = max(skip, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        vector<int>t(n, -1);
        int res = solve(nums, 0, t); 
        return res;
    }
};
