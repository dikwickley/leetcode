class Solution {
public:
    
    int rec(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>&dp){
        
        int n =triangle.size();
        
        if(i==n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left = rec(triangle, i+1, j, dp);
        int right = rec(triangle, i+1, j+1, dp);
        
        dp[i][j] = triangle[i][j] + min(left, right);
        
        return dp[i][j];
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
            
        return rec(triangle, 0,0, dp);
        
    }
};