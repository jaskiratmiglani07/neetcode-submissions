class Solution {
public:
    int maxLen = 0;
    bool solve(int i, int j, string &s){
        if(i >= j) return true;
        if(s[i] == s[j]){
            return solve(i + 1, j - 1, s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string result;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s)){
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return result;
    }
};
