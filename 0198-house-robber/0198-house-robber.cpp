class Solution {
public:
    int rec(vector<int> nums, int i, vector<int> &dp){
        if(i<0) return 0;

        if(dp[i]!=-1) return dp[i];

        int pick = nums[i] + rec(nums, i-2, dp);
        int notpick = rec(nums, i-1, dp);

        dp[i] =  max(pick, notpick);
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        
        if(n==1) return nums[0];
        
        if(n==2) return max(nums[0], nums[1]);
        
        dp[0] = nums[0];
        
        
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            
            int not_pick = dp[i-1];
            
            dp[i] = max(pick, not_pick);
        }
        
        
        return dp[n-1];   
    }
};