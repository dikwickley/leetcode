class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,bool> nmap;
        
        for(int i=0;i<nums.size();i++){
            if(nmap.find(nums[i]) != nmap.end()){
                //found;
                nmap[nums[i]] = true;
            } else {
                nmap.insert({nums[i],false});
            }
        }
        
        for(auto it : nmap){
            cout<<it.first<<"->"<<it.second<<endl;
            if(!it.second) return it.first;
        }
        return 0;
    }
};