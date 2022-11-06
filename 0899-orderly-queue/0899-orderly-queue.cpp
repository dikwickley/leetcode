class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        string a = s;
        
        if(k==1){
            string temp = s;
            for(int i=1;i<n;i++){
                string a = s.substr(0,i);
                string b = s.substr(i,n-i);
                
                string res = b+a;
                
                if(!lexicographical_compare(temp.begin(), temp.end(), res.begin(), res.end())){
                    temp = res;
                }
            }
            return temp;
        }
        
        sort(a.begin(), a.end());
        return a;

    }
};