class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int lc = 1;
        int maxlen = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1] + 1){
                lc++;
                maxlen = max(maxlen, lc);
            }
            else if(nums[i] == nums[i - 1]) continue;
            else lc = 1;
        }   
        return maxlen;     
    }
};
