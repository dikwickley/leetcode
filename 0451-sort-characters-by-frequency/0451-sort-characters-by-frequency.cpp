class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])==0) m[s[i]] = 1;
            else m[s[i]] += 1;
        }
        
        vector<pair<int,char>> freq;
        
        for(auto i: m){
            freq.push_back({i.second, i.first});
        }
        
        sort(freq.begin(), freq.end());
        
        
        string ans = "";
        for(auto f: freq){
            for(int j=0;j<f.first;j++){
                ans+=f.second;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};