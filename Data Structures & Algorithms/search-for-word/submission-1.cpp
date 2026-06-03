class Solution {
public:

    bool solve(int i,int j,int index,vector<vector<int>>&vis,vector<vector<char>>& board,string word){
        int n=board.size();
        int m=board[0].size();

        if(index==word.length()){
            return true;
        }
        
        vis[i][j]=1;

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        

        for(int k=0;k<4;k++){
            int newx=i+dx[k];
            int newy=j+dy[k];

            if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy] && board[newx][newy]==word[index] ){

                if(solve(newx,newy,index+1,vis,board,word)==true)return true;
            }

        }
        vis[i][j]=0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    
                  if(solve(i,j,1,vis,board,word))return true;
                }
            }

        }
        return false;
    }
};
