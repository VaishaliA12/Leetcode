class Solution {
public:
    unordered_map<string,int> dp;
    int solve(string target,vector<unordered_map<char,int>> &mp){
        if(dp.find(target)!=dp.end()) return dp[target];
        if(target.size()==0) return 0;
        int ans=1e9;
        unordered_map<char,int> mp1;
        for(auto it : target) mp1[it]++;
        for(int i=0;i<mp.size();i++){
            if(mp[i][target[0]]==0) continue;
            string s="";
            for(auto it : mp1) s+=string(max(0,it.second-mp[i][it.first]),it.first);
            int temp=solve(s,mp);
            if(temp!=-1) ans=min(ans,1+temp);
        }
        if(ans==1e9) return dp[target]=-1;
        return dp[target]=ans;
    }
    int minStickers(vector<string>& stickers, string target) {
        int n=stickers.size();
        vector<unordered_map<char,int>> mp(n);
        for(int i=0;i<n;i++){
            for(auto it : stickers[i]) mp[i][it]++;
        }
        return solve(target,mp);
    }
};