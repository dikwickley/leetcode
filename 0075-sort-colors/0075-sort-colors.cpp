class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3,0);
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            colors[nums[i]] ++;
        }
        int j = 0;
        
        while(colors[0]--) nums[j++] = 0;
        while(colors[1]--) nums[j++] = 1;
        while(colors[2]--) nums[j++] = 2;
    }
};