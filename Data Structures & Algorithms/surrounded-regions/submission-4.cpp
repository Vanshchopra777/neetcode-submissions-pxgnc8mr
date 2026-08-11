class Solution {
public:
    void bfs(int r,int c,vector<vector<char>>& board,vector<vector<bool>>&vis){
 int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && board[newr][newc]=='O' && !vis[newr][newc]){
                    vis[newr][newc]=true;
                    q.push({newr,newc});
                    
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1)&& board[i][j]=='O') {
                    vis[i][j]=true;
                    bfs(i,j,board,vis);
                }
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }





        
    }
};
