class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        st.push(0);
        int n = temperatures.size();
        vector<int>result(n, 0);
        for(int i = 1; i < temperatures.size(); i++){
            if(!st.empty() && temperatures[st.top()] < temperatures[i]){
                while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
            else{
                st.push(i);
            }
        }
        return result;
    }
};
