class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int maxLen=0;
        for(int i=0;i<s.length();i++){
            int left=i,right=i;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                if(right-left+1>maxLen){
                    ans=s.substr(left,right-left+1);
                    maxLen=right-left+1;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                if(right-left+1>maxLen){
                    ans=s.substr(left,right-left+1);
                    maxLen=right-left+1;
                }
                left--;
                right++;
            }
        }
        return ans;
    }
};