class Solution {
public:
    int rec(vector<vector<int>> &jobs, vector<int>&startTime, int i, vector<int> &dp){
        int n = jobs.size();
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        //get index for next job;
        int currentEndTime = jobs[i][1];
        int currentProfit = jobs[i][2];
        int nextJobIndex = lower_bound(startTime.begin(), startTime.end(), currentEndTime) - startTime.begin();
        
        int take = currentProfit + rec(jobs, startTime, nextJobIndex, dp);
        int not_take = 0 + rec(jobs, startTime, i+1, dp);
        
        return dp[i] = max(take, not_take);
        
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        
        vector<int> dp(n+1, -1);
        
        return rec(jobs, startTime, 0, dp);
    }
};