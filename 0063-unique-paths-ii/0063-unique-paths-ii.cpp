class Solution {
public:
//     int rec(vector<vector<int>>& o, int i, int j, vector<vector<int>>&dp){
        
        
        
//         if(i==0 && j==0) return 1;
//         if(i<0 || j<0 ) return 0;
        
//         if(o[i][j]==1) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         dp[i][j] = rec(o,i-1,j,dp) + rec(o,i,j-1,dp);
        
//         return dp[i][j];
//     }
    
//     int mem_uniquePathsWithObstacles(vector<vector<int>>& o) {
        
//         int n = o.size();
//         int m = o[0].size();
        
//         if(o[n-1][m-1]==1) return 0;
//         if(o[0][0]==1) return 0;
        
//         vector<vector<int>> dp(n, vector<int>(m,-1));
//         return rec(o, n-1, m-1, dp);
//     }
    
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        
        if(o[n-1][m-1]==1) return 0;
        if(o[0][0]==1) return 0;
        
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0 && j==0) {
                    dp[i][j] = 1;
                    continue;
                }
                
                if(o[i][j]==1){ 
                    dp[i][j] = 0;
                    continue;
                }
                
                int left = 0, right = 0;
                
                if(i>0) left = dp[i-1][j];
                if(j>0) right = dp[i][j-1];
                
                dp[i][j] = left+right;
            }
        }
        
        return dp[n-1][m-1];
    }
};