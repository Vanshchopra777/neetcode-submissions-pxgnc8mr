class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 ){
                    q.push({i,j});
                    // vis[i][j]=1;

                }

            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
          
            q.pop();
            

            for(int i=0;i<4;i++){
                int newr=r+delrow[i];
                int newc=c+delcol[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==INT_MAX ){
                    q.push({newr,newc});
                    grid[newr][newc]=grid[r][c]+1;
                }
            }


        }
      


        
    }
};
