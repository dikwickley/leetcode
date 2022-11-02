class Solution {
public:
    int reverse(int x) {
        long long y=0;
        
        while(x){
            y = y*10 + x%10;
            x /= 10;
        }
        
        if(y > ((long long)1<<31) - 1) return 0;
        if(y < -1*((long long)1<<31) ) return 0;
        
        return y;
        
    }
};