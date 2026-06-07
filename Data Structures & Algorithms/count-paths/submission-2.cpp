class Solution {
public:
    int solve(int m,int n, vector<vector<int>>&t){

        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){

                t[i][j]=t[i+1][j]+t[i][j+1];
            }
        }
        return t[0][0];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>t(m+1,vector<int>(n+1,1));
        return solve(m,n,t);
        
    }
};
