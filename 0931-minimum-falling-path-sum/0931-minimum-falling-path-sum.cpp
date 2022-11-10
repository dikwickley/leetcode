class Solution {
public:
    
    int rec(vector<vector<int>>&matrix, int i, int j, vector<vector<int>> &dp){
        int n = matrix.size();
        if(i==n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int first=INT_MAX, second, third=INT_MAX;
        
        if(j>0) first = rec(matrix, i+1, j-1, dp);
        second = rec(matrix, i+1, j, dp);
        if(j<n-1) third = rec(matrix, i+1, j+1, dp);
        
        dp[i][j] =  matrix[i][j] + min(first, min(second, third));
        
        return dp[i][j];
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int j=0;j<n;j++){
            ans = min(ans, rec(matrix, 0,j, dp));
        }
        return ans;
    }
};