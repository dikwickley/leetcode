class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int> s;
        unordered_map<int,int> m;
        for(int i=0;i<k;i++) {
            s.insert(nums[i]);
            if(m.count(nums[i])==0) m.insert({nums[i],1});
            else m[nums[i]] +=1;
        }
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = nums[i]+prefix[i-1];
        }

        int left = 0;
        int right = k-1;
        
        long long sum = 0;
        if(s.size()==k) {
            sum = prefix[k-1];
        }
        
        
        
        for(int i=k;i<n;i++){
            

            s.erase(nums[left]);
            m[nums[left]] -= 1;
            if(m[nums[left]]>0)
                s.insert(nums[left]);
            left++;
            right++;
            
            s.insert(nums[right]);
            if(m.count(nums[right])==0) m.insert({nums[right],1});
            else m[nums[right]] +=1;
            
            if(s.size()==k){
                cout<<right<<" "<<left<<"\n";
                sum = max(sum, (prefix[right]-prefix[left-1]));
            }
        }
        
        return sum;
        
    }
};