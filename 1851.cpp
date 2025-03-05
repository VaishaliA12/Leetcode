class Solution {
    public:
        vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
            sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
                return (a[1]-a[0])<(b[1]-b[0]);
            });
            set<pair<int,int>> s;
            for(int i=0;i<queries.size();i++) s.insert({queries[i],i});
            vector<int> ans(queries.size(),-1);
            for(auto &it: intervals){
                auto start=s.lower_bound({it[0],-1});
                auto end=start;
                for(end=start;end!=s.end() && end->first<=it[1];end++) ans[end->second]=it[1]-it[0]+1;
                s.erase(start,end);
            }
            return ans;
        }
    };