class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        int INF=2147483647;
        queue<pair<int,int>>q;



        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int dis=0;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};


        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){

                auto[r,c]=q.front();
                q.pop();
                grid[r][c]=dis;

                for(int it=0;it<4;it++){
                    int newr=r+delr[it];
                    int newc=c+delc[it];

                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==INF){
                        q.push({newr,newc});
                        grid[newr][newc]=-1;
                    }
                }



            }

            dis++;



        }
        
    }
};
