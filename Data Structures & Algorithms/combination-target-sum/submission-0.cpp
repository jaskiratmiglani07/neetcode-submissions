class Solution {
public:
    vector<vector<int>> answer;
    void solve(int i, int target, vector<int>& nums, vector<int>& equalsSum){
        //pick or not pick
        if(target == 0){
            answer.push_back(equalsSum);
            return;
        }
        if(i >= nums.size()){
            return;
        }
        if(target - nums[i] >= 0){
            equalsSum.push_back(nums[i]);
            solve(i, target - nums[i], nums, equalsSum);
            equalsSum.pop_back();
        }
        solve(i + 1, target, nums, equalsSum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>equalsSum;
        solve(0, target, nums, equalsSum);
        return answer;
    }
};
