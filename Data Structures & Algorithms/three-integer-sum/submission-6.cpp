class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -1 * nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < nums.size() && left < right){
                int x = nums[left] + nums[right];
                if(x == target){
                    answer.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) left++; 
                    while(left < right && nums[right] == nums[right + 1]) right--; 
                }
                else if(x < target) left++;
                else if(x > target) right--;
            }           
        }
        return answer;
    }
};
