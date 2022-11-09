class Solution {
public:
    
    int rec(int i, int j, vector<vector<int>>&dp){
        
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 ) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j] = rec(i-1,j,dp) + rec(i,j-1,dp);
        
        return dp[i][j];
    }
    int mem_uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return rec(n-1, m-1, dp);
    }
    
    //tabulation
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        dp[0][0] = 1; 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0 && j==0) continue;
                
                int r=0, l=0;
                
                if(i>0) r = dp[i-1][j]; 
                if(j>0) l = dp[i][j-1];
                
                dp[i][j] = r + l;
                
            }
        }
        
        return dp[n-1][m-1]; 
        
    }
};