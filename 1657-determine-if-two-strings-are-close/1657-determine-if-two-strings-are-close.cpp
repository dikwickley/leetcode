class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);
        
        for(int i=0;i<word1.size();i++){
            map1[word1[i]-'a'] += 1;
        }
        
        for(int i=0;i<word2.size();i++){
            map2[word2[i]-'a'] += 1;
        }
        
        for(int i=0;i<word1.size();i++){
            if(map2[word1[i]-'a']==0) return false;
        }
        
        for(int i=0;i<word2.size();i++){
            if(map1[word2[i]-'a']==0) return false;
        }
        
        
        
        
        vector<int> freq1;
        vector<int> freq2;
        
        for(auto i: map1) if(i!=0) freq1.push_back(i);
        
        for(auto i: map2) if(i!=0) freq2.push_back(i);
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return freq1==freq2;
    }
};