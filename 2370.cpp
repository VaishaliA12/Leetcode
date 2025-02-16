class Solution {
    public:
        int longestIdealString(string s, int k) {
            vector<int> dp(26,0);
            int ans=1;
            for(char &ch : s){
                int i=ch-'a';
                dp[i]=dp[i]+1;
                for(int j=max(0,i-k);j<=min(25,i+k);j++){
                    if(j!=i) dp[i]=max(dp[i],dp[j]+1);
                }
                ans=max(ans,dp[i]);
            }
            return ans;
        }
    };