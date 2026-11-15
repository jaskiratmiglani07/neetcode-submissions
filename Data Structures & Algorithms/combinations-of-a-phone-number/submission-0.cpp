#include<string>
class Solution {
public:
    vector<string>answer;
//base case
    void solve(int index, string current_combination, unordered_map<int, string>& letters, string& digits){
        if(index == digits.size()){
            if(!current_combination.empty())
            answer.push_back(current_combination);
            return;
        }
        for(int i = 0; i < letters[digits[index] - '0'].size(); i++){
            string s = letters[digits[index] - '0'];
            current_combination.push_back(s[i]);
            solve(index + 1, current_combination, letters, digits);
            current_combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> letters{
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"},
        };
        solve(0, "", letters, digits);
        return answer;
    }
};
