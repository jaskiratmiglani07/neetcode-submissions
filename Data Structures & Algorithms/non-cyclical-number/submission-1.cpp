class Solution {
public:
    int sumOfSquaredDigits(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        vector<int>seen(1000, 0);
        bool valid = true;
        while(valid){
            int x = sumOfSquaredDigits(n);
            if(x == 1) break;
            if(seen[x]){
                valid = false;
                break;
            }
            n = x;
            seen[n] = 1;
        }     
        if(valid) return true;
        else return false;     
    }
};
