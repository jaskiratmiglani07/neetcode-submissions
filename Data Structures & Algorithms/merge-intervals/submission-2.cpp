class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while(i < intervals.size()){
            if(i + 1 < intervals.size() && intervals[i + 1][0] <= intervals[i][1]){//overlap exists
                int b = max(intervals[i][1], intervals[i + 1][1]);
                answer.push_back({intervals[i][0], b});
                i++;
                while(i + 1 < intervals.size() && intervals[i + 1][0] <= answer.back().back()){
                    int b = max(answer.back().back(), intervals[i + 1][1]);
                    answer.back() = {answer.back().front(), b};
                    i++;
                }
                i++;
            }
            else{
                answer.push_back(intervals[i]);
                i++;
            }
        }
        return answer;
    }
};
