class Solution {
public:
    vector<vector<int>> answer;
    void solve(vector<int> &nums, vector<bool> &visited, vector<int>& curr_vec){
        if(nums.size() == curr_vec.size()){
            answer.push_back(curr_vec);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                curr_vec.push_back(nums[i]);
                solve(nums, visited, curr_vec);
                curr_vec.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //when nums.size() == current_vector.size()->stop
        //i need to somehow mark a used number and then unmark it once it has been explored 
        int n = nums.size();
        vector<bool>visited(n, 0);
        vector<int>curr_vec;
        solve(nums, visited, curr_vec);
        return answer;
    }
};
