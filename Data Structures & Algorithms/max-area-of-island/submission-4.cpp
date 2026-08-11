class Solution {
public:
    int bfs(int r,int c,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
         int n=grid.size();
        int m=grid[0].size();
        q.push({r,c});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        int cnt=0;


        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
        
            cnt++;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
                        grid[newr][newc]=0;
                        q.push({newr,newc});

                }
            }


        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int area=0;
        int maxarea=0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                   area=bfs(i,j,grid);
                   maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;

        
    }
};
