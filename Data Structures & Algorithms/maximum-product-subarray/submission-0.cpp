class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int temp = 1;
                for(int k = i; k <= j; k++){
                    temp *= nums[k];
                }
                maxi = max(temp, maxi);
            }
        }
        return maxi;
    }
};
