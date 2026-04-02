class Solution {
public:
    void dfs(int r,int c ,vector<vector<char>>& board,vector<vector<int>>&vis){
        int n=board.size();
        int m=board[0].size();
       
        vis[r][c]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newr=r+delrow[i];
            int newc=c+delcol[i];

            if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && board[newr][newc]=='O'){
                dfs(newr,newc,board,vis);
            }

        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 ||j==0||j==m-1){
                    if(board[i][j]=='O'){
                        dfs(i,j,board,vis);
                    }

                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O' ){
                    board[i][j]='X';

                }
            }
        }

        
    }
};
