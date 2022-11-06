class Solution {
public:
    
    
    
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n==1 && m==1){
            return matrix[0][0];
        }
        
        vector<vector<int>>dp(n,vector<int>(m,0));
                            
        //1st row
        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j];
        }
        //1st col
        for(int j=0;j<n;j++){
            dp[j][0] = matrix[j][0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1)
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
            }
        }
        
        int ans= 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<dp[i][j]<<" ";
                ans += dp[i][j];
            }
            // cout<<"\n";
        }
        
        return ans;
        
    }
};