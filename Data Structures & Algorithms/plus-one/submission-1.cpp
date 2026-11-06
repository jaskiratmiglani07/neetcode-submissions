class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n - 1] < 9){
            digits[n - 1] = digits[n - 1] + 1;
            return digits;
        }
        int i = n - 1;
        while(i >= 0){
            if(digits[i] < 9){
                digits[i]++;
                break;
            }
            if(digits[i] == 9){
                digits[i] = 0;
            }
            i--;
        }
        if(i == -1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
