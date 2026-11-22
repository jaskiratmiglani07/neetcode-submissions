class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int n = s.size();
        //window_len - max_freq <= k
        //right - left + 1 -> window_len
        int freq[26] = {0};
        int window_len = 0;
        int max_freq = 0;
        int answer = 0;
        while(right < n){
            window_len = right - left + 1;
            freq[s[right] - 'A']++;
            max_freq = max(max_freq, freq[s[right] - 'A']);
            if(window_len - max_freq <= k){
                answer = max(answer, window_len);
            }
            else{
                while(window_len - max_freq > k){
                    freq[s[left] - 'A']--;
                    left++;
                    // max_freq = 0;
                    // for(int i = 0; i < 26; i++) max_freq = max(max_freq, freq[i]); 
                    window_len = right - left + 1;
                }
            }
            right++;
        }
        return answer;
    }
};
