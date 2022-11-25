class Solution {
public:
    int rec(vector<int> &nums, int target, int i, int sum, vector<vector<int>> &dp, int total){
        int n = nums.size();
        if(i==n){
            return target==sum;
        }
        
        if(dp[i][sum+total]!=-1) return dp[i][sum+total];
        
        int left = rec(nums, target, i+1, sum+nums[i], dp, total);
        int right = rec(nums, target, i+1, sum-nums[i], dp, total);
        
        return dp[i][sum+total] = left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++) total += nums[i];
        vector<vector<int>> dp(n+1, vector<int>(total*2+10, -1));
        return rec(nums, target, 0, 0, dp, total);
    }
};