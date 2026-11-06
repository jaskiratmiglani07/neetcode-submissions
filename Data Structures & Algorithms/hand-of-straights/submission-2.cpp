class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> freq;
        int n = hand.size();
        if(n % groupSize != 0) return false;
        for(int i = 0; i < n; i++)
            freq[hand[i]]++;   
        for(auto x : freq){
            if(freq[x.first] == 0) continue;
            int count = freq[x.first];
            int key = x.first;
            for(int i = key; i < key + groupSize; i++){
                if(freq[i] < count) return false;
                freq[i] -= count;
            }
        }  
        return true;
    }
};
