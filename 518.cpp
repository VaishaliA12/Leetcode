class Solution {
    public:
        int change(int amount, vector<int>& coins) {
           int n=coins.size();
           vector<vector<unsigned long long int>> dp(n,vector<unsigned long long int> (amount+1,0));
           for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
           } 
           for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                unsigned long long int not_taken=dp[i-1][target];
                unsigned long long int taken=0;
                if(coins[i]<=target) taken=dp[i][target-coins[i]];
                dp[i][target]=not_taken+taken;
            }
           }
           return dp[n-1][amount];
        }
    };