class Solution {
public:
    vector<int>pile;
    int H;
    bool possible(int k){
        long long time = 0;
        for(int i = 0; i < pile.size(); i++){
            time += ceil((double)pile[i]/k);            
        }
        return time <= H;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        pile = piles;
        H = h;
        int lo = 1;
        int hi = 1e9;
        //fffffftttttt
        int ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(possible(mid)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }  
        return ans;      
    }
};
