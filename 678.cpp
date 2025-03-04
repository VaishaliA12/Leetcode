class Solution {
    public:
        bool checkValidString(string s) {
            int open=0,closed=0,star=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='(') open++;
                else if(s[i]==')') closed++;
                else star++;
                if(closed>open+star) return false;
            }
            open=0,closed=0,star=0;
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='(') open++;
                else if(s[i]==')') closed++;
                else star++;
                if(open>closed+star) return false;
            }
            return true;
        }
    };