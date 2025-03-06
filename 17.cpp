class Solution {
    public:
        void solve(int ind,string &digits,vector<string> &mapping,vector<string> &ans,string comb){
            if(ind==digits.size()){
                ans.push_back(comb);
                return;
            }
            for(int i=0;i<mapping[digits[ind]-'0'].size();i++){
                comb.push_back(mapping[digits[ind]-'0'][i]);
                solve(ind+1,digits,mapping,ans,comb);
                comb.pop_back();
            }
        }
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            if(digits.size()==0) return {};
            vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            solve(0,digits,mapping,ans,"");
            return ans;
        }
    };