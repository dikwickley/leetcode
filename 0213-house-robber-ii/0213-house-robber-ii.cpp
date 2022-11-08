class Solution {
public:
    int f(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        
        int prev2 = 0;
        int prev = nums[0];
        
        for(int i=1;i<n;i++){
            int pick = nums[i] + prev2;         
            int not_pick = prev;
            
            int curr = max(pick, not_pick);
            prev2 = prev;
            prev = curr;
        }
        
        
        return prev;   
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        
        vector<int> a(nums.begin(), nums.end()-1);
        vector<int> b(nums.begin() +1, nums.end());
        
        return max(f(a), f(b));
    }
};