class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        int inf=2147483647;
        queue<pair<pair<int,int>,int>>q;

        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int distance=q.front().second;

            q.pop();
            grid[r][c]=distance;
            for(int i=0;i<4;i++){

                int newr=r+delr[i];
                int newc=c+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m &&
                !vis[newr][newc] && grid[newr][newc]==inf){
                    vis[newr][newc]=1;
                    q.push({{newr,newc},distance+1});
                }
            }

            

        }
        
        
    }
};
