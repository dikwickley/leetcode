class Solution {
public:
    
//     int rec(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>&dp){
        
//         int n =triangle.size();
        
//         if(i==n) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int left = rec(triangle, i+1, j, dp);
//         int right = rec(triangle, i+1, j+1, dp);
        
//         dp[i][j] = triangle[i][j] + min(left, right);
        
//         return dp[i][j];
        
//     }
//     //memoization
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>>dp(n, vector<int>(n,-1));
            
//         return rec(triangle, 0,0, dp);
        
//     }
    
    // void print(vector<vector<int>>&dp){
    //     cout<<"dp\n";
    //     int n = dp.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<i+1;j++){
    //             cout<<dp[i][j]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    // }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        
        dp[0][0] = triangle[0][0];
        
        // print(dp);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i+1;j++){
                
                
                
                int right  = INT_MAX, left=INT_MAX;
                
                if(j<i)
                    left = dp[i-1][j];
                
                if(j>0)
                    right = dp[i-1][j-1];
                
                // cout<<left<<" "<<right<<"\n";
                
                dp[i][j] = triangle[i][j] + min(left, right);
                
                // print(dp);
                
            }
            
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++){
            ans = min(ans, dp[n-1][i]);
        }
        
        return ans;
    }
        
};