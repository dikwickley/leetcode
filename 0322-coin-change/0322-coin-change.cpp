class Solution {
public:
    
    int rec(vector<int> &coins, int i, int amount, vector<vector<int>> &dp){
        int n = coins.size();
        
        if(i==n){
            if(amount!=0) return 100000;
            else return 0;
        }
        
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int a = INT_MAX, b = INT_MAX;
        if(coins[i]<= amount) {
            a = 1 + rec(coins, i+1, amount-coins[i], dp);
            b = 1 + rec(coins, i, amount-coins[i], dp);
        }
        int c = 0 + rec(coins, i+1, amount, dp);    
                
        
        return dp[i][amount] = min(a,min(b,c));
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int a =  rec(coins, 0, amount, dp);
        
        if(a>=100000) return -1;
        else return a;
    }
};