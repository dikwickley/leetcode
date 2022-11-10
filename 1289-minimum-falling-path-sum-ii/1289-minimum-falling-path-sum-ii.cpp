class Solution {
public:
    int rec(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&dp){
        int n = grid.size();
        
        if(i==n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k = 0; k < grid[0].size(); k++){
            if(j == k) continue;
            ans = min(ans, rec(grid,i + 1, k, dp) + grid[i][j]);
        }
        dp[i][j]  =  ans;
        return ans;
        
        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        
        int n= grid.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        if(n==1){
            return grid[0][0];
        }
        
        int ans = INT_MAX;
        for(int j=0;j<n;j++){
            ans = min(ans, rec(grid, 0, j, dp));
        }
        
        return ans;
    }
    

};