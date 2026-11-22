class Solution {
public:
    unordered_map<char, int>freq;
    set<pair<int, char>>order;
    void add(char x){
        if(freq[x] > 0){
            order.erase({freq[x], x});
        }
        freq[x]++;
        order.insert({freq[x], x});
    }
    void remove(char x){
        order.erase({freq[x], x});
        freq[x]--;
        if(freq[x] > 0) order.insert({freq[x], x});
        else freq.erase(x);
    }
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int n = s.size();
        //window_len - max_freq <= k
        //right - left + 1 -> window_len
        int window_len = 0;
        int max_freq = 0;
        int answer = 0;
        while(right < n){
            window_len = right - left + 1;
            add(s[right]);
            max_freq = (*order.rbegin()).first;
            if(window_len - max_freq <= k){
                answer = max(answer, window_len);
            }
            else{
                while(window_len - max_freq > k){
                    remove(s[left]);
                    left++;
                    max_freq = (*order.rbegin()).first;
                    window_len = right - left + 1;
                }
            }
            right++;
        }
        return answer;
    }
};
