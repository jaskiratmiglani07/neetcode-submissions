class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int right = s.size() - 1;
        int left = 0;
        while(left <= right){
            if(!isalnum(s[left])) left++;
            if(!isalnum(s[right])) right--;
            if(s[left] != s[right] && isalnum(s[left]) && isalnum(s[right])){
                return false;
            }
            if(s[left] == s[right] && isalnum(s[left]) && isalnum(s[right])){
                left++;
                right--;
            }
        }
        return true;
    }
};
