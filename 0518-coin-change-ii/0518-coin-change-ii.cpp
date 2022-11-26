class Solution {
public:
    int rec(vector<int> &coins, int i, int amt, vector<vector<int>> &dp){
        int n = coins.size();
        if(i==0){
            if(amt%coins[0]==0) return 1;
            else return 0;
        }
        
        if(dp[i][amt] != -1) return dp[i][amt];
        
        int b=0;
        if(coins[i]<=amt){
            b = rec(coins, i, amt-coins[i], dp);
        }
        
        int c = rec(coins, i-1, amt, dp);
        return dp[i][amt] = b+c;
       
    }
    // mem
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    //     return rec(coins, n-1, amount, dp);
    // }
    
    //tabulation
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        //base case
        for(int amt=0; amt<=amount; amt++){
            if(amt%coins[0]==0) dp[0][amt] = 1;
            else dp[0][amt] = 0;
        }
        
        // i: n->0 in mem
        // amt: amonut -> 0 in mem
        
        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int b=0;
                if(coins[i]<=amt) b = dp[i][amt-coins[i]];
                int c = dp[i-1][amt];
                dp[i][amt] = b+c;
            }
        }
        
        return dp[n-1][amount];
        
    }
    
    
};