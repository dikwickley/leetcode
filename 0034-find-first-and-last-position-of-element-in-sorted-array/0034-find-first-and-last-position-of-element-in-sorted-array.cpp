class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n==0) return {-1, -1};
        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        
        
        if(first==n || nums[first]!=target) first = -1;
        
        if(first==-1) return {-1, -1};
        
        int second = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        return {first,second-1};
    }
};