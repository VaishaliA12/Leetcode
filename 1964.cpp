class Solution {
    public:
        vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
            int n=obstacles.size();
            vector<int> ans(n);
            vector<int> lis;
            for(int i=0;i<n;i++){
                int it=upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
                if(it==lis.size()) lis.push_back(obstacles[i]);
                else lis[it]=obstacles[i];
                ans[i]=it+1;
            }
            return ans;
        }
    };