class Solution {
public:
    void bfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>&vis){
        vis[r][c]=1;
         int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};


        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int newr=row+delrow[i];
                int newc=col+delcol[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]=='1'){
                    vis[newr][newc]=1;
                    q.push({newr,newc});

                }
            }

            

        }
    }
    int numIslands(vector<vector<char>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

       
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};
