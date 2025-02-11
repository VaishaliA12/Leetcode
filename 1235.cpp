class Solution {
    public:
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            int n=profit.size();
            vector<tuple<int,int,int>> jobs(n);
            for(int i=0;i<n;i++){
                jobs[i]={endTime[i],startTime[i],profit[i]};
            }
            sort(jobs.begin(),jobs.end());
            vector<int> dp(n+1);
            for(int i=0;i<n;i++){
                auto [end,start,pro]=jobs[i];
                int id=upper_bound(jobs.begin(),jobs.begin()+i,start,[&](int t,const auto &j)->bool{
                    return t< get<0>(j);
                })-jobs.begin();
                dp[i+1]=max(dp[i],dp[id]+pro);
            }
            return dp[n];
        }
    };