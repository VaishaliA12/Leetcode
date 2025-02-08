class Solution {
    public:
        int bestTeamScore(vector<int>& scores, vector<int>& ages) {
            vector<pair<int,int>> vec;
            int n=scores.size();
            for(int i=0;i<n;i++) vec.push_back({ages[i],scores[i]});
            sort(vec.begin(),vec.end());
            vector<int> dp(n,0);
            dp[0]=vec[0].second;
            for(int i=1;i<n;i++){
                int maxi=0;
                for(int j=0;j<i;j++){
                    if(vec[j].second<=vec[i].second) maxi=max(maxi,dp[j]);
                }
                dp[i]=maxi+vec[i].second;
            }
            return *max_element(dp.begin(),dp.end());
        }
    };