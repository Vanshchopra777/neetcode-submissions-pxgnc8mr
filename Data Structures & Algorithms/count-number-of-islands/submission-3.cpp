class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid){
         int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;

        q.push({i,j});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        while(!q.empty()){

            auto[r,c]=q.front();
            q.pop();

            for(int it=0;it<4;it++){
                int newr=r+delr[it];
                int newc=c+delc[it];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]=='1'){
                    grid[newr][newc]='0';
                    q.push({newr,newc});

                }

            }

        }


    }
    int numIslands(vector<vector<char>>& grid) {


        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid);
                }

            }
        }
        return cnt;
        
    }
};
