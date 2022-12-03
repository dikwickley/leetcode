class Solution {
public:
    string scs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
               
        
        for(int i=1;i<=n;i++){
            for(int j=1; j<=m;j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] =  1 + dp[i-1][j-1];
                else{
                    int not_pick_1 = dp[i-1][j];
                    int not_pick_2 = dp[i][j-1];    
                    dp[i][j] = max(not_pick_1, not_pick_2);
                }
            }
        }
        

       
        string scs_string = "";
        int i = n;
        int j = m;
        
        
        
        while(i>0 && j>0){
            
            if(text1[i-1]==text2[j-1]){
                scs_string += text1[i-1];
                i--;
                j--;
                
            } else {
                if(dp[i-1][j]>dp[i][j-1]){
                    scs_string += text1[i-1];
                    i--;
                } else {
                    scs_string += text2[j-1];
                    j--;
                }        
            }
            
        }
        
        // cout<<i<<" "<<j<<endl;
        
        while(i>0) {scs_string += text1[i-1];i--;}
        
        while(j>0) {scs_string += text2[j-1];j--;}
        
        
        
        reverse(scs_string.begin(), scs_string.end());
        
        return scs_string;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        
        return scs(str1, str2);
        
        
    }
};