class Solution {
public:

    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis,int n,int m,int & area){

        
        vis[row][col]=1;
        area++;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};


            //neighbours 
            for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
                     dfs(newr,newc,grid,vis,n,m,area);
                    
                }
            }
        
            
        }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
    int maxarea=0;
     int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    area=0;
                    dfs(i,j,grid,vis,n,m,area);
                    
                   maxarea=max(maxarea,area);
                    

                }
            }
        }
        return maxarea;
    }
};
