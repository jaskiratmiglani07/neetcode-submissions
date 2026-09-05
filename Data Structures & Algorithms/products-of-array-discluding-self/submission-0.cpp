class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>suffi(n);
        vector<int>prefi(n);
        suffi[n - 1] = nums[n - 1];
        prefi[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefi[i] = prefi[i - 1] * nums[i];
        }
        for(int i = n - 2; i >= 0; i--){
            suffi[i] = suffi[i + 1] * nums[i];
        }
        vector<int>output(n);
        output[0] = suffi[1];
        output[n - 1] = prefi[n - 2];
        for(int i = 1; i < n - 1; i++){
            output[i] = prefi[i - 1] * suffi[i + 1];
        }
        return output;
    }
};
