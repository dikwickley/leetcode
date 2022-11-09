class Solution {
public:
    int rec(vector<vector<int>>& grid, int i, int j,vector<vector<int>> &dp){

        if(i==0 && j==0) return grid[0][0];
        
        if(i<0 || j<0) return INT_MAX;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left = rec(grid, i-1, j, dp);
        int right = rec(grid, i, j-1, dp);
        
        dp[i][j] =  grid[i][j] + min(left, right);
        
        return dp[i][j];
        
    }
    int mem_minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return rec(grid, n-1, m-1, dp);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
            
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(i==0 && j==0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                int right=INT_MAX, left=INT_MAX;
                
                if(i>0) right = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                
                dp[i][j] = grid[i][j] + min(right,left);
                
            }
        }
        
        return dp[n-1][m-1];
        
    }
};