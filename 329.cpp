class Solution {
    public:
        int dfs(vector<vector<int>> &matrix,vector<vector<int>> &dp,int i,int j,vector<pair<int,int>> &dir){
            if(dp[i][j]!=-1) return dp[i][j];
            int ans=1;
            for(auto &d : dir){
                int x=i+d.first;
                int y=j+d.second;
                if(x>=0 && x<matrix.size() && y>=0 && y<matrix[0].size() && matrix[x][y]>matrix[i][j]) ans=max(ans,1+dfs(matrix,dp,x,y,dir));
            }
            dp[i][j]=ans;
            return ans;
        }
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            if(matrix.empty() || matrix[0].empty()) return 0;
            int m=matrix.size();
            int n=matrix[0].size();
            vector<vector<int>> dp(m,vector<int> (n,-1));
            vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
            int ans=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++) ans=max(ans,dfs(matrix,dp,i,j,dir));
            }
            return ans;
        }
    };