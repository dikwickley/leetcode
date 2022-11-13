class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp = "";
        vector<string> words;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                temp += s[i];
            } else {
                if(temp!=" " && temp!=""){
                    // reverse(temp.begin(), temp.end());
                    words.push_back(temp);
                    temp = "";
                }
            }
        }
        
        if(temp!=" " && temp!="") words.push_back(temp);
        
        reverse(words.begin(), words.end());
        
        // for(int i=0;i<words.size();i++) cout<<words[i]<<",";
        
        string ans = "";
        for(int i=0;i<words.size()-1;i++) ans += words[i] + " ";
        ans += words[words.size()-1];
        return ans;
    }
};