class Solution {
public:
    vector<string>word;
    int firstMismatch(int i){
        string st1 = word[i];
        string st2 = word[i+1];
        int idx = 0;
        while(idx < st1.size() && idx < st2.size()){
            if(st1[idx] != st2[idx]) return idx;
            idx++;
        }
        return -1;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        word = words;
        // for(int i = 0; i < n - 1; i++){
        //     if(firstMismatch(i) != -1){
        //         cout << words[i][firstMismatch(i)] << " " << words[i + 1][firstMismatch(i)] << endl;
        //     }
        // }   
        vector<vector<int>>adj(26);
        unordered_map<int, int>indegree;
        for(int i = 0; i < n - 1; i++){
            int idx = firstMismatch(i);
            if(idx != -1){
                adj[words[i][idx] - 'a'].push_back(words[i + 1][idx] - 'a');
                indegree[words[i + 1][idx] - 'a']++;
            }
            if(idx == -1 && words[i].size() > words[i + 1].size()) return "";
        }
        // for(int i = 0; i < adj.size(); i++){
        //     cout << i << ": ";
        //     for(int j = 0; j < adj[i].size(); j++){
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }  
        set<char> st;
        for (const string& w : words) {
            for (char c : w) {
                st.insert(c);
            }
        }
        queue<int> zeros;
        for (char c : st) {
           if (indegree[c - 'a'] == 0) {
                zeros.push(c - 'a');
            }
        }
        string res = "";
        while(!zeros.empty()){
            int x = zeros.front();
            zeros.pop();
            res += static_cast<char>('a' + x);
            for(auto y : adj[x]){
                indegree[y]--;
                if(indegree[y] == 0) zeros.push(y);
            }
        }
        return res.size() == st.size() ? res : ""; 
    }
};
