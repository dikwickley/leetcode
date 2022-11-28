#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        set<int> winners;
        set<int> losers;
        map<int,int> lost_count;
        
        for(auto i: matches){
            winners.insert(i[0]);
            losers.insert(i[1]);
            if(lost_count.count(i[1])==0) lost_count[i[1]] = 1;
            else lost_count[i[1]] += 1;
        }
        
        vector<int> result;
        vector<int> result2;
        
        for(auto i: lost_count){
            if(i.second==1) result2.push_back(i.first);
        }
  
        set_difference(begin(winners), end(winners),  
                 begin(losers), end(losers),  
                 inserter(result, end(result))); 
        
        sort(result.begin(), result.end());
        sort(result2.begin(), result2.end());
        
        return {result,result2};
    }
};