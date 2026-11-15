class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int target = -1 * nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < nums.size() && left < right){
                int x = nums[left] + nums[right];
                if(x == target){
                    answer.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                if(x < target) left++;
                if(x > target) right--;
            }           
        }
        vector<vector<int>>result(answer.begin(), answer.end());
        return result;
    }
};
