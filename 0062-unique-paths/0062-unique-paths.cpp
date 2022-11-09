class Solution {
public:
    
    int rec(int i, int j, vector<vector<int>>&dp){
        
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 ) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j] = rec(i-1,j,dp) + rec(i,j-1,dp);
        
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return rec(n-1, m-1, dp);
    }
};