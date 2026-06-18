class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int tmax=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==2 && !vis[i][j]){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }



            }
        }
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        while(!q.empty()){

            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;

            q.pop();
            tmax=max(tmax,time);

            for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m &&
                !vis[newr][newc] && grid[newr][newc]==1){
                    vis[newr][newc]=1;
                    q.push({{newr,newc},time+1});
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j])return -1;
            }
        }

        return tmax;
        
    }
};
