class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> m;
        
        unordered_map<string, int> same;
        
        for(int i=0;i<n;i++){
            if(words[i][0]!=words[i][1]){
                string s = words[i];
                reverse(s.begin(), s.end());
                if(m.count(s)==0) m.insert({s,1});
                else m[s]+=1;
                
            }else{
                if(same.count(words[i])==0){same.insert({words[i],1});}
                else same[words[i]]+=1;
            }
        }
        
        int matches = 0;
               
        for(int i=0;i<n;i++){
            string s = words[i];
            string r = s;
            reverse(r.begin(), r.end());
            if(m.count(s)!=0) {
                if(m[s]!=0){
                    matches+=min(m[s],m[r]);
                    m[s]=0;
                    m[r]=0;
                }
            }
                
        }
        
        bool flag = false;
        
               
        for(auto i: same){
            if(i.second%2==1) flag = true;
            matches += (i.second/2);
        }
        
        int ans = matches*4;
        
        if(flag) ans+=2;
               
        
        return ans;
        
    }
};