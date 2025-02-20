class Solution {
    public:
        void dfs(vector<vector<int>> &heights,vector<vector<int>> &vis,int row,int col){
            int n=heights.size();
            int m=heights[0].size();
            vis[row][col]=1;
            int delr[]={-1,1,0,0};
            int delc[]={0,0,-1,1};
            for(int i=0;i<4;i++){
                int nr=row+delr[i];
                int nc=col+delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && heights[nr][nc]>=heights[row][col]) dfs(heights,vis,nr,nc);
            }
        }
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            int n=heights.size();
            int m=heights[0].size();
            vector<vector<int>> ans;
            vector<vector<int>> pac(n,vector<int> (m,0));
            vector<vector<int>> atl(n,vector<int> (m,0));
            for(int i=0;i<n;i++){
                dfs(heights,pac,i,0);
                dfs(heights,atl,i,m-1);
            }
            for(int j=0;j<m;j++){
                dfs(heights,pac,0,j);
                dfs(heights,atl,n-1,j);
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
                }
            }
            return ans;
        }
    };