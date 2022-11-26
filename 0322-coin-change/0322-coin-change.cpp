class Solution {
public:
    int rec(vector<int>&coins, int i, int amt, vector<vector<int>> &dp){
        int n = coins.size();
        if(i==0){
            if(amt==0) return 0;
            
            if(amt%coins[0]==0) return amt/coins[0];
            
            return INT_MAX-1;
        }
        
        if(dp[i][amt]!=-1) return dp[i][amt];
        
        int a = INT_MAX;
        if(amt>=coins[i]){
            a = 1 + rec(coins, i, amt-coins[i], dp);
        }
        int b = 0 + rec(coins, i-1, amt, dp);
        
        return dp[i][amt] = min(a,b);
    }
    //mem
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    //     int ans = rec(coins, n-1, amount, dp);
    //     if(ans==INT_MAX-1) return -1;
    //     else return ans;
    // }
    
    int coinChange(vector<int>&coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        dp[0][0] = 0;
        
        //base case;
        for(int amt=1;amt<=amount;amt++){
            if(amt%coins[0]==0) dp[0][amt] = amt/coins[0];
            else dp[0][amt] = INT_MAX-1;
        }
        
        // i: n->0 in mem
        // amt: amount -> 0 in mem
        for(int i=1;i<n;i++){
            for(int amt=0; amt<=amount; amt++){
                
                int a = INT_MAX;
                if(amt>=coins[i]){
                    a = 1 + dp[i][amt-coins[i]];
                }
                int b = 0 + dp[i-1][amt];

                dp[i][amt] = min(a,b);
            }
        }

        int ans =  dp[n-1][amount];
        if(ans==INT_MAX-1) return -1;
        else return ans;
    }
};