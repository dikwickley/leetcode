class Solution {
public:
    double myPow(double x, int N) {
         double res = 1;
        
        long long n = N;
        
        if(x==1) return 1;
        
        if(n<0){
            x = 1.0/x;
            n = -n;
        }
        
        cout<<n;
        
            while(n){
                if(n&1) res *= x;
                x *= x;
                n >>=1;
            }
        
        return res;
    }
};