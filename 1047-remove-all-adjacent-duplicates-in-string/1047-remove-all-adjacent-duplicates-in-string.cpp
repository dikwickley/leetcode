class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        
        stack<char> stk;
        
        for(int i=0;i<n;i++){
            if(!stk.empty()){
                if(stk.top()!=s[i]){
                    stk.push(s[i]);
                } else 
                    stk.pop();
            }else {
                stk.push(s[i]);
            }
        }
        s = "";
        while(!stk.empty()){
            s += stk.top();
            stk.pop();
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};