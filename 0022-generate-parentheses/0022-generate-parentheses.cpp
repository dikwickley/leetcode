class Solution {
public:
   
    
    void rec(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ rec(v, str+")", n, m-1); }
        if(n > 0){ rec(v, str+"(", n-1, m+1); }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        rec(res, "", n, 0);
        return res;
    }
   
};