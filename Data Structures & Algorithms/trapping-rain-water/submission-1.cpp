class Solution {
public:
    int trap(vector<int>& height) {
        //max(0, min(maxonleft, maxonright) - height[i])
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxl = 0;
        int maxr = 0;
        int trapped = 0;
        while(left < right){
            maxl = max(height[left], maxl);
            maxr = max(height[right], maxr);
            if(maxl < maxr){
                trapped += maxl - height[left];
                left++;
            }
            else{
                trapped += maxr - height[right];
                right--;
            }
        }
        return trapped;
    }
};
