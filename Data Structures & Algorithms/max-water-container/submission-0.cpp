class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int left = 0;
        int right = heights.size() - 1;
        while(left < right){
            int x = (right - left) * min(heights[left], heights[right]);
            if(x > maxArea) maxArea = x;
            if(heights[left] >= heights[right]) right--;
            else left++;
        }
        return maxArea;        
    }
};
