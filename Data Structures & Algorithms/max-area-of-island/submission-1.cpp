class Solution {
public:
  
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&vis,int &area){
         int n=grid.size();
        int m=grid[0].size();
        
        vis[r][c]=1;
        area++;
     
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};




            for(int i=0;i<4;i++){
                int newr=r+delrow[i];
                int newc=c+delcol[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]==1){
                   
                   dfs(newr,newc,grid,vis,area);
                }
                
            }

        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        
int maxarea=0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int area=0;
               
                     dfs(i,j,grid,vis,area);
                    maxarea=max(area,maxarea);


                }

            }
        }
        return maxarea;
    }
};
