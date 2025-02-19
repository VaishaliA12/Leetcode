class Solution {
    public:
        void dfs(vector<vector<int>> &grid,int i,int j,int &res){
            int n=grid.size();
            int m=grid[0].size();
            if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) return;
            grid[i][j]=0;
            res++;
            dfs(grid,i+1,j,res);
            dfs(grid,i-1,j,res);
            dfs(grid,i,j+1,res);
            dfs(grid,i,j-1,res);
        }
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        int res=0;
                        dfs(grid,i,j,res);
                        ans=max(ans,res);
                    }
                }
            }
            return ans;
        }
    };