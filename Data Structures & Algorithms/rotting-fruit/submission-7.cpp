class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;

        queue<pair<int,int>>q;
        int rot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    
                }
                else if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;
        int time=0;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};


        while(!q.empty()){

            int size=q.size();

            for(int it=0;it<size;it++){

                auto [r,c]=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int newr=r+delr[i];
                    int newc=c+delc[i];

                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
                        grid[newr][newc]=2;
                        fresh--;
                        q.push({newr,newc});
                    }
                }


            }
            time++;
        }
        if(fresh>0)return -1;
        return time-1;
        
    }
};
