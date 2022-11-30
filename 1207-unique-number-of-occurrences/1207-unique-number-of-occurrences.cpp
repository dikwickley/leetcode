class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        vector<int> m(2500, 0);
        
        for(int i=0;i<n;i++){
            m[1001+arr[i]] += 1;
        }
        vector<int> m2(2500, 0);
        
        
        for(int i=0;i<m.size();i++){
            m2[m[i]] += 1;
        }
        
        for(int i=1;i<m2.size();i++){
            if(m2[i]>1) return false;
        }
        
        return true;
    }
};