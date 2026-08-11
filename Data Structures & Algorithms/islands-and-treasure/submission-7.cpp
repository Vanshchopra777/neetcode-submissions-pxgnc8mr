class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>dist(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            grid[row][col]=dis;

            for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==inf){        grid[newr][newc]=0;
                    q.push({{newr,newc},dis+1});
                }
            }


        }
        


        
    }
};
