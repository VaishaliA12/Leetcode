class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s(days.begin(),days.end());
        vector<int> dp(366,0);
        for(int day=1;day<=365;day++){
            if(s.find(day)==s.end()) dp[day]=dp[day-1];
            else dp[day]=min({dp[day-1]+costs[0],dp[max(0,day-7)]+costs[1],dp[max(0,day-30)]+costs[2]});
        }
        return dp[365];
    }
};