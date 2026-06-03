class Solution {
public:
    bool check(int row,int col,vector<vector<int>>&board,int n){
        //check row 
        for(int i=0;i<col;i++){
            if(board[row][i]==1)return false;
        }
        //check left upper diagonal 
        {int i=row;
        int j=col;
        while(i>=0 && j>=0){
              if(board[i][j]==1)return false;
              i--;
              j--;
        }
        }
        int i=row;
        int j=col;
        while(i<n && j>=0){
              if(board[i][j]==1)return false;
              i++;
              j--;
        }
        return true;


    }
    void solve(int index,int n,vector<int>&temp,vector<vector<string>>&ans,vector<vector<int>>&board){

        if(index==n){
               vector<string> curr(n, string(n, '.'));

            for(int c = 0; c < n; c++) {
                curr[temp[c]][c] = 'Q';
            }

            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
           if( check(i,index,board,n)){
                temp.push_back(i);
            board[i][index]=1;
            solve(index+1,n,temp,ans,board);
            temp.pop_back();
             board[i][index]=0;

            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        //col by col
        vector<vector<string>>ans;
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<int>temp;
        solve(0,n,temp,ans,board);

    return ans;

        
        
    }
};
