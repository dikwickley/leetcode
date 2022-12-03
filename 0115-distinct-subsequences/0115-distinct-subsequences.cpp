class Solution {
public:
    
    int rec(string s, string t, int i, int j, vector<vector<int>>&dp){
        
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            int pick = rec(s, t,i-1, j-1, dp);
            int not_pick = rec(s, t, i-1, j, dp);
            return dp[i][j] = pick + not_pick;
        } else{
            return dp[i][j] = rec(s, t, i-1, j, dp);
        }
    }
    
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
        
//         vector<vector<int>> dp(n, vector<int>(m,-1));
        
//         return rec(s, t, n-1, m-1, dp);
//     }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1,0));
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
        
    }
};