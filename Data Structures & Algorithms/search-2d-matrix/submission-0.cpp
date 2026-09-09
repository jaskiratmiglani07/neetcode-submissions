class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>mat;
        for(int i = 0; i < m; i++){
            mat.insert(mat.end(), matrix[i].begin(), matrix[i].end());            
        }  
        int lo = 0;
        int hi = mat.size() - 1;  
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(mat[mid] == target){
                return true;
            }
            if(mat[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};
