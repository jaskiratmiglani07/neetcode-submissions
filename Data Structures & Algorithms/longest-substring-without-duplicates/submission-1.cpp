class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>freq;
        int maxLen = 0;
        int left = 0; 
        int right = 0; 
        while(right < s.size()){
            if(freq.find(s[right]) != freq.end()){
                while(s[left] != s[right]){
                    freq.erase(s[left]);
                    left++;
                }
                left++;
            }
            freq[s[right]]++;
            right++;
            maxLen = max(maxLen, right - left);
        }
        return maxLen; 
    }
};
