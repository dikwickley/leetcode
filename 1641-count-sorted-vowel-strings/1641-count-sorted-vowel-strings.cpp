class Solution {
public:
    
    int arr[5][50] = {0};
    
    int rec(int n, char c){
        if(n==2){
            if(c=='a') return 5;
            if(c=='e') return 4;
            if(c=='i') return 3;
            if(c=='o') return 2;
            if(c=='u') return 1;
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
        
        return ans;
        
        
    }
    
    int countVowelStrings(int n) {
    
        if(n==1) return 5;
        
        return rec(n, 'a')  + 
                rec(n, 'e') +
                rec(n, 'i') +
                rec(n, 'o') +
                rec(n, 'u');
    }
};