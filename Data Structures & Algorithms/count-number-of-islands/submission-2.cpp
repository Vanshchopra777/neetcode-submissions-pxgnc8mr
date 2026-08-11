class Solution {
public:
    void bfs(int r,int c,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        q.push({r,c});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]=='1'){
                    vis[newr][newc]=true;
                    q.push({newr,newc});
                }
            }
        }



    }
    int numIslands(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(!vis[i][j] && grid[i][j]=='1'){
                    vis[i][j]=true;
                    bfs(i,j,grid,vis);
                    cnt++;

                }

                
                
            }
        }
        return cnt;
        
    }
};
