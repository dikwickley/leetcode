class Solution {
public:
    bool halvesAreAlike(string s) {
        int firstHalf = 0;
        int secondHalf = 0;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            s[i] = tolower(s[i]);
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
                if(i<n/2) firstHalf ++;
                else secondHalf ++;
            }
        }
        
        return firstHalf==secondHalf;
    }
};