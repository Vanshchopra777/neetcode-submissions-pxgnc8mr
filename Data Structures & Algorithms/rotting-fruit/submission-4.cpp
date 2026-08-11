class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int fresh=0;

        int tmin=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)fresh++;
            }
        }
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;

            q.pop();

            tmin=max(tmin,time);

            for(int i=0;i<4;i++){
                int newr=r+delr[i];
                int newc=c+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){

                    grid[newr][newc]=2;
                    fresh--;
                    q.push({{newr,newc},time+1});

                }

            }

        }
        if(fresh)return -1;
        return tmin;


        
    }
};
