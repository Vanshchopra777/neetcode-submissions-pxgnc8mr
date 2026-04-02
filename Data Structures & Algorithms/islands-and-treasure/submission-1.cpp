class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    q.push({{i,j},0});
                    vis[i][j]=1;

                }

            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            grid[r][c]=dist;

            for(int i=0;i<4;i++){
                int newr=r+delrow[i];
                int newc=c+delcol[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==INT_MAX && !vis[newr][newc]){
                    q.push({{newr,newc},dist+1});
                    vis[newr][newc]=1;
                }
            }


        }
      


        
    }
};
