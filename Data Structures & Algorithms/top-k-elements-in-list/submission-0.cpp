class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>>pq;
        for (const auto& pair : freq) {
            pq.push({pair.second, pair.first});
        }
        vector<int>res;
        while(k--){
            auto &x = pq.top();
            res.push_back(x.second);
            pq.pop();
        }
        return res;
    }
};
