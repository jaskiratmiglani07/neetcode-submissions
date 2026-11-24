class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        dq.push_back(0);
        for(int i = 1; i < k; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int>answer;
        int left = 0;
        int right = k - 1;
        int n = nums.size();
        answer.push_back(nums[dq.front()]);
        while(right < n - 1){
            right++;
            while(!dq.empty() && nums[dq.back()] < nums[right]) dq.pop_back();
            dq.push_back(right);
            left++;
            if(dq.front() < left) dq.pop_front();
            answer.push_back(nums[dq.front()]);
        }
        return answer;
    }
};
