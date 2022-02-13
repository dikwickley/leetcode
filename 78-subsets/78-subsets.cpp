class Solution {
public:
    
    string dec2bin(int n, int prec){
        string r;
        
        for(int i=0;i<prec;i++){
            r+= "0";
        }
        for(int i=0;i<prec;i++){
            r[i] = n%2==0?'0':'1';
            n/=2;
        }
        
        reverse(r.begin(), r.end());
        
        return r;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = pow(2,nums.size());
        
        for(int i=0;i<n;i++){
            
            // cout<<dec2bin(i, nums.size())<<endl;
            string bin = dec2bin(i, nums.size());
            vector<int>temp;
            
            for(int i=0;i<bin.length();i++){
                if(bin[i]=='1'){
                    cout<<nums[i]<<" ";
                    temp.push_back(nums[i]);
                }
            }
            cout<<endl;
            res.push_back(temp);
        }

        
    
        return res;
        
    }
};