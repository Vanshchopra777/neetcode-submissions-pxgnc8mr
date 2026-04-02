class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& nums,vector<vector<int>>& vis){
         int n=nums.size();
        int m=nums[0].size();

        vis[r][c]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newr=r+delrow[i];
            int newc=c+delcol[i];

            if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && nums[newr][newc]>=nums[r][c]){
                vis[newr][newc]=1;
                dfs(newr,newc,nums,vis);
            }

        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            dfs(i,0,nums,pacific);
            dfs(i,m-1,nums,atlantic);
            
        }
        for(int j=0;j<m;j++){
            dfs(0,j,nums,pacific);
            dfs(n-1,j,nums,atlantic);
        }
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

        
    }
};
