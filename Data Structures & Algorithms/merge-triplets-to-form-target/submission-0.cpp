class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //256 144 575 -> impossible for us to put 4 at second place since it is the smallest number at the second place in the list of triplets.
        //not really possible for us to put a 5 at the second place either if we're aiming for 5 at the first place    
        //123 711-> at the first place the right number was already present, at the other two places we were able to find a triplet that had the required digit as a "max" 
        //256 144 511 -> can i create a 546 with it? how am i supposed to place a 4 at the second place?
        //256 544 511 
        //556 -> i dont think it's possible to create a 546 because even though 4 exists at the second place it's not possible for me to put it there because 
        //111 222 -> can i create 345 -> no.
        vector<vector<int>> validTriplets;
        for(int i = 0; i < triplets.size(); i++){
            bool valid = true;
            for(int j = 0; j < 3; j++){
                if(triplets[i][j] > target[j])
                    valid = false;
            }
            if(valid) validTriplets.push_back(triplets[i]);
        }
        vector<int>maxi(3, 0);
        for(int i = 0; i < validTriplets.size(); i++){
            //what is the max?
            for(int j = 0; j < 3; j++){
                if(validTriplets[i][j] > maxi[j]){
                    maxi[j] = validTriplets[i][j];
                }
            }
        }
        for(int i = 0; i < 3; i++){
            if(maxi[i] != target[i]) return false;
        }
        return true;
    }
};
