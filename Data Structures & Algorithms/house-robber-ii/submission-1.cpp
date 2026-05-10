class Solution {
public:
    int solve(vector<int>&nums, int i, vector<int>&t1){
        if(i >= nums.size())
            return 0;
        if(t1[i] != -1)
            return t1[i];
        int skip = 0, take = 0;
        skip = solve(nums, i+1, t1);
        take = nums[i] + solve(nums, i+2, t1);
        return t1[i] = max(skip, take);
    }
    int solve1(vector<int>&nums, int i, vector<int>&t2){
        if(i >= nums.size()-1)
            return 0;
        if(t2[i] != -1)
            return t2[i];
        int skip = 0, take = 0;
        skip = solve1(nums, i+1, t2);
        take = nums[i] + solve1(nums, i+2, t2);
        return t2[i] = max(skip, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1)
        return nums[0];
        vector<int>t1(n, -1);
        int res1 = solve(nums, 1, t1); 
        vector<int>t2(n, -1);
        int res2 = solve1(nums, 0, t2);
        return max(res1, res2);
    }
};