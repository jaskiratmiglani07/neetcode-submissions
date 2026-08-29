class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n + 1);
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int>result(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        result[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &x : adj[node]){
                int nei = x.first;
                int t = x.second;
                if(d + t < result[nei]){
                    result[nei] = d + t;
                    pq.push({d + t, nei});
                }
            }
        }
        int answer = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(result[i] == INT_MAX) return -1;
            answer = max(result[i], answer);
        }
        return answer;
    }
};
