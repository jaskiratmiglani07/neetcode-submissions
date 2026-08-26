class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        unordered_map<int, int>indegree;
        for(int i = 0; i < n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }   
        // for(int i = 0; i < adj.size(); i++){
        //     cout << i << ": ";
        //     for(int j = 0; j < adj[i].size(); j++){
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }  
        queue<int>zeros;
        for(int i = 0; i < numCourses ; i++){
            if(indegree[i] == 0) zeros.push(i);
        }
        // for(int i = 0; i < indegree.size(); i++){
        //     cout << indegree[i] << endl;
        // }
        // 0 0 
        // 1 1
        int processed = 0;
        while(!zeros.empty()){
            int x = zeros.front();
            zeros.pop();
            for(auto y : adj[x]){//reduce the indegree of whatever indices x was pointing to 
                indegree[y]--;
                if(indegree[y] == 0) zeros.push(y);
            }
            processed++;
        }
        return processed == numCourses; 
    }
};
