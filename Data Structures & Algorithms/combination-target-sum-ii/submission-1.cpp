class Solution {
public:
    vector<vector<int>> answer;
    void solve(int i, int target, vector<int>& candidates, vector<int>& equalsSum){
        //pick or not pick
//every push_back must be immediately followed by a recursive call, which is then immediately followed by a pop_back
//Once you decide to reject a specific value, you must reject all identical copies of it for the rest of that specific path so you don't generate the same combination twice.
        if(target == 0){
            answer.push_back(equalsSum);
            return;
        }
        if(i >= candidates.size()){
            return;
        }
        if(target - candidates[i] >= 0){
            equalsSum.push_back(candidates[i]);
            solve(i + 1, target - candidates[i], candidates, equalsSum);//ensuring that an element has only been used once at max 
            equalsSum.pop_back();
        }
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]){
            i++;
        }
        solve(i + 1, target, candidates, equalsSum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>equalsSum;
        solve(0, target, candidates, equalsSum);
        return answer;
    }
};
