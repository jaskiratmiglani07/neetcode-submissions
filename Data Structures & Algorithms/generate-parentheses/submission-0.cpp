class Solution {
public:
    vector<string>answer;
    int N;
    void solve(int open_count, int closed_count, string current_string){
        if(current_string.size() == 2 * N){
            answer.push_back(current_string);
            return;
        }
        if(open_count < N){
            current_string.push_back('(');
            solve(open_count + 1, closed_count, current_string);
            current_string.pop_back();
        }
        if(closed_count < open_count){
            current_string.push_back(')');
            solve(open_count, closed_count + 1, current_string);
            current_string.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        N = n;
        solve(0, 0, "");
        return answer;
    }
};
