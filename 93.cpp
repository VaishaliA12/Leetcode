class Solution {
    public:
        bool valid(string s){
            if(s.size()>3 || s.size()==0) return false;
            if(s.size()>1 && s[0]=='0') return false;
            if(s.size() && stoi(s)>255) return false;
            return true;
        }
        void solve(vector<string> &ans,string comb,int ind,string s,int dots){
            if(dots==3){
                if(valid(s.substr(ind))) ans.push_back(comb+s.substr(ind));
                return;
            }
            int len=s.size();
            for(int i=ind;i<min(ind+3,len);i++){
                if(valid(s.substr(ind,i-ind+1))){
                    comb.push_back(s[i]);
                    comb.push_back('.');
                    solve(ans,comb,i+1,s,dots+1);
                    comb.pop_back();
                }
            }
        }
        vector<string> restoreIpAddresses(string s) {
            vector<string> ans;
            solve(ans,"",0,s,0);
            return ans;
        }
    };