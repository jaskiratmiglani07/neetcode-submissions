class Solution {
public:
//A car cannot pass the car in front of it.
// Starting from the car closest to the target, that car dictates the arrival time for its fleet.
// Any car behind it taking less or equal time will catch up and join its fleet.
// Any car behind it taking more time will never catch up, forming a new fleet and setting a new time to beat.
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }    
        sort(cars.begin(), cars.end());   
        int n = position.size(); 
        vector<double>time(n);
        for(int i = 0; i < cars.size(); i++){
            time[i] = (double)(target - cars[i].first)/cars[i].second;
        }     
        stack<double>st;
        st.push(time[n-1]);
        for(int i = n - 2; i >= 0; i--){
            if(time[i] > st.top()){
                st.push(time[i]);
            }
        }
        return st.size();
    }
};
