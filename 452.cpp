class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& intervals) {
            int n=intervals.size();
            vector<int> vec;
            for(int i=0;i<n;i++) vec.push_back(i);
            sort(vec.begin(),vec.end(),[&](int a,int b){
                return intervals[a][1]<intervals[b][1];
            });
            int ans=0;
            int end=intervals[vec[0]][1];
            for(int i=1;i<n;i++){
                if(intervals[vec[i]][0]>end){
                    end=intervals[vec[i]][1];
                    ans++;
                }
            }
            return ans+1;
        }
    };