class Solution {
    public:
        long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<pair<int,int>> vec;
            for(int i=0;i<nums1.size();i++) vec.push_back({nums2[i],nums1[i]});
            sort(vec.rbegin(),vec.rend());
            long long ans=0;
            long long sum=0;
            priority_queue<int> pq;
            for(int i=0;i<k-1;i++){
                sum+=vec[i].second;
                pq.push(-vec[i].second);
            }
            for(int i=k-1;i<nums1.size();i++){
                sum+=vec[i].second;
                pq.push(-vec[i].second);
                ans=max(ans,sum*vec[i].first);
                sum+=pq.top();
                pq.pop();
            }
            return ans;
        }
    };