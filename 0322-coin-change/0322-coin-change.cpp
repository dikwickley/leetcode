class Solution {
public:
    int rec(vector<int>&coins, int i, int amt, vector<vector<int>> &dp){
        int n = coins.size();
        if(i==n){
            if(amt==0) return 0;
            else return INT_MAX-1;
        }
        
        if(dp[i][amt]!=-1) return dp[i][amt];
        
        int a = INT_MAX;
        if(amt>=coins[i]){
            a = 1 + rec(coins, i, amt-coins[i], dp);
        }
        int b = 0 + rec(coins, i+1, amt, dp);
        
        return dp[i][amt] = min(a,b);
    }
    //mem
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = rec(coins, 0, amount, dp);
        if(ans==INT_MAX-1) return -1;
        else return ans;
    }
};