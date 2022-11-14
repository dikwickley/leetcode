class Solution {
public:
    
    bool rec(vector<int>&nums, int i, int sumA, int total, vector<vector<int>>&dp){
        int n = nums.size();
        if(i==n){
            return sumA*2==total;
        };
        
        if(dp[i][sumA]!=-1) return dp[i][sumA];

        dp[i][sumA] =  rec(nums,i+1, sumA+nums[i], total, dp) || rec(nums,i+1, sumA, total, dp);
        return dp[i][sumA];
    }
    //memoization
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        vector<vector<int>> dp(n, vector<int>(100*201,-1));
        for(int i=0;i<n;i++) total+=nums[i];
        return rec(nums, 0, 0, total,dp);
    }
//         bool canPartition(vector<int>& nums) {
            
//         }
    
};