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
        
        
        
        sort(map1.begin(), map1.end());
        sort(map2.begin(), map2.end());
        
        return map1==map2;
    }
};