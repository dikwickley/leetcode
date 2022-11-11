class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        for(int i=1;i<n;i++,k++){
            int next_greater = upper_bound(nums.begin()+i, nums.end(), nums[i-1]) - nums.begin();
            if(next_greater==n) break;
            // cout<<nums[i-1]<<" "<< nums[next_greater]<<"\n";
            
            
            nums[i] = nums[next_greater];
        }
        return k;
    }
};