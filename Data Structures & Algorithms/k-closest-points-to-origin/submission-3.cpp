class Solution {
public:
    using Item = pair<double, vector<int>>;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Item, vector<Item>, greater<Item>> minPq;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            double dist = sqrt(((x - 0) * (x - 0))+ ((y - 0) * (y - 0)));
            minPq.push({dist, {x, y}});
        }
        vector<vector<int>>answer;
        while(k){
            auto tm = minPq.top();
            answer.push_back(tm.second);
            minPq.pop();
            k--;
        }
        return answer;
    }
};