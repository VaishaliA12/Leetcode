class Solution {
    public:
        const int mod=1e9+7;
        int solve(int cur_ind,int count_a,int count_l,int n,vector<vector<vector<int>>> &dp){
            if(cur_ind==n) return 1;
            if(dp[cur_ind][count_a][count_l]!=-1) return dp[cur_ind][count_a][count_l];
            int a_next=(count_a==0)?solve(cur_ind+1,count_a+1,0,n,dp):0;
            int l_next=(count_l==2)?0:solve(cur_ind+1,count_a,count_l+1,n,dp);
            int p_next=solve(cur_ind+1,count_a,0,n,dp);
            int ans=((a_next+l_next)%mod+p_next)%mod;
            return dp[cur_ind][count_a][count_l]=ans;
        }
        int checkRecord(int n) {
            vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
            return solve(0,0,0,n,dp);
        }
    };