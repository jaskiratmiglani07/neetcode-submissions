class Solution {
public:
    int trap(vector<int>& height) {
        //max(0, min(maxonleft, maxonright) - height[i])
        int n = height.size();
        vector<int>mol(n);//i-1 to 0
        vector<int>mor(n);//i+1 to n-1
        mol[0] = height[0];
        for(int i = 1; i < n; i++)
            mol[i] = max(height[i], mol[i - 1]);
        mor[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--)
            mor[i] = max(height[i], mor[i + 1]);
        int trapped = 0;
        for(int i = 0; i < n; i++){
            int maxonleft = mol[i];
            int maxonright = mor[i];
            int water = max(0, min(maxonleft, maxonright) - height[i]);
            trapped += water;
        }
        return trapped;
    }
};
