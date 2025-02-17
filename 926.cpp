class Solution {
    public:
        int minFlipsMonoIncr(string s) {
            int ans=0;
            int one=0;
            for(auto it : s){
                if(it=='1') one++;
                else{
                    ans++;
                    ans=min(ans,one);
                }
            }
            return ans;
        }
    };