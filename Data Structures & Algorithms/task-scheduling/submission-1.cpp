class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>freq;
        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i]]++;
        }
        priority_queue<int>maxhp;//only contains tasks that are ready to run
        for(auto x : freq){
            maxhp.push(x.second);
        }
        int count = 0;
        queue<pair<int, int>>avl;//tasks cooling down {rem_freq, avl time}
        while(!maxhp.empty() || !avl.empty()){//if either of the conditions is still true, the loop needs to keep running
            if(!maxhp.empty()){
                int x = maxhp.top();
                maxhp.pop();
                x--;
                if(x > 0)
                avl.push({x, count + n}); 
            }
            if(!avl.empty() && avl.front().second == count){//ready to run now
                maxhp.push(avl.front().first);
                avl.pop();
            }
            count++;
        }
        return count;
    }
};
