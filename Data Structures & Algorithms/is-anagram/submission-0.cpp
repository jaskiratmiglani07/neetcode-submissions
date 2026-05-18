class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int>mp1;
        unordered_map<int, int>mp2;
        int n = s.size();
        int m = t.size();
        if(n != m) return false;
        for(int i = 0; i < n; i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        if(mp1.size() != mp2.size()) return false;
        for(auto it : mp1){
            if(mp1[it.first] != mp2[it.first])
                return false;
        }
        return true;
    }
};
