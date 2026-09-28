class Solution {
public:
    int bfs(int i,int j,int area,vector<vector<int>>& grid){
         int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            area++;
            

            for(int it=0;it<4;it++){
                int newr=r+delr[it];
                int newc=c+delc[it];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){         
                    grid[newr][newc]=0;
                    q.push({newr,newc});
                }
            }

        }
        return area;
        

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        
        int maxarea=0;
        int n=grid.size();
        int m=grid[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int area=0;

                if(grid[i][j]==1){
                    grid[i][j]=0;
                    maxarea=max(maxarea,bfs(i,j,area,grid));
                }
            }
        }
        return maxarea;
    }
};
