class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<int> curr(2,0);
            vector<int> front1(2,0);
            vector<int> front2(2,0);
            for(int i=n-1;i>=0;i--){
                for(int buy=0;buy<=1;buy++){
                    int profit;
                    if(buy==0) profit=max(0+front1[0],-prices[i]+front1[1]);
                    if(buy==1) profit=max(0+front1[1],prices[i]+front2[0]);
                    curr[buy]=profit;
                }
                front2=front1;
                front1=curr;
            }
            return curr[0];
        }
    };