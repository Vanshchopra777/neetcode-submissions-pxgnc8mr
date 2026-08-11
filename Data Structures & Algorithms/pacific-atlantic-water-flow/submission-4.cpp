class Solution {
public:
    void bfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>&vis){

         int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
            int newr=row+delr[i];
            int newc=col+delc[i];

            if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]>=grid[row][col]){
                vis[newr][newc]=true;
                q.push({newr,newc});
            }
        }



        }

        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>pac_vis(n,vector<bool>(m,false));
        vector<vector<bool>>atl_vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 || j==0) {
                    pac_vis[i][j]=true;
                    bfs(i,j,heights,pac_vis);
                }

                 if(i==n-1 || j==m-1){
                    atl_vis[i][j]=true;
                    bfs(i,j,heights,atl_vis);

                }

            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac_vis[i][j] && atl_vis[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;



        

    }
};
