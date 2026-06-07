class Solution {
public:
    int solve(int i,int j,int m, int n,int &ways, vector<vector<int>>&t){

        if(i==m-1 && j==n-1){
           
            return 1;

        }
        if(i >= m || j >= n)
    return 0;
        
        if(t[i][j]!=-1)return t[i][j];

        t[i][j]=solve(i+1,j,m,n,ways,t)+solve(i,j+1,m,n,ways,t);

        return t[i][j];
    }
    int uniquePaths(int m, int n) {
        int ways=0;
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,ways,t);
        
        
    }
};
