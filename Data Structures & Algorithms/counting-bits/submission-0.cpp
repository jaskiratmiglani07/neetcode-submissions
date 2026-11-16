class Solution {
public:
    int counter(int x){
        int cnt = 0; 
        while(x){
            x = x & (x - 1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>answer;
        for(int i = 0; i <= n; i++){
            int count = counter(i);
            answer.push_back(count);
        }
        return answer;
    }
};
