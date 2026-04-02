class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int tm=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 && !vis[i][j]){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};


        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;

            q.pop();
            tm=max(tm,time);

            for(int i=0;i<4;i++){
                int newr=r+delrow[i];
                int newc=c+delcol[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && vis[newr][newc]!=2){
                    q.push({{newr,newc},time+1});
                    vis[newr][newc]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1)return -1;
            }
        }
        return tm;

        
    }
};
