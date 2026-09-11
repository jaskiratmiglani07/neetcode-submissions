class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>maxAhead(n);
        maxAhead[n - 1] = prices[n - 1];
        for(int i = n - 2; i >= 0; i--){
            maxAhead[i] = max(maxAhead[i + 1], prices[i]);
        } 
        // for(int i = 0; i < n; i++) cout << maxAhead[i] << " ";
        int maxProf = 0;       
        for(int i = 0; i < n - 1; i++){
            // cout << prices[i] - maxAhead[i + 1] << " ";
            maxProf = max(maxProf, maxAhead[i + 1] - prices[i]);
        }
        return maxProf;
    }
};
