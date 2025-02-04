class Solution {
public:
    int solve(string &s,int left,int right){
        int ans=0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            ans++;
            left--;
            right++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=solve(s,i,i);
            ans+=solve(s,i,i+1);
        }
        return ans;
    }
};