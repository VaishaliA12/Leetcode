class Solution {
    public:
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            unordered_map<int,int> mpp;
            for(auto a : arr) mpp[a]++;
            vector<int> vec;
            int ans=0;
            for(auto it : mpp) vec.push_back(it.second);
            sort(vec.begin(),vec.end());
            for(int i=0;i<vec.size();i++){
                if(k>vec[i]){
                    k-=vec[i];
                    vec[i]=0;
                }
                else{
                    vec[i]-=k;
                    k=0;
                }
                if(vec[i]!=0) ans++;
            }
            return ans;
        }
    };