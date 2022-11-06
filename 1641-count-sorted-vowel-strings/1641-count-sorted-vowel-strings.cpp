class Solution {
public:
    
    int arr[5][51] = {0};
    
    Solution(){
        int n= 50;
        int ans = rec(n, 'a')  + 
                rec(n, 'e') +
                rec(n, 'i') +
                rec(n, 'o') +
                rec(n, 'u');
    }
    
    
    int rec(int n, char c){
        if(n==2){
            if(c=='a') return 5;
            if(c=='e') return 4;
            if(c=='i') return 3;
            if(c=='o') return 2;
            if(c=='u') return 1;
        }
        
        
        int i = 0;
        switch(c){
            case 'a' : i=0; break;
            case 'e' : i=1; break;
            case 'i' : i=2; break;
            case 'o' : i=3; break;
            case 'u' : i=4; break;    
        }
        
        if(arr[i][n]!=0){
            // cout<<i<<" "<<n<<"\n";
            return arr[i][n];
        }
        
        int ans = 0;
        
        if(c=='a')
                ans = rec(n-1, 'a')  + 
                rec(n-1, 'e') +
                rec(n-1, 'i') +
                rec(n-1, 'o') +
                rec(n-1, 'u');
        
        if(c=='e')
                ans = rec(n-1, 'e') +
                rec(n-1, 'i') +
                rec(n-1, 'o') +
                rec(n-1, 'u');
        
        if(c=='i')
                ans = rec(n-1, 'i') +
                rec(n-1, 'o') +
                rec(n-1, 'u');
        
        if(c=='o')
                ans = rec(n-1, 'o') +
                rec(n-1, 'u');
        
        if(c=='u')
                ans = rec(n-1, 'u');
        
        
        arr[i][n] = ans;
        
        return ans;
        
        
    }
    
    int countVowelStrings(int n) {
    
        if(n==1) return 5;
        if(n==2) return 15;
        
        return arr[0][n]+arr[1][n]+arr[2][n]+arr[3][n]+arr[4][n];
        
        // return rec(n, 'a')  + 
        //         rec(n, 'e') +
        //         rec(n, 'i') +
        //         rec(n, 'o') +
        //         rec(n, 'u');
    }
};