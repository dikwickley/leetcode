class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        if(n==0) return 0;
        if(n==1) return 1;
        
        unordered_map<char, int> mp;
        
        int i=0;
        int j=0;
        
        int ans = INT_MIN;
        
        for(i=0;i<n;i++){
            
            if(mp.count(s[i])!=0){
                j = max(j, mp[s[i]]+1);
                mp[s[i]] = i;
            }           
            
            ans = max(ans, i-j+1);
            
            if(mp.count(s[i])==0){
                mp[s[i]] = i;
            }
            
            
            
        }
        
        return ans;
    }
};