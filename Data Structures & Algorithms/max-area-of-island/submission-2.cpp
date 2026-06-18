class Solution {
public:

    int bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis,int n,int m,int & area){

        
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;

            q.pop();
            area++;

            //neighbours 
            for(int i=0;i<4;i++){
                int newr=r+delr[i];
                int newc=c+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
                    vis[newr][newc]=1;
                    
                    q.push({newr,newc});
                }
            }
        }
        return area;
            
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
                    
                   maxarea=max(maxarea, bfs(i,j,grid,vis,n,m,area));
                    

                }
            }
        }
        return maxarea;
    }
};
