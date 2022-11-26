class Solution {
public:
    int rec(vector<int> &coins, int i, int amount, vector<vector<int>> &dp){
        int n = coins.size();
        if(i==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int b=0;
        if(coins[i]<=amount){
            b = rec(coins, i, amount-coins[i], dp);
        }
        
        int c = rec(coins, i-1, amount, dp);
        return dp[i][amount] = b+c;
       
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return rec(coins, n-1, amount, dp);
    }
};