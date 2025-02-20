class Solution {
    public:
        bool dfs(int i,int j,int mark,vector<vector<int>> &grid1,vector<vector<int>> &grid2){
            if(grid1[i][j]!=1) return 0;
            grid2[i][j]=mark;
            bool ans=1;
            int dir[5]={0,1,0,-1,0};
            for(int d=0;d<4;d++){
                int x=i+dir[d];
                int y=j+dir[d+1];
                if(x<0 || y<0 || x>=grid1.size() || y>=grid1[0].size() || grid2[x][y]!=1) continue;
                if(grid1[x][y]!=1) ans=0;
                if(!dfs(x,y,mark,grid1,grid2)) ans=0;
            }
            return ans;
        }
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            int n=grid1.size();
            int m=grid1[0].size();
            int ans=0,mark=2;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid2[i][j]==1) ans+=dfs(i,j,mark++,grid1,grid2);
                }
            }
            return ans;
        }
    };