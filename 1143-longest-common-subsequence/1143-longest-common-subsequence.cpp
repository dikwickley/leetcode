class Solution {
public:
    int rec(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        if(text1[i] == text2[j])
            return dp[i][j] =  1 + rec(text1, text2, i-1, j-1, dp);
        else{
            int not_pick_1 = rec(text1, text2, i-1, j, dp);
            int not_pick_2 = rec(text1, text2, i, j-1, dp);    
            return dp[i][j] = max(not_pick_1, not_pick_2);
        }
               
        
    }
    // memoization
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
        
//         vector<vector<int>> dp(n, vector<int>(m, -1));
        
//         return rec(text1, text2, n-1, m-1, dp);
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
               
        
        for(int i=1;i<=n;i++){
            for(int j=1; j<=m;j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] =  1 + dp[i-1][j-1];
                else{
                    int not_pick_1 = dp[i-1][j];
                    int not_pick_2 = dp[i][j-1];    
                    dp[i][j] = max(not_pick_1, not_pick_2);
                }
            }
        }
        
        
        
        return dp[n][m];
    }
};