class Solution {
    public:
        void dfs(vector<vector<char>> &board,int n,int m,int i,int j){
            if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='X' || board[i][j]=='V') return;
            board[i][j]='V';
            dfs(board,n,m,i-1,j);
            dfs(board,n,m,i+1,j);
            dfs(board,n,m,i,j-1);
            dfs(board,n,m,i,j+1);
        }
        void solve(vector<vector<char>>& board) {
            int n=board.size();
            int m=board[0].size();
            for(int j=0;j<m;j++){
                if(board[0][j]=='O') dfs(board,n,m,0,j);
                if(board[n-1][j]=='O') dfs(board,n,m,n-1,j);
            }
            for(int i=0;i<n;i++){
                if(board[i][0]=='O') dfs(board,n,m,i,0);
                if(board[i][m-1]=='O') dfs(board,n,m,i,m-1);
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]=='O') board[i][j]='X';
                    else if(board[i][j]=='V') board[i][j]='O';
                }
            }
        }
    };