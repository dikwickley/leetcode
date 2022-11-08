class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        
        if(n==1) return s;
        
        stack<char> st;
        
        st.push(s[0]);
        
        for(int i=1;i<n;i++){
            
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            
            char top = st.top();
            char out = s[i];
            
            if(tolower(top) == tolower(out)){
                if((islower(top)&&isupper(out))||(islower(out)&&isupper(top))){
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
            
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};