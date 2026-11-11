class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> answer;
    void solve(int start_index, vector<string>& current_partition, string& s){
        if(start_index == s.size()){
            answer.push_back(current_partition);
            return;
        }
        for(int i = start_index;  i < s.size(); i++){
            if(isPalindrome(s, start_index, i)){
                current_partition.push_back(s.substr(start_index, i - start_index + 1));//lock
                solve(i + 1, current_partition, s);//explore
                current_partition.pop_back();//unlock
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>current_partition;
        solve(0, current_partition, s);
        return answer;
    }
};
