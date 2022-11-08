class Solution {
public:
    int rec(vector<int> &nums, int i, vector<int> &dp){
        
        // cout<<i<<" ";
                
        if(i>=nums.size()-1) return 0;
        
        if(dp[i]!=-1) return dp[i];
    
        int k = nums[i];
        
        if(k==0) return INT_MAX-1;
        
        int ans = INT_MAX -1;
        
        for(int j=1; j<=k; j++){
            
            if(i+j>nums.size()-1) break;
            
            ans = min(ans, 1 + rec(nums, i+j, dp));
        }
        
        dp[i] = ans;
        return ans;
        
    }
    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);
        return rec(nums, 0, dp);
    }
    
    
};