class Solution {
    public:
        void solve(int ind,int target,vector<int> &candidates,vector<vector<int>> &ans,vector<int> &comb){
            if(target==0){
                ans.push_back(comb);
                return;
            }
            for(int i=ind;i<candidates.size();i++){
                if(i>ind && candidates[i]==candidates[i-1]) continue;
                if(candidates[i]>target) break;
                comb.push_back(candidates[i]);
                solve(i+1,target-candidates[i],candidates,ans,comb);
                comb.pop_back();
            }
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<vector<int>> ans;
            vector<int> comb;
            solve(0,target,candidates,ans,comb);
            return ans;
        }
    };